#pragma once

#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

/** \file
 * \brief Basic Display class for points, lines, and polygons
 */

#include "Vector.h"
#include "Colour.h"

#include <opencv2/opencv.hpp>

#include <string>
#include <vector>

/**
 * \brief A class to display points, lines, and polygons on a grid
 *
 * This class is basically a wrapper around some simple OpenCV calls to display an image.
 * A basic Display image is an X-Y grid, and you can draw points, lines, and polygons on it.
 *
 * Multiple displays can be made, and each has their own image and window. However, Display 
 * objects are <i>non-copyable</i>, which means you can't pass them by value to functions,
 * assign to or from them, and they have no copy constructor.
 */
class Display {
 public:

  /**
   * \brief Display constructor.
   *
   * Create a Display with a given size and scale. The width and height determine the size
   * of the window (in pixels) that is drawn on screen, while the scale determines how many
   * pixels correspond to one unit of distance. This lets you create Displays where the axes
   * may be only a few units long (say from -3 to 3), but which are still clearly visible.
   *
   * The thickness of the lines and the size of the points drawn also changes with scale.
   * An underlying grid of lines is drawn on construction.
   *
   * \param width The horizontal size of the Display window.
   * \param height The vertical size of the Display window.
   * \param scale The number of pixels per unit distance in the window.
   */
  Display(size_t width, size_t height, size_t scale);

  /**
   * \brief Display destructor.
   *
   * Release any resources held by a Display object.
   */
  ~Display();

  /**
   * \brief Reset the display.
   *
   * This method resets the display to its initial state, undoing any previous drawing commands.
   */
  void clear();

  /**
   * \brief Refresh the display.
   *
   * The drawing commands update the internal image, but it is not shown on screen until update() is called.
   * This allows several drawing operations (such as several lines to make a polygon) to appear as a single operation.
   */
  void update();

  /**
   * \brief Pause the program.
   *
   * Calling wait() causes the program to idle for a specified time. This gives time to view the results of 
   * update() operations. The idle period can be interupted by pressing any key.
   *
   * Times less than 0.01 seconds (including negative times) are treated as 0.01 seconds.
   *
   * \param seconds The time (in seconds) to wait.
   */
  void wait(double seconds = 1);

  /**
   * \brief Draw a point on the Display.
   *
   * This draws a single point as a circle on the Display. The location is provided as a 3-vector,
   * which is a 2D point in homogeneous form.
   *
   * \param point The location at which to draw the point.
   * \param colour The colour to draw the point.
   */
  void draw(const Vector& point, const Colour colour);

  /**
   * \brief Draw a line on the Display.
   *
   * This draws two points and a line between them on the Display. Points are provided as 3-vectors,
   * which are 2D points in homogeneous form.
   *
   * \param start The point where the line starts.
   * \param end The point where the line finishes.
   * \param colour The colour to draw the line.
   */
  void draw(const Vector& start, const Vector& end, const Colour& colour);

  /**
   * \brief Draw a polygon on the Display.
   *
   * This draws a series of points and closed sequence of lines between them. The points are given as 
   * a std::vector of homogeneous co-ordintes, and lines link each point to the next one in the list.
   * The last point is linked to the first one to close the curve.
   *
   * \param points The point where the line starts.
   * \param colour The colour to draw the polygon.
   */
  void draw(const std::vector<Vector>& points, const Colour& colour);


 private:

  /**
   * \brief [NO] Copy Constructor
   *
   * There is no Copy Constructor. You cannot copy Display objects.
   * 
   * The copy constructor for Display objects has no implementation and is not accessible
   * since it is private. This prevents the compiler from making a default copy constructor,
   * and raises an error if you try and call it.
   *
   * \param nil Not used
   */
  Display(const Display& nil);

  /**
   * \brief [NO] Assignment
   *
   * There is no Assignment operator. You cannot assign Display objects.
   * 
   * The assignment operator for Display objects has no implementation and is not accessible
   * since it is private. This prevents the compiler from making a default operator,
   * and raises an error if you try and call it.
   *
   * \param nil Not used
   * \return Not used
   */
  Display& operator=(const Display& nil);

  /**
   * \brief Convert a homogeneous 3-vector to an OpenCV point
   *
   * For the transform exercies points are represented as 
   *
   * \param point A point represented as a homogeneous 3-vector.
   * \result The corresponding (x,y) location for OpenCV.
   */
  cv::Point2d convert(const Vector& point);

  cv::Mat img_;                 //!< The image to show in the window.
  static size_t displayCount_;  //!< A counter for multiple Display objects.
  std::string windowName_;	    //!< The name of the window that this Display object uses.

  size_t scale_;				//!< The number of pixels per unit distance on the Display.
  size_t pointSize_;			//!< The radius, in pixels, of points drawn on the Display.
  size_t lineThickness_;		//!< The thickness, in pixels, of lines drawn on the Display.
};

#endif
