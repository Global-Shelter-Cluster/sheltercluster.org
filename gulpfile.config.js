module.exports = function() {
  var theme = './docroot/sites/all/themes/shelter';
  var config = {
    base: {
      app: './docroot/',
    },
    assets: {
      sass: theme + ['/assets/sass/**/*.scss'],
      sassOutput: theme + '/assets/css',
      paths: {
        sass: theme + ['/assets/sass'],
        css: theme + ['/assets/css'],
        images: theme + ['/assets/images']
      }
    }
  }

  return config;
}
