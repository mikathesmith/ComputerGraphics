#include <opencv2/opencv.hpp>
#include "opencv2/xfeatures2d.hpp"

#include <ctime>
#include <iostream>
#include <string>
#include <vector>

// Difference between times in milliseconds
double clockDiff(clock_t t1, clock_t t2) {
  return (t2-t1)/(CLOCKS_PER_SEC/1000.0);
}

int main (int argc, char *argv[]) {
 //control program's input and output. 
  const bool displayResults = false; //should illustrate its progress
  if(argc<2){
    return 0;
  }
  std::string folder = argv[1];
  const size_t numImages = 2; //program tries to read images from folder/image[x].png where
  							  //x ranges from 1 to numImages. 
  const bool filterMatches = true; //whether or not ambiguous matches will be used when trying 
  								   //to determine homography. 
  
  if (displayResults) {
    cv::namedWindow("Image");
    cv::namedWindow("Features1");
    cv::namedWindow("Features2");
    cv::namedWindow("Matches");
    cv::namedWindow("Mosaic");
  }

  char fname[100];
  clock_t start, end;

  // Read in the images
  std::vector<cv::Mat> images(numImages);
  for (size_t i = 0; i < numImages; ++i) {
    sprintf(fname, "%s/img%d.png", folder.c_str(), int(i+1));
    std::cout << "Reading " << fname << std::endl;
    images[i] = cv::imread(fname);
  }

  // An image to hold the mosaic
  cv::Mat mosaic(cv::Size(1250,300), CV_8UC3);
  
  // Transform matrix, starts out as the identity
  cv::Mat T(cv::Mat::eye(cv::Size(3,3),CV_64F));
  // Offset slightly to give a bit of room for the mosaic
  T.at<double>(0,2) = 10;
  T.at<double>(1,2) = 25;
  
  // A SIFT feature detector
  cv::Ptr<cv::Feature2D> sift = cv::xfeatures2d::SIFT::create();
  
  // A feature matching strategy
  cv::FlannBasedMatcher matcher; //Fast library for approximate nearest neighbours 
  //cv::BFMatcher matcher;
     
  // Warp the first image to the mosaic
  cv::warpPerspective(images[0], mosaic, T, mosaic.size(), 
		      cv::INTER_CUBIC, 0, CV_RGB(255,255,255));

  if (displayResults) {
    cv::imshow("Mosaic", mosaic);
    cv::waitKey();
  }

  cv::Mat grey(images[0].size(), CV_8UC3);

  for (size_t i = 1; i < numImages; ++i) {
    std::cout << "Matching image[" << i << "] to image[" << i-1 << "]" << std::endl; 

    // Detect and describe SIFT features in images[i]
    cv::cvtColor(images[i], grey, CV_BGR2GRAY);
    std::vector<cv::KeyPoint> keypoints1;
    cv::Mat descriptors1;
    start = clock();
    sift->detect(grey, keypoints1);
    sift->compute(grey, keypoints1, descriptors1);
    end = clock();
    std::cout << "- Found " << keypoints1.size() << " features in " << 
      clockDiff(start, end) << "ms" << std::endl;

    // Detect and describe SIFT features in images[i-1]
    cv::cvtColor(images[i-1], grey, CV_BGR2GRAY);
    std::vector<cv::KeyPoint> keypoints2;
    cv::Mat descriptors2;
    start = clock();
    sift->detect(grey, keypoints2);
    sift->compute(grey, keypoints2, descriptors2);
    end = clock();
    std::cout << "- Found " << keypoints2.size() << " features in " << 
      clockDiff(start, end) << "ms" << std::endl;

    // Display the features
    if (displayResults) {
      cv::Mat features1(images[i].clone());
      cv::drawKeypoints(features1, keypoints1, features1, CV_RGB(0,255,0), 
			cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
      cv::imshow("Features1", features1);
      cv::Mat features2(images[i-1].clone());
      cv::drawKeypoints(features2, keypoints2, features2, CV_RGB(0,255,0), 
			cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
      cv::imshow("Features2", features2);
    }

    // Match the features
    std::vector<std::vector<cv::DMatch> > rawMatches;
    start = clock();
    matcher.knnMatch(descriptors1, descriptors2, rawMatches, 2);
    end = clock();
    std::cout << "- Found " << rawMatches.size() << " matches in " << 
      clockDiff(start, end) << "ms" << std::endl;

    std::vector<cv::DMatch> goodMatches;
    std::vector<cv::Point2d> points1;
    std::vector<cv::Point2d> points2;

    for (auto match: rawMatches) {
      if (!filterMatches || match[0].distance < 0.8*match[1].distance) {
	goodMatches.push_back(match[0]);
	points1.push_back(keypoints1[match[0].queryIdx].pt);
	points2.push_back(keypoints2[match[0].trainIdx].pt);
      }
    }
    std::cout << "- Kept " << goodMatches.size() << " out of " << 
      rawMatches.size() << " matches" << std::endl;

    // Display the matches
    if (displayResults) {
      cv::Mat matchImage;
      cv::drawMatches(images[i], keypoints1, images[i-1], keypoints2, 
		      goodMatches, matchImage, CV_RGB(0,255,0), CV_RGB(255,0,0));
      cv::imshow("Matches", matchImage);
    }

    // Compute the Homography and update the transform
    start = clock();
    cv::Mat H = cv::findHomography(points1, points2, CV_RANSAC, 2.0); //uses RANSAC when determining the
    //homography, 2.0 is max distance in pixels between aligned points for them to be considered inliers
    //RANSAC can be cahnged to 0 (least squares fit from all matches) and CV_LMEDS (least median of squares error)
    
    
    T = T*H;
    end = clock();
    std::cout << "Found homography in " << 
      clockDiff(start,end) << "ms" << std::endl;

    // Warp the image onto the mosaic
    cv::warpPerspective(images[i], mosaic, T, mosaic.size(), 
			cv::INTER_CUBIC, cv::BORDER_TRANSPARENT);

    if (displayResults) {
      cv::imshow("Mosaic", mosaic);
      cv::waitKey();
    }
  }

  return 0;

}
