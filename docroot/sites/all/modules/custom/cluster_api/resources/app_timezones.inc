<?php

function _cluster_api_get_timezones() {
  return array_keys(system_time_zones());
}
