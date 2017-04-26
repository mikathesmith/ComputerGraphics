cmake_minimum_required(VERSION 2.8)
project( transform2D )

set (OpenCV_DIR /home/cshome/s/stefanie/Public/opencv-3.2.0/build)
find_package( OpenCV REQUIRED )

add_executable( transform2D
transformMain.cpp
transforms.cpp
transforms.h
utility.h
Vector.h
Vector.cpp
Colour.h
Display.h
Display.cpp
Matrix.h
Matrix.cpp )

add_executable( mytransform2D
mytransformMain.cpp
transforms.cpp
transforms.h
utility.h
Vector.h
Vector.cpp
Colour.h
Display.h
Display.cpp
Matrix.h
Matrix.cpp )

target_link_libraries( transform2D ${OpenCV_LIBS} )
target_link_libraries( mytransform2D ${OpenCV_LIBS} )
