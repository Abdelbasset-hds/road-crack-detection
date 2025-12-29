#include "crack_detection.hpp"

const cv::Mat& CrackDetection::getOriginal() const{return crack;}
const cv::Mat& CrackDetection::getgradientImage() const{return gradientImage;}
const cv::Mat& CrackDetection::getFiltred() const{return filtred;}
const cv::Mat& CrackDetection::getResult() const{return result;}

cv::Mat CrackDetection::calculeGradient(const cv::Mat& input)const{
    cv::Mat gradX, gradY, gradient;
    cv::Sobel(input,gradX,CV_16S,1,0);
    cv::Sobel(input,gradY,CV_16S,0,1);

    cv::Mat absX , absY;
    cv::convertScaleAbs(gradX,absX);
    cv::convertScaleAbs(gradY,absY);

    cv::addWeighted(absX,0.5,absY,0.5,0,gradient);
    return gradient;
}

cv::Mat CrackDetection::segmentation(const cv::Mat& input)const{
    cv::Mat binary;
    threshold(input,binary,0,255,cv::THRESH_BINARY|cv::THRESH_OTSU);
    //threshold(input,binary,30,255,cv::THRESH_BINARY);
    return binary;
}

cv::Mat CrackDetection::removeNoise(const cv::Mat& input)const{
    cv::Mat openH , openV, cleaned;
    cv::morphologyEx(input,openH,cv::MORPH_OPEN,openHKernel);
    cv::morphologyEx(input,openV,cv::MORPH_OPEN,openVKernel);
    cleaned = openH | openV;
    return cleaned;
}; 
cv::Mat CrackDetection::fill(const cv::Mat& input)const{
    cv::Mat filled;
    cv::morphologyEx(input,filled,cv::MORPH_CLOSE,closeKernel);
    return filled;
};

cv::Mat CrackDetection::findAndDrawContours(const cv::Mat& input1,const cv::Mat& input2)const{
    CV_Assert(input1.type()==CV_8UC1);
    cv::Mat temp = input1.clone();
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(temp,contours,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);
    for(const auto& c:contours){
        double length = cv::arcLength(c,false);
        if(length > 150){
            cv::drawContours(input2,std::vector<std::vector<cv::Point>>{c},-1,cv::Scalar(0,255,0),1);
        }
    }
    return input2;
}

cv::Mat CrackDetection::dilate(const cv::Mat& input)const{
    cv::Mat dilated;
    cv::erode(input,dilated,dilateKernel);
    return dilated;

}

CrackDetection::CrackDetection(const cv::Mat& input): crack(input),
                                 closeKernel(cv::getStructuringElement(cv::MORPH_RECT,{3,3})),
                                 openHKernel(cv::getStructuringElement(cv::MORPH_RECT,{1,7})),
                                 openVKernel(cv::getStructuringElement(cv::MORPH_RECT,{7,1})),
                                 dilateKernel(cv::getStructuringElement(cv::MORPH_RECT,{3,3})){}

void CrackDetection::detect(const cv::Mat& input){

    cv::Mat temp = crack.clone();
    gradientImage = calculeGradient(input);
    cv::Mat binary = segmentation(gradientImage);
    cv::Mat filled = fill(binary);
    cv::Mat denoised = removeNoise(filled);
    
    filtred = dilate(denoised);
    cv::medianBlur(filtred, filtred, 7);
    result = findAndDrawContours(filtred,temp);
}

