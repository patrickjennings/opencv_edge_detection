//
// Created by patrick on 5/6/18.
//

#ifndef OPENCV_EDGE_DETECTOR_IMAGE_H
#define OPENCV_EDGE_DETECTOR_IMAGE_H

#include <opencv2/opencv.hpp>

#include "CannyConfiguration.h"


class Image {
public:
    Image();
    Image(cv::Mat matrix);

    const cv::Mat &getMatrix() const;

    void copyImage(Image input, Image mask);
    void blurImage(Image input, int kernelSize);
    void canny(Image input, CannyConfiguration config);

    bool isEmpty();

protected:
    cv::Mat matrix;
};


class GrayscaleImage: public Image {
public:
    GrayscaleImage(Image image);
};


#endif //OPENCV_EDGE_DETECTOR_IMAGE_H
