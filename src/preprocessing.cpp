#include "preprocessing.hpp"


Preprocessor::Preprocessor(){}
cv::Mat Preprocessor::toGray(const cv::Mat& input){
    cv::Mat gray;
    cv::cvtColor(input,gray,cv::COLOR_BGR2GRAY);
    return gray;
};
cv::Mat Preprocessor::blure(const cv::Mat& input){
    cv::Mat denoised;
    cv::GaussianBlur(input,denoised,cv::Size(13,13),1);
    return denoised;
};
cv::Mat Preprocessor::equilize(const cv::Mat& input){
    cv::Mat contrasted;
    cv::equalizeHist(input,contrasted);
    return contrasted;
};


cv::Mat Preprocessor::enhaceContrast(const cv::Mat& input) const {
    cv::Mat gray;
    if(input.channels() == 3)
        cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    else
        gray = input;

    // Augmenter juste le contraste global
    cv::Mat enhanced
    ;
    double alpha = 1.4; // contraste
    int beta = 45;       // luminosité
    gray.convertTo(enhanced, -1, alpha, beta);

    return enhanced;
}


cv::Mat Preprocessor::preprocessing(const cv::Mat& input){
    cv::Mat gray = toGray(input);
    cv::Mat enhaced = enhaceContrast(gray);
    return blure(enhaced);
};
