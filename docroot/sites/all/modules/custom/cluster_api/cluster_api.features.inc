<?php
/**
 * @file
 * cluster_api.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cluster_api_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_default_oauth2_server().
 */
function cluster_api_default_oauth2_server() {
  $items = array();
  $items['shelter'] = entity_import('oauth2_server', '{
    "name" : "shelter",
    "label" : "shelter",
    "settings" : {
      "enforce_state" : true,
      "default_scope" : "response",
      "allow_implicit" : 1,
      "use_openid_connect" : 0,
      "use_crypto_tokens" : 0,
      "grant_types" : {
        "refresh_token" : "refresh_token",
        "password" : "password",
        "authorization_code" : 0,
        "client_credentials" : 0,
        "urn:ietf:params:oauth:grant-type:jwt-bearer" : 0
      },
      "always_issue_new_refresh_token" : 1,
      "unset_refresh_token_after_use" : 1,
      "access_lifetime" : "3600",
      "id_lifetime" : "3600",
      "refresh_token_lifetime" : "0",
      "require_exact_redirect_uri" : 0
    },
    "rdf_mapping" : [],
    "scopes" : [
      {
        "name" : "response",
        "description" : "Grants response related auth",
        "rdf_mapping" : []
      },
      {
        "name" : "signup",
        "description" : "Lets user create accounts",
        "rdf_mapping" : []
      }
    ]
  }');
  return $items;
}
