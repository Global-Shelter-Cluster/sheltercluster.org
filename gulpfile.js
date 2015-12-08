var gulp = require('gulp');
var tasks = require('gulp-task-listing');
var config = require('./gulpfile.config')();

var compass = require('gulp-compass');
var plumber = require('gulp-plumber');
var autoprefixer = require('gulp-autoprefixer');
var watch = require('gulp-watch');

gulp.task('sass', ['sass-watch']);

gulp.task('sass-watch', function() {
  gulp.watch(config.assets.sass, ['sass-compile']);
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

