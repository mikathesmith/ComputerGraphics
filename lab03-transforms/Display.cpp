#include "Display.h"

#include <sstream>
#include <algorithm>

size_t Display::displayCount_ = 0;

Display::Display(size_t width, size_t height, size_t scale) : img_(cv::Size(width,height), CV_8UC3), scale_(scale) {
  
	if (scale_ < 5) scale = 5;

  lineThickness_ = scale_/20;
  if (lineThickness_ == 0) lineThickness_ = 1;

  pointSize_ = lineThickness_*2;
	
  std::stringstream sstr;
  sstr << "Window " << ++displayCount_;
  windowName_ = sstr.str();
  
  cv::namedWindow(windowName_);

  clear();  
  update();
}

Display::~Display() {
  cv::destroyWindow(windowName_);
}

void Display::clear() {
  img_.setTo(cv::Scalar(0,0,0));

  int midX = img_.size().width/2;
  
  for (int x = midX+scale_; x < img_.size().width; x+= scale_) {
    cv::line(img_, cv::Point(x, 0), cv::Point(x, img_.size().height), cv::Scalar(64,64,64), lineThickness_);
    cv::line(img_, cv::Point(img_.size().width-x, 0), cv::Point(img_.size().width-x, img_.size().height), cv::Scalar(64,64,64), lineThickness_);
  }

  int midY = img_.size().height/2;
  for (int y = midY+scale_; y < img_.size().height; y+= scale_) {
    cv::line(img_, cv::Point(0, y), cv::Point(img_.size().width, y), cv::Scalar(64,64,64), lineThickness_);
    cv::line(img_, cv::Point(0, img_.size().height-y), cv::Point(img_.size().width, img_.size().height-y), cv::Scalar(64,64,64), lineThickness_);
  }

  cv::line(img_, cv::Point(midX,0), cv::Point(midX,img_.size().height), cv::Scalar(128,128,128), lineThickness_);
  cv::line(img_, cv::Point(0,midY), cv::Point(img_.size().width, midY), cv::Scalar(128,128,128), lineThickness_);
}
  
void Display::update() {
  cv::imshow(windowName_, img_);
  cv::waitKey(10);
}

void Display::wait(double seconds) {
  if (seconds <= 0.01) seconds = 0.01;
  cv::waitKey(seconds*1000);
}



void Display::draw(const Vector& point, const Colour colour) {
  cv::Point2d p = convert(point);
  cv::circle(img_, p, pointSize_, cv::Scalar(colour.blue, colour.green, colour.red), -1);
}

void Display::draw(const Vector& start, const Vector& end, const Colour& colour) {
  draw(start, colour);
  draw(end, colour);
  cv::Point2d p1 = convert(start);
  cv::Point2d p2 = convert(end);
  cv::line(img_, p1, p2, cv::Scalar(colour.blue, colour.green, colour.red), lineThickness_);
}

void Display::draw(const std::vector<Vector>& points, const Colour& colour) {
  for (size_t i = 0; i < points.size(); ++i) {
    if (i == 0) {
      draw(points[0], points[points.size()-1], colour);
    } else {
      draw(points[i-1], points[i], colour);
    }
  }
}

cv::Point2d Display::convert(const Vector& point) {
  assert(point.numRows() == 3);
  return cv::Point2d(scale_*point(0)/point(2)+img_.size().width/2, img_.size().height/2-scale_*point(1)/point(2));
}
