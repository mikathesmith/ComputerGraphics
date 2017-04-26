cmake_minimum_required(VERSION 2.8)
project( mosaicing )

set (OpenCV_DIR /home/cshome/s/stefanie/Public/opencv-3.2.0/build)
find_package( OpenCV REQUIRED )

add_executable( mosaicing 
mosaicing.cpp
)

target_link_libraries( mosaicing ${OpenCV_LIBS} )