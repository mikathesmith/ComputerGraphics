#pragma once

#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED

/** \file
 * \brief Some utility functions.
 */

#include "Vector.h"

#include <cmath>

/**
 * \brief Convert from degrees to radians.
 *
 * While it is often convenient to think about angles in degrees, most mathematics works better
 * in radians. Since the C++ math libraries use radians, it is convenient to have functions to 
 * convert between them.
 * 
 * \param deg An angle expressed in degrees.
 * \result The equivalent angle in radians.
 */
inline double deg2rad(double deg) {
  return deg*M_PI/180;
}

/**
 * \brief Convert from radians to radians.
 *
 * While it is often convenient to think about angles in degrees, most mathematics works better
 * in radians. Since the C++ math libraries use radians, it is convenient to have functions to 
 * convert between them.
 * 
 * \param rad An angle expressed in radians.
 * \result The equivalent angle in radians.
 */
inline double rad2deg(double rad) {
  return rad*180/M_PI;
}

/**
 * \brief Create a homogeneous vector to represent a point.
 *
 * Points are conveniently represented as homogeneous co-ordinates.
 * This function takes the x- and y-values of a point and makes such a vector
 * 
 * \param x,y The location of the point.
 * \result A homegeneous representation of the point(x,y).
 */
inline Vector point2D(double x, double y) {
  Vector v(3);
  v(0) = x;
  v(1) = y;
  v(2) = 1;
  return v;
}

#endif
