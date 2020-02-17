(function ($) {
  Drupal.behaviors.clusterCharts = {
    initialized: false,
    init: function() {
      if (this.initialized)
        return;

      this.initialized = true;

      Chart.defaults.global.legend.position = 'bottom';
      Chart.defaults.global.elements.rectangle.borderWidth = 0;
      Chart.defaults.global.elements.arc.borderWidth = 0;
      Chart.defaults.global.elements.point.borderWidth = 0;
      Chart.defaults.global.elements.line.borderWidth = 0;
    },
    attach: function (context, settings) {
      this.init();

      if (typeof settings.cluster_chart === 'undefined')
        return;

      if (typeof settings.cluster_chart.type_pie !== 'undefined') {
        for (var html_id in settings.cluster_chart.type_pie) {
          $('#' + html_id).once('cluster_charts').each(function() {
            new Chart(this, {
              type: 'pie',
              data: {
                datasets: [settings.cluster_chart.type_pie[html_id].data],
                labels: settings.cluster_chart.type_pie[html_id].labels
              },
              options: settings.cluster_chart.type_pie[html_id].options
            })
          });
        }
      }

      if (typeof settings.cluster_chart.type_hbar !== 'undefined') {
        for (var html_id in settings.cluster_chart.type_hbar) {
          $('#' + html_id).once('cluster_charts').each(function() {
            const options = settings.cluster_chart.type_hbar[html_id].options;

            if (options.scales !== undefined && options.scales.xAxes !== undefined) {
              for (let i = 0; i < options.scales.xAxes.length; i++) {
                if (options.scales.xAxes[i].ticks !== undefined && options.scales.xAxes[i].ticks.callback !== undefined) {
                  switch (options.scales.xAxes[i].ticks.callback) {
                    case '[M]':
                      options.scales.xAxes[i].ticks.callback = function(value) {
                        return (value / 1000000).toFixed(value % 1000000 === 0 ? 0 : 1) + "M";
                      };
                      break;
                  }
                }
              }
            }

            new Chart(this, {
              type: 'horizontalBar',
              data: {
                datasets: settings.cluster_chart.type_hbar[html_id].data,
                labels: settings.cluster_chart.type_hbar[html_id].labels
              },
              options: options
            })
          });
        }
      }
    }
  }
})(jQuery);
