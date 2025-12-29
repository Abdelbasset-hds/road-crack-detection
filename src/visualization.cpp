#include "visualization.hpp"
#include <iostream>

Visualizer::Visualizer(){}
void Visualizer::display(const cv::Mat& image) const{
    if (image.empty()) {
        std::cerr << "Image vide !" << std::endl;
        return;
    }
    cv::imshow("display",image);
    cv::waitKey(0);
}

cv::Mat Visualizer::getGrid()const{
    return grid;
}

cv::Mat Visualizer::toBGR(const cv::Mat& image)const{
    if(image.channels()==1){
        cv::Mat color;
        cv::cvtColor(image,color,cv::COLOR_GRAY2BGR);
        return color;
    }
    return image.clone();
}


void Visualizer::displayGrid(const cv::Mat& original,
                            const cv::Mat& gradientImage,
                            const cv::Mat& filtred,
                            const cv::Mat& result){

                                CV_Assert(!original.empty()&&!gradientImage.empty()&&!filtred.empty()&&!result.empty());

                                cv::Mat o = toBGR(original);
                                cv::Mat g = toBGR(gradientImage);
                                cv::Mat f = toBGR(filtred);
                                cv::Mat r = toBGR(result);

                                cv::resize(o,o,cv::Size(400,300));
                                cv::resize(g,g,cv::Size(400,300));
                                cv::resize(f,f,cv::Size(400,300));
                                cv::resize(r,r,cv::Size(400,300));

                                cv::Mat top,bottom;
                                
                                cv::hconcat(o,g,top);
                                cv::hconcat(f,r,bottom);
                                cv::vconcat(top,bottom,grid);

                                cv::putText(grid,"original",{20,30},cv::FONT_HERSHEY_SIMPLEX,0.7,{204, 214, 255},2);
                                cv::putText(grid,"gradient",{420,30},cv::FONT_HERSHEY_SIMPLEX,0.7,{204, 214, 255},2);
                                cv::putText(grid,"filtred",{20,330},cv::FONT_HERSHEY_SIMPLEX,0.7,{204, 214, 255},2);
                                cv::putText(grid,"result",{420,330},cv::FONT_HERSHEY_SIMPLEX,0.7,{204, 214, 255},2);

                                cv::imshow("Crack Detection Pipeline",grid);
                                cv::waitKey(0);

                            }