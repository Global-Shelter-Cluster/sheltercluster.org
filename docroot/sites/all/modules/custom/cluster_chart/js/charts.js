(function ($) {
  Drupal.behaviors.clusterCharts = {
    attach: function (context, settings) {
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
            new Chart(this, {
              type: 'horizontalBar',
              data: {
                datasets: settings.cluster_chart.type_hbar[html_id].data,
                labels: settings.cluster_chart.type_hbar[html_id].labels
              },
              options: settings.cluster_chart.type_hbar[html_id].options
            })
          });
        }
      }
    }
  }
})(jQuery);
