#ifndef CRACK_DETECTION_HPP
#define CRACK_DETECTION_HPP
#include <opencv2/opencv.hpp>

class CrackDetection {

private:
    cv::Mat openVKernel;
    cv::Mat openHKernel;
    cv::Mat closeKernel;
    cv::Mat dilateKernel;
    cv::Mat crack;
    cv::Mat gradientImage;
    cv::Mat filtred;
    cv::Mat result;
    cv::Mat segmentation(const cv::Mat& input)const;
    cv::Mat removeNoise(const cv::Mat& input)const; 
    cv::Mat fill(const cv::Mat& input)const;
    cv::Mat calculeGradient(const cv::Mat& input)const;
    cv::Mat findAndDrawContours(const cv::Mat& input,const cv::Mat& input2)const;
    cv::Mat dilate(const cv::Mat& input)const;
    
public:
    CrackDetection(const cv::Mat& input);
    void detect(const cv::Mat& input);
    const cv::Mat& getOriginal() const;
    const cv::Mat&  getgradientImage() const;
    const cv::Mat&  getFiltred() const;
    const cv::Mat&  getResult() const;

};

#endif