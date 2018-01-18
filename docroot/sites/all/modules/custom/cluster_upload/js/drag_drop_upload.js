(function ($) {
  Drupal.behaviors.dragDropUplaod = {
    attach: function (context, settings) {
      if (!settings.cluster_nav.group_nid) return;
      $("body").on("dragover",  (event) => {
        $("body").addClass('document-upload-ondrag');
        return false;
      });
      $("body").on("dragend", (event) => {
        $("body").removeClass('document-upload-ondrag');
        return false;
      });
      $("body").on("dragleave", (event) => {
        $("body").removeClass('document-upload-ondrag');
        return false;
      });
      $("body").on("drop", (event) => {
        $("body").removeClass('document-upload-ondrag');
        cluster_upload.drop(event, settings.cluster_nav.group_nid);
      });
    }
  };
}(jQuery));

const cluster_upload = {
  "drop": function(event, gid) {
    event.preventDefault();
    // Only upload the first file.
    var file_data = event.originalEvent.dataTransfer.files[0];
    var form_data = new FormData();
    form_data.append('file', file_data);
    this.notify("status", "Your document is getting created...");
    if (form_data) {
      jQuery.ajax({
        url: "/upload-document/" + gid,
        type: "POST",
        data: form_data,
        processData: false,
        contentType: false,
        success: this.success,
        error: this.error,
      });
    }
    else {
      console.log('Failed to create document.');
    }
  },

  "success": function(response, status) {
    if (response.status == "error") {
      console.log(response.status);
      this.error();
      window.location.reload();
    }
    else if (response.status === "ok") {
      window.location.href = '/node/' + response.document_nid + '/edit';
    }
  },

  "notify": function(type, message) {
    jQuery("#operation-title").append("<div id='cluter-upload-status' class='cluster-upload-message throbber'>" + message + "</div>");
  },
  "error": function(jqXHR, textStatus, errorThrown) {
    jQuery("#cluter-upload-status").replaceWith("<div id='cluter-upload-status' class='cluster-upload-message'>Error when creating the document</div>");
  },
};
