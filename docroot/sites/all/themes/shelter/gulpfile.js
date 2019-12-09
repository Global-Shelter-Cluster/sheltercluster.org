var gulp = require('gulp');
var compass = require('gulp-compass');
var plumber = require('gulp-plumber');
var minifyCSS = require('gulp-minify-css');
var watch = require('gulp-watch');

gulp.task('watch',['compass'], function() {
  gulp.watch('./assets/sass/**/*.scss', ['compass']);
});

gulp.task('default', ['compass'], function() {
});

gulp.task('compass', function() {
  gulp.src('./assets/sass/*.scss')
    .pipe(plumber({
      errorHandler: function (error) {
        console.log(error.message);
        this.emit('end');
    }}))
    .pipe(compass({
      css: './assets/css',
      sass: './assets/sass',
      image: './assets/images',
      require: ['breakpoint', 'compass-normalize']
    }))
    .on('error', function(err) {
      // Error Handling
    })
    //.pipe(minifyCSS())
    .pipe(gulp.dest('./assets/css'));
});
