<?php
/**
 * @file
 * cluster_taxonomy.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function cluster_taxonomy_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Recovery',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '000017a9-c455-4f57-860d-00447f88d1d2',
    'vocabulary_machine_name' => 'response_phase',
  );
  $terms[] = array(
    'name' => 'Cluster Evaluation',
    'description' => 'An evaluative review of the work done by the cluster and the coordination teams',
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => '003e9b3b-2eab-4384-9221-1d17b7eaf418',
    'vocabulary_machine_name' => 'assessment_monitoring_evaluation',
  );
  $terms[] = array(
    'name' => 'Community Participation',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '014cd41f-a671-4ac6-8bdb-22418c7630bd',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Technical Training',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '01932662-8e57-4420-8a0f-3c021ceeac9e',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Risk Reduction',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '0266edff-6a91-4e3d-a42a-96df3605c9ad',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Human Rights',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 8,
    'uuid' => '05777ad3-81a1-47e6-ae27-cd1a23bd7c1b',
    'vocabulary_machine_name' => 'cross_cutting_issues',
  );
  $terms[] = array(
    'name' => 'Livestock',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '077fb354-c0d9-494f-8248-7a934e3e085c',
    'vocabulary_machine_name' => 'cross_cutting_issues',
  );
  $terms[] = array(
    'name' => 'Template',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '082341aa-3100-4d3e-8963-2dfb268aba81',
    'vocabulary_machine_name' => 'toolkit',
  );
  $terms[] = array(
    'name' => 'Tools and Fixing',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '0d579851-10c8-49bc-91ec-700b2bba1dea',
    'vocabulary_machine_name' => 'non_food_items',
  );
  $terms[] = array(
    'name' => 'Severe Local Storm',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '19812f2a-b597-487c-adcd-35a420e1d5f2',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Government and regulatory policy',
    'description' => 'Documentation on government policies, legislation, building codes, etc.',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '20bbc6c4-2b8f-4fb2-a008-d88545054ab3',
    'vocabulary_machine_name' => 'coordination_management',
  );
  $terms[] = array(
    'name' => 'HIV/AIDS',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 7,
    'uuid' => '2105392a-1960-4c54-b53d-67e4b7761570',
    'vocabulary_machine_name' => 'cross_cutting_issues',
  );
  $terms[] = array(
    'name' => 'No-build Zones',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2256cb0a-0126-4593-b760-318960e1833d',
    'vocabulary_machine_name' => 'issues',
  );
  $terms[] = array(
    'name' => 'Protracted Crisis',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '27c34da7-d28b-4651-9b0b-e41237c09f10',
    'vocabulary_machine_name' => 'disaster_onset',
  );
  $terms[] = array(
    'name' => 'Cash and Vouchers',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2a3d473e-5365-4bfc-afd1-6d5e8cded390',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Natural Disaster',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2b53aeeb-f325-48f8-a9f7-f2a4d3dd4cd2',
    'vocabulary_machine_name' => 'disaster_type',
  );
  $terms[] = array(
    'name' => 'Age',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 10,
    'uuid' => '2b7910a2-a7e7-475a-b0ea-9a4f3ef3e0ea',
    'vocabulary_machine_name' => 'cross_cutting_issues',
  );
  $terms[] = array(
    'name' => 'Winterization',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2c670010-8b2b-4c10-b5c1-da4931b7151d',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Early Recovery',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '3011fe7c-a1fd-4e09-8c0a-a012a23d58c2',
    'vocabulary_machine_name' => 'inter_cluster',
  );
  $terms[] = array(
    'name' => 'Earthquake',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3015c8d0-4652-486d-b932-39bb8ef8100a',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Masonry',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3132d7be-184f-4741-902d-26dac71134c0',
    'vocabulary_machine_name' => 'intervention_materials',
  );
  $terms[] = array(
    'name' => 'Example',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '32c7e9ea-196e-4c9a-8157-982d5970c906',
    'vocabulary_machine_name' => 'toolkit',
  );
  $terms[] = array(
    'name' => 'Host Families',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3340ec31-8e35-4913-8e17-6eb67fd22726',
    'vocabulary_machine_name' => 'settlement_type',
  );
  $terms[] = array(
    'name' => 'Disabilities',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '33a0a3be-6c3b-4afc-9aa0-719eb1888c47',
    'vocabulary_machine_name' => 'cross_cutting_issues',
  );
  $terms[] = array(
    'name' => 'Environment',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '341f24cf-d447-4890-8884-22e01cf0d126',
    'vocabulary_machine_name' => 'cross_cutting_issues',
  );
  $terms[] = array(
    'name' => 'Owner-occupier',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3a7ddfd1-3263-4f2c-963a-a3f2d3add412',
    'vocabulary_machine_name' => 'settlement_type',
  );
  $terms[] = array(
    'name' => 'Agency Assessment',
    'description' => 'A report from an independent assessment conducted by an agency in the cluster',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3b1e3d1a-3753-481e-93c5-443f897cd4dc',
    'vocabulary_machine_name' => 'assessment_monitoring_evaluation',
  );
  $terms[] = array(
    'name' => 'Shelter Programming',
    'description' => 'Guidance related to the modalities of shelter interventions such as cash, support to host famililies, distributions, etc.',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '3c0c5890-95b3-472b-9edb-ec224fc154f5',
    'vocabulary_machine_name' => 'technical_support_design',
  );
  $terms[] = array(
    'name' => 'Secondary Data Review',
    'description' => 'An assessment report resulting from the analysis of available secondary data',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '3d20e159-f152-4fad-8f22-a8fa70a29b4b',
    'vocabulary_machine_name' => 'assessment_monitoring_evaluation',
  );
  $terms[] = array(
    'name' => 'Technical Guidance',
    'description' => 'Documentation of suggested technical standards and program modalities',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3d32ad02-1b19-443e-a6bb-28484d1febca',
    'vocabulary_machine_name' => 'technical_support_design',
  );
  $terms[] = array(
    'name' => 'Repairs and Retrofitting',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3f022da5-4867-44da-ad50-2a4343457524',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Core Shelters',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3f1e57ba-3da5-4530-9acc-8b6e21ce579d',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Distribution',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3ffc180f-cc18-4dbf-bdc1-9bd70da2be8b',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Beneficiary Communications',
    'description' => 'Documents related to messaging that is specifically targetted towards affected populations',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '469926b7-f52d-4fc1-8484-cca05acff9ac',
    'vocabulary_machine_name' => 'information_management',
  );
  $terms[] = array(
    'name' => 'WASH',
    'description' => 'Water, Sanitation, and Hygiene Promotion',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '48e39189-ed6d-4527-94ff-219a99460b50',
    'vocabulary_machine_name' => 'inter_cluster',
  );
  $terms[] = array(
    'name' => 'Procurement and Logistics',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4a4a3f8e-95a0-466d-93c7-fbb8f70d314f',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Meeting Management',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '51cbff1f-021a-43a1-8429-e66c958b98e1',
    'vocabulary_machine_name' => 'coordination_management',
  );
  $terms[] = array(
    'name' => 'Technical Disaster',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '53214ef4-78a1-46f5-94e8-0a481e2c7c99',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Cold wave',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '53527189-c3d6-437f-8fda-87659d8adf56',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Displacement Tracking',
    'description' => 'Reporting on the movement and settlement conditions of displaced populations',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '55eaac52-8a6e-4b6f-a638-ad017ac423a5',
    'vocabulary_machine_name' => 'assessment_monitoring_evaluation',
  );
  $terms[] = array(
    'name' => 'Informal Settlements',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5667a7a0-2f99-4d3c-8c50-0a6787018fac',
    'vocabulary_machine_name' => 'settlement_type',
  );
  $terms[] = array(
    'name' => 'Organic Enclosures',
    'description' => 'woven grass, etc.',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '566e2413-d81d-433e-8ea4-b1ca731429e8',
    'vocabulary_machine_name' => 'intervention_materials',
  );
  $terms[] = array(
    'name' => 'Relocations',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '58bf77fd-355f-45c9-a44e-db012198fb85',
    'vocabulary_machine_name' => 'issues',
  );
  $terms[] = array(
    'name' => 'Market Assessment',
    'description' => 'A report from an assessment that examines the economic or market functions for a particular area',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => '5c1974d1-9a4e-4087-b378-98fa9fa41cea',
    'vocabulary_machine_name' => 'assessment_monitoring_evaluation',
  );
  $terms[] = array(
    'name' => 'Aggregates',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5ca47229-9652-42df-a41d-63520fec5349',
    'vocabulary_machine_name' => 'intervention_materials',
  );
  $terms[] = array(
    'name' => 'Slow Onset',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5ee652d0-0440-45d4-8cf8-8abaf79b58fb',
    'vocabulary_machine_name' => 'disaster_onset',
  );
  $terms[] = array(
    'name' => 'Reconstruction',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '5f7d4a03-5d53-477e-bea1-178ed4ae5d0e',
    'vocabulary_machine_name' => 'response_phase',
  );
  $terms[] = array(
    'name' => 'Tropical Cyclone',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '64653863-481d-4d77-a304-1180b439889f',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Multi-tenant Apartment',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6a6fefac-f15b-4bf5-8223-e968c8cdcd6f',
    'vocabulary_machine_name' => 'settlement_type',
  );
  $terms[] = array(
    'name' => 'Cooking and Eating Utensils',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6a7e7965-a162-4844-beae-3b5a6d955608',
    'vocabulary_machine_name' => 'non_food_items',
  );
  $terms[] = array(
    'name' => 'Health',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '6aef3fa1-7c39-446e-a757-dcbd3e5ab137',
    'vocabulary_machine_name' => 'inter_cluster',
  );
  $terms[] = array(
    'name' => 'Mines and other explosives',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6b730f77-36ba-4937-959d-45031f626cc4',
    'vocabulary_machine_name' => 'cross_cutting_issues',
  );
  $terms[] = array(
    'name' => 'Returns to Area of Origin',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '70472c91-e109-482d-a0f1-f91de81ad9d0',
    'vocabulary_machine_name' => 'issues',
  );
  $terms[] = array(
    'name' => 'Maps and GIS',
    'description' => 'Graphic mapping products',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '79772c36-ed3f-4cbf-99f1-c3361a854563',
    'vocabulary_machine_name' => 'information_management',
  );
  $terms[] = array(
    'name' => 'Logistics',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 7,
    'uuid' => '7b5eff48-bd93-470c-b68d-166700a94dc6',
    'vocabulary_machine_name' => 'inter_cluster',
  );
  $terms[] = array(
    'name' => 'Communications Messaging',
    'description' => 'Documentation that illustrate key messaging of advocacy messages targeted to stakeholders of the cluster and media',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '7eafa2d9-220d-44bc-a0ff-fe5b759065fe',
    'vocabulary_machine_name' => 'information_management',
  );
  $terms[] = array(
    'name' => 'Rentals and tenants',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '848d416c-f6d8-499e-b4ae-6009972d7472',
    'vocabulary_machine_name' => 'settlement_type',
  );
  $terms[] = array(
    'name' => 'Rubble Removal',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '88aa7163-7706-4995-8a90-a7f3ff0eb1c4',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Urban Planning',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8d113a79-37ad-4c1e-8a9e-4d1dbcc7a9db',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Guidance',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '91919635-562a-4735-ad43-7957fad923b7',
    'vocabulary_machine_name' => 'toolkit',
  );
  $terms[] = array(
    'name' => 'Protection',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '92a901cb-5e56-4bbb-956c-68bbcb72190b',
    'vocabulary_machine_name' => 'inter_cluster',
  );
  $terms[] = array(
    'name' => 'Stoves, Fuel, and Lighting',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '94029900-c28c-4ec7-ab42-f44b83ec71c0',
    'vocabulary_machine_name' => 'non_food_items',
  );
  $terms[] = array(
    'name' => 'Resource Mobilization',
    'description' => 'Appeals, Strategic response plan, CERF, CAP documents',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '97f29998-777b-4b0f-a7fb-41998310e5c2',
    'vocabulary_machine_name' => 'coordination_management',
  );
  $terms[] = array(
    'name' => 'Design Specifications',
    'description' => 'Detailed information on construction design, bills of quantity, costing, etc.',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => '9b0e5aa2-2232-4dc7-bd39-f466c336082c',
    'vocabulary_machine_name' => 'technical_support_design',
  );
  $terms[] = array(
    'name' => 'Land Slide',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '9ba71478-70c9-41c4-bd45-c018ad7b0b49',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Children',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '9fd846ed-7e25-4edd-bc9f-e9901b828ecb',
    'vocabulary_machine_name' => 'cross_cutting_issues',
  );
  $terms[] = array(
    'name' => 'Housing, Land, and Property Rights',
    'description' => 'Housing, Land, and Property Rights',
    'format' => 'filtered_html',
    'weight' => 9,
    'uuid' => 'a023e414-c655-431a-bd7c-70cf25ab084c',
    'vocabulary_machine_name' => 'cross_cutting_issues',
  );
  $terms[] = array(
    'name' => 'Emergency Shelter',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a20c44ff-3ef9-4b14-852a-cb3b09d86232',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Snow Avalanche',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a265176e-7e90-4175-8ade-c311ed5e48b3',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Extratropical Cyclone',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a29a67bb-ae0c-4d99-9d5e-b1aff021f1ce',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Tools and Shelter Kits',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a2b3aed6-4802-46df-ac17-ff4cad4705cd',
    'vocabulary_machine_name' => 'intervention_materials',
  );
  $terms[] = array(
    'name' => 'Timber',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a44fc26c-9a15-49d2-80f5-ecd544ea5b81',
    'vocabulary_machine_name' => 'intervention_materials',
  );
  $terms[] = array(
    'name' => 'CCCM',
    'description' => 'Camp Coordination and Camp Management',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => 'a54e745a-d963-4e42-83e2-f12af8aa057b',
    'vocabulary_machine_name' => 'inter_cluster',
  );
  $terms[] = array(
    'name' => 'Non-displaced',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a6a05846-68e2-4663-ba56-cc7d8016116c',
    'vocabulary_machine_name' => 'settlement_type',
  );
  $terms[] = array(
    'name' => 'Host Family Support',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a756083b-3669-4f15-acca-853cedac05a0',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Formal Camps',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a80f90df-0c7f-4e10-a22f-c1b901666f3e',
    'vocabulary_machine_name' => 'settlement_type',
  );
  $terms[] = array(
    'name' => 'Built Environment Professionals',
    'description' => 'engagement of engineers, architects, planners, etc',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a8c3fd93-28e4-4fb9-9aaa-734e271a0572',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Permanent Housing',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'aa31af83-42c8-40e5-81be-079bd2249160',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Emergency',
    'description' => 'Typically associated with life-saving activities',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'ae4af7fb-0364-43a7-8ae1-98708ab92610',
    'vocabulary_machine_name' => 'response_phase',
  );
  $terms[] = array(
    'name' => 'Demolition',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'af363042-bcae-49e9-878b-b040b983533b',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Multi-sectoral Assessment',
    'description' => 'A report for an assessment that involves several cluster such as a MIRA',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'af7249ca-f0eb-4a64-82ba-c25322e32d61',
    'vocabulary_machine_name' => 'assessment_monitoring_evaluation',
  );
  $terms[] = array(
    'name' => 'Flood',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b0119ed0-c464-45ee-880a-9a9d57a5a02f',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Heat Wave',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b0f3c4d4-d5ce-45ee-aaed-28da6a6f3436',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'General Household Support',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b1599173-047e-45e4-ab3a-cb8fe0b86516',
    'vocabulary_machine_name' => 'non_food_items',
  );
  $terms[] = array(
    'name' => 'Volcano',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b2d236a3-e27b-48c0-804d-664353216597',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Storm Surge',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b3babded-c097-40ed-8f73-82fd12f4f1d2',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Bamboo',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b47e81be-d6b1-4db7-9f0a-c48186cfbd72',
    'vocabulary_machine_name' => 'intervention_materials',
  );
  $terms[] = array(
    'name' => 'Bunkhouses',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b50b507f-a52d-4360-9f6a-5325b4123a9f',
    'vocabulary_machine_name' => 'issues',
  );
  $terms[] = array(
    'name' => 'Metal Sheeting',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b75b8716-c089-485c-8c0b-4d932d17920c',
    'vocabulary_machine_name' => 'intervention_materials',
  );
  $terms[] = array(
    'name' => 'Steel',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b975b04a-54f4-4ade-a093-b359bf042909',
    'vocabulary_machine_name' => 'intervention_materials',
  );
  $terms[] = array(
    'name' => 'Concrete',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b99e7560-a88b-4290-9622-9b18fedb977b',
    'vocabulary_machine_name' => 'intervention_materials',
  );
  $terms[] = array(
    'name' => 'Plastic Sheeting',
    'description' => 'Tarpaulines, rolls, sheets',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'be7b432b-84f8-4369-a657-972cfec22e0c',
    'vocabulary_machine_name' => 'intervention_materials',
  );
  $terms[] = array(
    'name' => 'Advisory Note',
    'description' => 'Documents to clarify cluster positions on various thematic topics',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => 'beca793a-cad5-4348-aba4-856d5010f133',
    'vocabulary_machine_name' => 'coordination_management',
  );
  $terms[] = array(
    'name' => 'Complex Crisis',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'c5493fd0-50aa-4393-a458-5f83d2deb506',
    'vocabulary_machine_name' => 'disaster_type',
  );
  $terms[] = array(
    'name' => 'Infographic',
    'description' => 'Visual image representing information used to communicate a set of messages related to the crisis',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => 'c8f1e2b4-dd4f-4b39-854d-cb2c11a6ad96',
    'vocabulary_machine_name' => 'information_management',
  );
  $terms[] = array(
    'name' => 'Sudden Onset',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c94d9bb5-335c-43e5-b41b-e3d074717a92',
    'vocabulary_machine_name' => 'disaster_onset',
  );
  $terms[] = array(
    'name' => 'Early Recovery',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'c94e35b1-95ea-4bc9-b109-c18a5727585c',
    'vocabulary_machine_name' => 'response_phase',
  );
  $terms[] = array(
    'name' => 'Construction Methods',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ca785653-f9bc-4323-b2d3-5c1ca0f1a091',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Mudslide',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cbc976f7-1c9c-471d-9532-0ab9410e84dc',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Collective Centres',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cc372269-a57f-4ae1-935e-13759558cd6d',
    'vocabulary_machine_name' => 'settlement_type',
  );
  $terms[] = array(
    'name' => 'Beneficiary Communications',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd0048fc8-b03f-4176-bc06-fe0fad5ae975',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Training materials',
    'description' => 'Products related to technical training for affected populations, workshops, etc.',
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => 'd11833bc-0e62-4595-917f-ab1c1505f87c',
    'vocabulary_machine_name' => 'technical_support_design',
  );
  $terms[] = array(
    'name' => 'Tsunami',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd2523ba5-8315-4559-aa08-061a251141d5',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Beneficiary Selection',
    'description' => 'Documentation of selection criteria for assistance prioritization of affected population',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'd5db5845-7b5c-499f-861c-b1d5ec710e61',
    'vocabulary_machine_name' => 'coordination_management',
  );
  $terms[] = array(
    'name' => 'Camp Management',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd846ccf4-3fae-4490-b32e-90e734ce609d',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Mental Health',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'd85163f8-0186-490a-9399-00dc651ce5fa',
    'vocabulary_machine_name' => 'cross_cutting_issues',
  );
  $terms[] = array(
    'name' => 'Settlement Planning',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd9e2592c-8c31-4ad3-a6ab-699c0356c2b8',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Strategy',
    'description' => 'Documentation of cluster defined approaches and strategic goals',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'da80b56e-1372-472e-808e-40443b2cb8bc',
    'vocabulary_machine_name' => 'coordination_management',
  );
  $terms[] = array(
    'name' => 'Tornadoes',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'db282b19-3974-4590-be81-46515bc9fd5b',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'IM reports and analysis',
    'description' => 'Reporting related to needs, gap, or 3W analyses usually as a table or dashboard document',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'dca64835-75f4-46a0-acf5-513570d0e8c1',
    'vocabulary_machine_name' => 'information_management',
  );
  $terms[] = array(
    'name' => 'IEC materials',
    'description' => 'Information, Education, and Communication materials that are usually distributed as part of interventions or to affected populations',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'dd01c5f1-6dfa-4cc8-8b0a-936ff0b48050',
    'vocabulary_machine_name' => 'technical_support_design',
  );
  $terms[] = array(
    'name' => 'Development',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => 'e0457000-0e06-441d-80db-6af7bcec5dd9',
    'vocabulary_machine_name' => 'response_phase',
  );
  $terms[] = array(
    'name' => 'Epidemic',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e109ec69-3c12-4d88-846d-4890f379a6c2',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Fire',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e2d3f186-bac8-4a62-af20-d1293fc5a5f1',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Clothing and Bedding',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e2f73244-8861-461d-bc50-9b774e1f0c48',
    'vocabulary_machine_name' => 'non_food_items',
  );
  $terms[] = array(
    'name' => 'Inter-Cluster Coordination',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e33af16f-d37c-4875-9c8f-6793508df352',
    'vocabulary_machine_name' => 'inter_cluster',
  );
  $terms[] = array(
    'name' => 'Drought',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e42b1631-061a-4639-93ce-9289f64c91cb',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Shelter Cluster Assessment',
    'description' => 'A report of an assessment conducted on behalf of shelter cluster partners',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'e77bdfa0-abed-40cb-ab56-6f6e043f2e8c',
    'vocabulary_machine_name' => 'assessment_monitoring_evaluation',
  );
  $terms[] = array(
    'name' => 'Dataset',
    'description' => 'Structured data made available for sharing',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'ea80df1b-3815-4059-b0ce-e6f57cdeef9d',
    'vocabulary_machine_name' => 'information_management',
  );
  $terms[] = array(
    'name' => 'Conflict',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ef3694d3-bdc8-4d97-9634-f64e8fd2c235',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Flash Flood',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f10d0ee4-29b3-462b-92fc-613ed5a125af',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Education',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => 'f1c7d9e0-e3bf-40ea-8d2c-cc6123ada4de',
    'vocabulary_machine_name' => 'inter_cluster',
  );
  $terms[] = array(
    'name' => 'Gender',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => 'f4794653-28d2-44fd-b41a-a4ed6a21769b',
    'vocabulary_machine_name' => 'cross_cutting_issues',
  );
  $terms[] = array(
    'name' => 'Man-made disaster',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => 'f684ff86-0cab-4044-8034-e46922bc972e',
    'vocabulary_machine_name' => 'disaster_type',
  );
  $terms[] = array(
    'name' => 'Tents',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f6937478-e997-49c9-ac8c-704772e813a3',
    'vocabulary_machine_name' => 'intervention_materials',
  );
  $terms[] = array(
    'name' => 'Insect Infestation',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f6974de6-c1bb-4447-8dd1-595b0b9c42fb',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Transitional Shelter',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f75613bc-427d-498d-8d0f-85c855bb3432',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'No legal status',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f769d279-22a8-4839-83c8-b027fdb98550',
    'vocabulary_machine_name' => 'settlement_type',
  );
  $terms[] = array(
    'name' => 'Camp Planning',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f8943746-b0a3-48a7-ba94-ffdfbe47ebf4',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Conflict',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'f97152e6-9e51-4fd0-a2e1-2eaa78467efa',
    'vocabulary_machine_name' => 'disaster_type',
  );
  $terms[] = array(
    'name' => 'Preparedness',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fb49a788-3b9b-4013-9159-a3df3753fb4b',
    'vocabulary_machine_name' => 'response_phase',
  );
  $terms[] = array(
    'name' => 'Owner Driven',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fc121321-481a-4e2b-8659-53e4cd915d66',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  return $terms;
}
