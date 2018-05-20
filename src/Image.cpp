//
// Created by patrick on 5/6/18.
//

#include "Image.h"

Image::Image(cv::Mat matrix) {
    this->matrix = matrix;
}

Image::Image() {}

const cv::Mat &Image::getMatrix() const {
    return matrix;
}

void Image::copyImage(Image input, Image mask) {
    input.matrix.copyTo(this->matrix, mask.matrix);
}

bool Image::isEmpty() {
    return this->matrix.empty();
}

void Image::blurImage(Image input, int kernelSize) {
    auto kernel = cv::Size(kernelSize, kernelSize);
    cv::blur(input.getMatrix(), this->matrix, kernel);
}

void Image::canny(Image input, CannyConfiguration config) {
    cv::Canny(input.getMatrix(), this->matrix, config.lowThreshold, config.getSecondThreshold(), config.kernelSize);
}

GrayscaleImage::GrayscaleImage(Image image) {
    cv::cvtColor(image.getMatrix(), this->matrix, cv::COLOR_BGR2GRAY);
}
