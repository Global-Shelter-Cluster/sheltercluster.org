<?php

namespace Drupal\cluster_api\Assessment;

use Drupal\cluster_api\Assessment\AssessmentSubmissionInterface;

class AssessmentSubmissionWebform implements AssessmentSubmissionInterface {

  private $user;
  private $node;
  private $webform;
  private $submission;

  /**
   * @return array;
   * @throws \Exception
   */
  public function saveSubmission($user, $form_id, $submission) {
    $this->user = $user;

    $this->node = node_load($form_id);

    // If the user is follower of at least one group in which this form is posted, allow.
    $user_is_follower = FALSE;
    if (!isset($this->node->og_group_ref)) {
      return ['success' => FALSE, 'message' => t('Form not in a group')];
    }
    foreach ($this->node->og_group_ref[LANGUAGE_NONE] as $group_id) {
      $roles = og_get_user_roles('node', $group_id['target_id'], $this->user->uid);
      if (in_array('follower', $roles)) {
        $user_is_follower = TRUE;
        break;
      }
    }

    // 2019-04-11: We're removing this requirement (as per SA-70)
//    if (!$user_is_follower) {
//      return ['success' => FALSE, 'message' => t('User is not group follower')];
//    }

    if (!$this->node) {
      return ['success' => FALSE, 'message' => t('Bad form id')];
    }
    if (empty($this->node->webform)) {
      return ['success' => FALSE, 'message' => t('Not a form')];
    }
    $this->webform = $this->node->webform;
    return $this->mapSubmissionToComponents($submission);
  }

  private function mapSubmissionToComponents($submission) {
    $result = ['success' => TRUE, 'message' => t('Form submission successful')];
    $all_form_keys = [];
    $webform_data = [];

    // For each webform component, get the submitted value.
    foreach ($this->webform['components'] as $cid => $component) {
      $form_key = $component['form_key'];
      $all_form_keys[] = $form_key;

      // Test if required values are present.
      if ($component['required'] && empty($submission[$form_key])) {
        return ['success' => FALSE, 'message' => t('@field is required', ['@field' => $component['name']])];
      }

      switch ($component['type']) {
        case 'file':
          if (!$submission[$form_key])
            break;

          // This reads from a base64 string (e.g. "data:image/jpeg;base64,...")
          $data = file_get_contents($submission[$form_key]);

          if (!$data)
            break;

          // Figure out the extension from the mime type
          $ext = _cluster_api_mime2ext(mime_content_type($submission[$form_key]));
          $ext = $ext ? '.' . $ext : '';

          // Make sure the directory exists
          $dir = 'public://webform/' . date('Y-m');
          if (file_exists($dir) && !is_dir($dir))
            throw new \Exception("Not a directory: ".$dir);
          if (!file_exists($dir))
            drupal_mkdir($dir, NULL, TRUE);

          // Now save as a file
          $path = $dir . '/' . $form_key . $ext;
          $file = file_save_data($data, $path, FILE_EXISTS_RENAME);
          if ($file === FALSE)
            break;

          // Webform submission stores the file id
          $webform_data[$cid] = [$file->fid];

          break;

        // Submissions are nested too deeply in select.
        case 'select':
          $webform_data[$cid] = [$submission[$form_key]][0];
          break;

        case 'geolocation':
          $webform_data[$cid] = $submission[$form_key];
          break;

        default:
          $webform_data[$cid] = [$submission[$form_key]];
      }
    }

    // Test if submission includes values that are not supported by the webform.
    $unsuported_keys = array_diff(array_keys($submission), $all_form_keys);
    if ($unsuported_keys) {
      return ['success' => FALSE, 'message' => t('Form submission contains inputs that are not defined in the form')];
    }

    module_load_include('inc', 'webform', 'includes/webform.submissions');
//    $webform_data = _webform_client_form_submit_flatten($this->node, $webform_data);
    $webform_data = webform_submission_data($this->node, $webform_data);

    $webform_submission = (object)array(
      'nid' => $this->node->nid,
      'uid' => $this->user->uid,
      'submitted' => REQUEST_TIME,
      'remote_addr' => ip_address(),
      'is_draft' => FALSE,
      'data' => $webform_data,
    );


    webform_submission_insert($this->node, $webform_submission);
    return $result;
  }

}

/**
 * Adapted from: https://stackoverflow.com/a/53662733
 */
function _cluster_api_mime2ext($mime) {
  $mime_map = [
    'video/3gpp2' => '3g2',
    'video/3gp' => '3gp',
    'video/3gpp' => '3gp',
    'application/x-compressed' => '7zip',
    'audio/x-acc' => 'aac',
    'audio/ac3' => 'ac3',
    'application/postscript' => 'ai',
    'audio/x-aiff' => 'aif',
    'audio/aiff' => 'aif',
    'audio/x-au' => 'au',
    'video/x-msvideo' => 'avi',
    'video/msvideo' => 'avi',
    'video/avi' => 'avi',
    'application/x-troff-msvideo' => 'avi',
    'application/macbinary' => 'bin',
    'application/mac-binary' => 'bin',
    'application/x-binary' => 'bin',
    'application/x-macbinary' => 'bin',
    'image/bmp' => 'bmp',
    'image/x-bmp' => 'bmp',
    'image/x-bitmap' => 'bmp',
    'image/x-xbitmap' => 'bmp',
    'image/x-win-bitmap' => 'bmp',
    'image/x-windows-bmp' => 'bmp',
    'image/ms-bmp' => 'bmp',
    'image/x-ms-bmp' => 'bmp',
    'application/bmp' => 'bmp',
    'application/x-bmp' => 'bmp',
    'application/x-win-bitmap' => 'bmp',
    'application/cdr' => 'cdr',
    'application/coreldraw' => 'cdr',
    'application/x-cdr' => 'cdr',
    'application/x-coreldraw' => 'cdr',
    'image/cdr' => 'cdr',
    'image/x-cdr' => 'cdr',
    'zz-application/zz-winassoc-cdr' => 'cdr',
    'application/mac-compactpro' => 'cpt',
    'application/pkix-crl' => 'crl',
    'application/pkcs-crl' => 'crl',
    'application/x-x509-ca-cert' => 'crt',
    'application/pkix-cert' => 'crt',
    'text/css' => 'css',
    'text/x-comma-separated-values' => 'csv',
    'text/comma-separated-values' => 'csv',
    'application/vnd.msexcel' => 'csv',
    'application/x-director' => 'dcr',
    'application/vnd.openxmlformats-officedocument.wordprocessingml.document' => 'docx',
    'application/x-dvi' => 'dvi',
    'message/rfc822' => 'eml',
    'application/x-msdownload' => 'exe',
    'video/x-f4v' => 'f4v',
    'audio/x-flac' => 'flac',
    'video/x-flv' => 'flv',
    'image/gif' => 'gif',
    'application/gpg-keys' => 'gpg',
    'application/x-gtar' => 'gtar',
    'application/x-gzip' => 'gzip',
    'application/mac-binhex40' => 'hqx',
    'application/mac-binhex' => 'hqx',
    'application/x-binhex40' => 'hqx',
    'application/x-mac-binhex40' => 'hqx',
    'text/html' => 'html',
    'image/x-icon' => 'ico',
    'image/x-ico' => 'ico',
    'image/vnd.microsoft.icon' => 'ico',
    'text/calendar' => 'ics',
    'application/java-archive' => 'jar',
    'application/x-java-application' => 'jar',
    'application/x-jar' => 'jar',
    'image/jp2' => 'jp2',
    'video/mj2' => 'jp2',
    'image/jpx' => 'jp2',
    'image/jpm' => 'jp2',
    'image/jpeg' => 'jpg',
    'image/jpg' => 'jpg',
    'image/pjpeg' => 'jpg',
    'application/x-javascript' => 'js',
    'application/json' => 'json',
    'text/json' => 'json',
    'application/vnd.google-earth.kml+xml' => 'kml',
    'application/vnd.google-earth.kmz' => 'kmz',
    'text/x-log' => 'log',
    'audio/x-m4a' => 'm4a',
    'application/vnd.mpegurl' => 'm4u',
    'audio/midi' => 'mid',
    'application/vnd.mif' => 'mif',
    'video/quicktime' => 'mov',
    'video/x-sgi-movie' => 'movie',
    'audio/mpeg' => 'mp3',
    'audio/mpg' => 'mp3',
    'audio/mpeg3' => 'mp3',
    'audio/mp3' => 'mp3',
    'video/mp4' => 'mp4',
    'video/mpeg' => 'mpeg',
    'application/oda' => 'oda',
    'audio/ogg' => 'ogg',
    'video/ogg' => 'ogg',
    'application/ogg' => 'ogg',
    'application/x-pkcs10' => 'p10',
    'application/pkcs10' => 'p10',
    'application/x-pkcs12' => 'p12',
    'application/x-pkcs7-signature' => 'p7a',
    'application/pkcs7-mime' => 'p7c',
    'application/x-pkcs7-mime' => 'p7c',
    'application/x-pkcs7-certreqresp' => 'p7r',
    'application/pkcs7-signature' => 'p7s',
    'application/pdf' => 'pdf',
    'application/octet-stream' => 'pdf',
    'application/x-x509-user-cert' => 'pem',
    'application/x-pem-file' => 'pem',
    'application/pgp' => 'pgp',
    'application/x-httpd-php' => 'php',
    'application/php' => 'php',
    'application/x-php' => 'php',
    'text/php' => 'php',
    'text/x-php' => 'php',
    'application/x-httpd-php-source' => 'php',
    'image/png' => 'png',
    'image/x-png' => 'png',
    'application/powerpoint' => 'ppt',
    'application/vnd.ms-powerpoint' => 'ppt',
    'application/vnd.ms-office' => 'ppt',
    'application/msword' => 'ppt',
    'application/vnd.openxmlformats-officedocument.presentationml.presentation' => 'pptx',
    'application/x-photoshop' => 'psd',
    'image/vnd.adobe.photoshop' => 'psd',
    'audio/x-realaudio' => 'ra',
    'audio/x-pn-realaudio' => 'ram',
    'application/x-rar' => 'rar',
    'application/rar' => 'rar',
    'application/x-rar-compressed' => 'rar',
    'audio/x-pn-realaudio-plugin' => 'rpm',
    'application/x-pkcs7' => 'rsa',
    'text/rtf' => 'rtf',
    'text/richtext' => 'rtx',
    'video/vnd.rn-realvideo' => 'rv',
    'application/x-stuffit' => 'sit',
    'application/smil' => 'smil',
    'text/srt' => 'srt',
    'image/svg+xml' => 'svg',
    'application/x-shockwave-flash' => 'swf',
    'application/x-tar' => 'tar',
    'application/x-gzip-compressed' => 'tgz',
    'image/tiff' => 'tiff',
    'text/plain' => 'txt',
    'text/x-vcard' => 'vcf',
    'application/videolan' => 'vlc',
    'text/vtt' => 'vtt',
    'audio/x-wav' => 'wav',
    'audio/wave' => 'wav',
    'audio/wav' => 'wav',
    'application/wbxml' => 'wbxml',
    'video/webm' => 'webm',
    'audio/x-ms-wma' => 'wma',
    'application/wmlc' => 'wmlc',
    'video/x-ms-wmv' => 'wmv',
    'video/x-ms-asf' => 'wmv',
    'application/xhtml+xml' => 'xhtml',
    'application/excel' => 'xl',
    'application/msexcel' => 'xls',
    'application/x-msexcel' => 'xls',
    'application/x-ms-excel' => 'xls',
    'application/x-excel' => 'xls',
    'application/x-dos_ms_excel' => 'xls',
    'application/xls' => 'xls',
    'application/x-xls' => 'xls',
    'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet' => 'xlsx',
    'application/vnd.ms-excel' => 'xlsx',
    'application/xml' => 'xml',
    'text/xml' => 'xml',
    'text/xsl' => 'xsl',
    'application/xspf+xml' => 'xspf',
    'application/x-compress' => 'z',
    'application/x-zip' => 'zip',
    'application/zip' => 'zip',
    'application/x-zip-compressed' => 'zip',
    'application/s-compressed' => 'zip',
    'multipart/x-zip' => 'zip',
    'text/x-scriptzsh' => 'zsh',
  ];

  return isset($mime_map[$mime]) ? $mime_map[$mime] : false;
}
