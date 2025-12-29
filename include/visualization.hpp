#ifndef VISUALIZATION_HPP
#define VISUALIZATION_HPP

#include <opencv2/opencv.hpp>

class Visualizer {
private:
    cv::Mat grid;
public:
    Visualizer();
    void display(const cv::Mat& image) const;
    void displayGrid(const cv::Mat& origianl,
                            const cv::Mat& gradiad,
                            const cv::Mat& filtred,
                            const cv::Mat& result);
    cv::Mat toBGR(const cv::Mat& image)const;
    cv::Mat getGrid()const;


};

#endif