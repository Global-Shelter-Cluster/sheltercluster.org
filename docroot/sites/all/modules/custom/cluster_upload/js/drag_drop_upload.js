(function ($) {
  Drupal.behaviors.dragDropUplaod = {
    attach: function (context, settings) {
      if (!settings.cluster_nav.group_nid) return;
      $("body").on("dragover", false);
      $("body").on("dragend", false);
      $("body").on("drop", function(event) {
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
        success: this.redirect
      });
    }
  },

  "redirect": function(response, status) {
    window.location.href = '/node/' + response.document_nid + '/edit';
  },

  "notify": function(type, message) {
    jQuery("#operation-title").append("<div class='cluster-upload-message'>" + message + "</div>");
  }
};
