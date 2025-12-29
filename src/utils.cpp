#include "utils.hpp"
#include <stdexcept>
#include <iostream>
#include <opencv2/imgcodecs.hpp>

cv::Mat loadImage(const std::string& path){
    cv::Mat img = cv::imread(path);
    if(img.empty()){
        throw std::runtime_error("Can't load img "+path);
    }
    return img;
}

bool save_img(const cv::Mat& input,const std::string& path){
    if(input.empty()){
        std::cerr<<"Error! Empty image\n";
        return 0;
    }

    bool success = cv::imwrite(path,input);
    if(!success){
        std::cerr<<"Error! image not saved\n";
        return 0;
    }
    return 1;

}