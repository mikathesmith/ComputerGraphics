#pragma once

#ifndef TRANSFORMS_H_INCLUDED
#define TRANSFORMS_H_INCLUDED

/** \file
 * \brief Functions to create and apply 2D transformation matrices.
 */

#include "Matrix.h"
#include "Vector.h"

#include <vector>

/**
 * \brief Translation by some amount.
 *
 * This creates a transformation that ofsets a point by some shift. 
 *
 * \param tx The horizontal (X) shift to apply.
 * \param ty The vertical (Y) shift to apply.
 * \result The corresponding 3x3 transformation matrix.
 */
Matrix translate(double tx, double ty);

/**
 * \brief Scaling by a constant factor.
 *
 * This creates a transformation that scales a point by a constant factor. 
 * The same factor is applied in both the vertical and horizontal directions.
 *
 * \param s The scale factor.
 * \result The corresponding 3x3 transformation matrix.
 */Matrix scale(double s);

/**
 * \brief Scaling by some factors along each of X and Y.
 *
 * This creates a transformation that scales by different amounts in the X- and Y-directions. 
 *
 * \param sx The horizontal (X) scale factor.
 * \param sy The vertical (Y) scale factor.
 * \result The corresponding 3x3 transformation matrix.
 */
Matrix scale(double sx, double sy);

/**
 * \brief Rotation about the origin by some angle
 *
 * This creates a rotation matrix from an angle, given in degrees. 
 * The resulting matrix is 3x3 due to the use of homogeneous co-ordinates.
 * To convert between degrees and radians use the utility functions deg2rad() and rad2deg().
 *
 * \param angle The angle in degrees.
 * \result The corresponding 3x3 transformation matrix.
 */
 
Matrix shearX(float m);

Matrix shearY(float n);

Matrix rotate(double angle);

/**
 * \brief Apply a transform to each element of a std::vector of points.
 *
 * Transforms are matrices, which can be applied directly to points represented as homogeneous 3-vectors.
 * This application is done through the multiplication operator, <code>new_v = T*old_v;</code>.
 * Since polygons are represented as a std::vector of Vectors, it is convenient to be able to apply a transform 
 * to a whole vector as a single operation.
 *
 * \param T The transform to apply. 
 * \param points A list of points to transform.
 * \result A list of transformed points.
 */
std::vector<Vector> operator*(const Matrix& T, const std::vector<Vector>& points);

#endif
