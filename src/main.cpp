#include <iostream>
#include <opencv2/opencv.hpp>

#include "CannyConfiguration.h"
#include "DisplayWindow.h"
#include "ImageEdgeDetection.h"


const std::string COMMAND_NAME = "OpenCV Test v1.0.0";
const std::string COMMAND_ARGS = "{@input | | input image}";
const std::string COMMAND_ARG_NAME = "@input";
const std::string WINDOW_NAME = "Canny Image Detection";


cv::CommandLineParser initializeParser(int argc, char **argv) {
    cv::CommandLineParser parser(argc, argv, COMMAND_ARGS);
    parser.about(COMMAND_NAME);
    return parser;
}

Image getSrcImageFromArguments(cv::CommandLineParser parser) {
    auto imagePath = parser.get<cv::String>(COMMAND_ARG_NAME);
    auto imageMatrix = cv::imread(imagePath, cv::IMREAD_COLOR);
    return Image(imageMatrix);
}

Image detectEdges(Image image, CannyConfiguration config) {
    auto image_detection = ImageEdgeDetection(image, config);
    return image_detection.detectEdges();
}

void displayImageAndBlock(Image image) {
    auto display_window = GTKDisplayWindow();
    display_window.setWindow_name(WINDOW_NAME);
    display_window.display_image(image);
    display_window.block_gui();
}


int main(int argc, char **argv) {
    CannyConfiguration config(100, 3, 3);

    auto parser = initializeParser(argc, argv);
    auto srcImage = getSrcImageFromArguments(parser);

    if(srcImage.isEmpty()) {
        std::cout << "Image failed to initialize" << std::endl;
        return -1;
    }

    auto dstImage = detectEdges(srcImage, config);
    displayImageAndBlock(dstImage);

    return 0;
}