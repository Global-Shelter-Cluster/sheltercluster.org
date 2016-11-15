var gulp = require('gulp');
var tasks = require('gulp-task-listing');
var config = require('./gulpfile.config')();
var shell = require('gulp-shell');

var compass = require('gulp-compass');
var plumber = require('gulp-plumber');
var autoprefixer = require('gulp-autoprefixer');
var watch = require('gulp-watch');
var plugins = require('gulp-load-plugins')();

gulp.task('sass', ['sass-compile', 'sass-watch']);

gulp.task('sass-watch', function() {
  gulp.watch(config.assets.sass, ['sass-compile', 'clearstyles']);
});

gulp.task('sass-compile', function() {
  gulp.src(config.assets.sass)
    .pipe(plumber({
      errorHandler: function (error) {
        console.log(error.message);
        this.emit('end');
    }}))
    .pipe(compass({
      css: config.assets.paths.css,
      sass: config.assets.paths.sass,
      image: config.assets.paths.images,
      require: ['breakpoint', 'compass-normalize']
    }))
    .pipe(gulp.dest(config.assets.sassOutput));
});

gulp.task('default', function() {
  return tasks.withFilters(null, 'default')();
});

gulp.task('clearstyles', function() {
  return shell.task([
  'drush cc css-js'
  ]);
});