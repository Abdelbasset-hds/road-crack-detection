#ifndef UTILS_HPP
#define UTILS_HPP

#include <opencv2/opencv.hpp>
#include <string>

cv::Mat loadImage(const std::string& path);
bool save_img(const cv::Mat& input,const std::string& name);

#endif