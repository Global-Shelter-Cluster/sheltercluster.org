<?php

function cluster_home_dashboard_export_excel() {
  $data = _cluster_home_dashboard_data();

  $xls = new PhpOffice\PhpSpreadsheet\Spreadsheet();
  $xls->setActiveSheetIndex(0);

  $clusters = $xls->getActiveSheet();
  $clusters->setTitle('CLUSTERS');
  $funding = $xls->createSheet();
  $funding->setTitle('DATA FUNDING & BENEFICIARIES');
  $wordcloud = $xls->createSheet();
  $wordcloud->setTitle('WORDCLOUD');
  $url = $xls->createSheet();
  $url->setTitle('URL');

  $clusters_cols = [
    'Countries' => 'A',
    'Region' => 'B',
    'Type of Crisis' => 'C',
    'Status' => 'D',
    'Cluster Mechanism' => 'E',
    'Lead' => 'F',
    'Co-Lead/Co-Chair' => 'G',
    'Focal Point ' => 'H',
    'HRP' => 'I',
    'Strategy' => 'J',
    'Household/People Factor' => 'K',
    'URL' => 'L',
  ];
  $funding_cols = [
    'Country' => 'A',
    'Count' => 'B',
    'Year' => 'C',
    'Uploaded' => 'D',
    'Quarter' => 'E',
    'Status' => 'F',
    'URL' => 'G',
    'Region' => 'H',
    'Type of crisis' => 'I',
    'Lead' => 'J',
    'Co-chair / co-lead' => 'K',
    'Funding received' => 'L',
    'Funding required' => 'M',
    'Funding Figure Consistent with FTS' => 'N',
    'Funding coverage' => 'O',
    'Funding Gap' => 'P',
    'Overall FTS (total requirement)' => 'Q',
    '% of FTS Allocated to Shelter' => 'R',
    '# of partners' => 'S',
    '# total number of people in need' => 'T',
    '# of people reached in total' => 'U',
    '# of people targeted in total' => 'V',
    'Coverage against target total' => 'W',
    '# of people reached with NFI' => 'X',
    '# of people targeted with NFI' => 'Y',
    'Coverage against target NFI' => 'Z',
    '# of people reached with shelter' => 'AA',
    '# of people targeted with shelter' => 'AB',
    'Coverage against target Shelter' => 'AC',
    'Data from' => 'AD',
    'Source/comments: Beneficiaries' => 'AE',
    'Source/comments: Funding' => 'AF',
  ];
  $wordcloud_cols = [
    'Country' => 'A',
    'Words' => 'B',
    'Description' => 'C',
  ];
  $url_cols = [
    'Country' => 'A',
    'URL' => 'B',
  ];

  foreach ($clusters_cols as $k => $v)
    $clusters->setCellValue($v.'1', $k);
  foreach ($funding_cols as $k => $v)
    $funding->setCellValue($v.'1', $k);
  foreach ($wordcloud_cols as $k => $v)
    $wordcloud->setCellValue($v.'1', $k);
  foreach ($url_cols as $k => $v)
    $url->setCellValue($v.'1', $k);

  $clusters_row = 2;
  $funding_row = 2;
  $wordcloud_row = 2;
  $url_row = 2;

  $write_row = function($data, &$sheet, &$cols, &$row) {
    foreach ($data as $k => $v) {
      $sheet->setCellValue($cols[$k].$row, $v);
    }
    $row++;
  };
  $write_row_clusters = function($data) use ($write_row, $clusters, $clusters_cols, &$clusters_row) {
    $write_row($data, $clusters, $clusters_cols, $clusters_row);
  };
  $write_row_funding = function($data) use ($write_row, $funding, $funding_cols, &$funding_row) {
    $write_row($data, $funding, $funding_cols, $funding_row);
  };
  $write_row_wordcloud = function($data) use ($write_row, $wordcloud, $wordcloud_cols, &$wordcloud_row) {
    $write_row($data, $wordcloud, $wordcloud_cols, $wordcloud_row);
  };
  $write_row_url = function($data) use ($write_row, $url, $url_cols, &$url_row) {
    $write_row($data, $url, $url_cols, $url_row);
  };

  foreach ($data['countries'] as $nid => $country_data) {
    // the first response found in the country (randomly selected)
    $response = current($country_data['responses']);

    // the latest factsheet for $response, if any
    $factsheet = array_key_exists($response['nid'], $data['factsheets'])
      ? $data['factsheets'][$response['nid']]
      : NULL;

    $country_url = url('node/' . $nid, ['absolute' => TRUE]);
    $country_top_region = $data['node_names'][$country_data['top_region']];
    $response_disaster_type = $data['term_names'][$response['disaster_type']];

    $write_row_clusters([
      'Countries' => $data['node_names'][$nid],
      'Region' => $country_top_region,
      'Type of Crisis' => $response_disaster_type,
      'Status' => '',
      'Cluster Mechanism' => '',
      'Lead' => '',
      'Co-Lead/Co-Chair' => '',
      'Focal Point ' => '',
      'HRP' => '',
      'Strategy' => '',
      'Household/People Factor' => $factsheet ? $factsheet['people_per_household'] : '',
      'URL' => $country_url,
    ]);

    $new_funding_row = [
      'Country' => $data['node_names'][$nid],
      'Count' => '',
      'Year' => $response['year'],
      'Uploaded' => '',
      'Quarter' => '',
      'Status' => '',
      'URL' => $country_url,
      'Region' => $country_top_region,
      'Type of crisis' => $response_disaster_type,
      'Lead' => '',
      'Co-chair / co-lead' => '',
      'Funding received' => '',
      'Funding required' => '',
      'Funding Figure Consistent with FTS' => '',
      'Funding coverage' => '',
      'Funding Gap' => '',
      'Overall FTS (total requirement)' => '',
      '% of FTS Allocated to Shelter' => '',
      '# of partners' => '',
      '# total number of people in need' => '',
      '# of people reached in total' => '',
      '# of people targeted in total' => '',
      'Coverage against target total' => '',
      '# of people reached with NFI' => '',
      '# of people targeted with NFI' => '',
      'Coverage against target NFI' => '',
      '# of people reached with shelter' => '',
      '# of people targeted with shelter' => '',
      'Coverage against target Shelter' => '',
      'Data from' => '',
      'Source/comments: Beneficiaries' => '',
      'Source/comments: Funding' => '',
    ];

    if ($factsheet) {
      if ($factsheet['funding']['required'] > 0 || $factsheet['funding']['funded'] > 0) {
        $new_funding_row['Funding received'] = $factsheet['funding']['funded'];
        $new_funding_row['Funding required'] = $factsheet['funding']['required'];
      }

      if ($factsheet['funding']['required'] > 0) {
        $new_funding_row['Funding coverage'] = $factsheet['funding']['funded'] / $factsheet['funding']['required'];

        if ($factsheet['funding']['funded'] < $factsheet['funding']['required'])
          $new_funding_row['Funding Gap'] = ($factsheet['funding']['required'] - $factsheet['funding']['funded']) / $factsheet['funding']['required'];
      }

      $new_funding_row['# of partners'] = $factsheet['partners'];

      $new_funding_row['# total number of people in need'] = $factsheet['people']['in need'];
      $new_funding_row['# of people reached in total'] = $factsheet['people']['reached'];
      $new_funding_row['# of people targeted in total'] = $factsheet['people']['targeted'];
      if ($factsheet['people']['targeted'] > 0)
      $new_funding_row['Coverage against target total'] = $factsheet['people']['reached'] / $factsheet['people']['targeted'];

      $new_funding_row['# of people reached with NFI'] = $factsheet['people_totals']['nfi']['reached'];
      $new_funding_row['# of people targeted with NFI'] = $factsheet['people_totals']['nfi']['targeted'];
      if ($factsheet['people_totals']['nfi']['targeted'] > 0)
        $new_funding_row['Coverage against target NFI'] = $factsheet['people_totals']['nfi']['reached'] / $factsheet['people_totals']['nfi']['targeted'];

      $new_funding_row['# of people reached with shelter'] = $factsheet['people_totals']['shelter']['reached'];
      $new_funding_row['# of people targeted with shelter'] = $factsheet['people_totals']['shelter']['targeted'];
      if ($factsheet['people_totals']['shelter']['targeted'] > 0)
        $new_funding_row['Coverage against target Shelter'] = $factsheet['people_totals']['shelter']['reached'] / $factsheet['people_totals']['shelter']['targeted'];

      $new_funding_row['Data from'] = $factsheet['date'];
      $new_funding_row['Source/comments: Funding'] = $factsheet['funding']['source'];
    }

    $write_row_funding($new_funding_row);

    $write_row_url([
      'Country' => $data['node_names'][$nid],
      'URL' => $country_url,
    ]);
  }

  $objWriter = PhpOffice\PhpSpreadsheet\IOFactory::createWriter($xls, 'Xlsx');
  $uri = drupal_tempnam('temporary://', 'home-dashboard-export') . '.xlsx';
  $objWriter->save(drupal_realpath($uri));
  file_transfer($uri, [
    'Content-Disposition' => 'attachment; filename="GSC Database.xlsx"',
    'Content-Type' => 'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet',
  ]);
}
