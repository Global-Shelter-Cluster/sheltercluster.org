Webform GPS Location
====================

# Introduction

This is a webform component that allows users to indicate their location on a map. The component has a fixed crosshair
in the center of the map. Users can pan the map to indicate their location. Users can also click a button to use
device location (when supported).

The module is a work in progress. The core functionality is supported but niceties such as map display on configuration,
submissions or analysis are not yet supported.

The configuration form also needs settings validation.

# Requirements

- Webform 7.x-4.x (https://www.drupal.org/project/webform)
- Leaflet 7.x-1.x (https://www.drupal.org/project/leaflet) with all its dependencies installed.

Optional: Leaflet More Maps 7.x-1.x (https://www.drupal.org/project/leaflet_more_maps)

# Installation

Place the module in the appropriate directory (eg sites/all/modules/contrib) and enable it.

# Use

After installation, the gpslocation webform component will become available to be placed on a webform.

TODO: Discuss settings.

# Credits

Created by LimoenGroen (https://limoengroen.nl) for the Municipality of Leidschendam-Voorburg (https://lv.nl).

http://alienryderflex.com/polygon/ for the polygon validation algorithm.
