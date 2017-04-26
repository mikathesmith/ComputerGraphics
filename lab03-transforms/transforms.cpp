#include "transforms.h"
#include "utility.h"

#include <cmath>

Matrix translate(double tx, double ty) {
  Matrix T(Matrix::identity(3,3));

  T(0,2) = tx;
  T(1,2) = ty;

  return T;
}

Matrix scale(double s) {
  Matrix S(Matrix::identity(3,3));

  S(0,0) = S(1,1) = s;

  return S;
}

Matrix scale(double sx, double sy) {
  Matrix S(Matrix::identity(3,3));

  S(0,0) = sx;
  S(1,1) = sy;

  return S;
}

//expects an angle in degrees, but C++ trig functions
//expect angles in radians. 
Matrix rotate(double angle) {
  Matrix R(Matrix::identity(3,3));
  double radians = deg2rad(angle);
  
  R(0,0) = cos(radians);
  R(0,1) = -sin(radians);
  R(0,2) = 0;
  R(1,0) = sin(radians);
  R(1,1) = cos(radians);
  R(1,2) = 0;  
  R(2,0) = 0;
  R(2,1) = 0;
  R(2,2) = 1; 
  
  //int degrees = rad2deg(radians);
  return R;
}

Matrix shearX(float m){
  Matrix S(Matrix::identity(3,3));
  S(0,0) = 1;
  S(0,1) = m;
  S(0,2) = 0; 
  S(1,0) = 0;
  S(1,1) = 1;
  S(1,2) = 0;
  S(2,0) =0;
  S(2,1) = 0;
  S(2,2) = 1; 
  return S; 
}

Matrix shearY(float n){
  Matrix S(Matrix::identity(3,3));
  S(0,0) = 1;
  S(0,1) = 0;
  S(0,2) = 0; 
  S(1,0) = n;
  S(1,1) = 1;
  S(1,2) = 0;
  S(2,0) =0;
  S(2,1) = 0;
  S(2,2) = 1; 
  
  return S; 
}

std::vector<Vector> operator*(const Matrix& T, const std::vector<Vector>& points) {
  std::vector<Vector> result;
  for (size_t i = 0; i < points.size(); ++i) {
    result.push_back(T*points[i]);
  }
  return result;
}


