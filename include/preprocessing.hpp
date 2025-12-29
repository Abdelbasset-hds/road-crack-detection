#ifndef PREPROCESSING_HPP
#define PREPROCESSING_HPP

#include <opencv2/opencv.hpp>

class Preprocessor {

    private :
        cv::Mat toGray(const cv::Mat& input);
        cv::Mat blure(const cv::Mat& input);
        cv::Mat equilize(const cv::Mat& input);
        cv::Mat enhaceContrast(const cv::Mat& input)const;

    public :
        Preprocessor();
        cv::Mat preprocessing(const cv::Mat& input);
};


#endif 