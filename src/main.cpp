#include <iostream>
#include "preprocessing.hpp"
#include "visualization.hpp"
#include "utils.hpp"
#include "crack_detection.hpp"

int main(int argc,char** argv){

    if(argc < 3){
        std::cerr<<"usage"<<argv[0]<<"<input_image><output_image>\n";
        return 1;
        }
    std::string input_dir = argv[1];
    std::string output_dir = argv[2];


    Preprocessor preprocessor;
    Visualizer Visualizer;
    
    cv::Mat img = loadImage(input_dir);
    CrackDetection detector(img);
    cv::Mat preprocessed = preprocessor.preprocessing(img);
    detector.detect(preprocessed);
     Visualizer.displayGrid(detector.getOriginal(),
                             detector.getgradientImage(),
                             detector.getFiltred(),
                             detector.getResult());

    if(!save_img(Visualizer.getGrid(),output_dir)){
        std::cerr<<"Failed to save image!\n";
        return 1;
    }
    return 0;
}