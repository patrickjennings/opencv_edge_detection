//
// Created by patrick on 4/22/18.
//

#include "ImageEdgeDetection.h"


ImageEdgeDetection::ImageEdgeDetection(Image srcImage, CannyConfiguration config) {
    this->srcImage = srcImage;
    this->config = config;
}

Image ImageEdgeDetection::detectEdges() {
    Image detected_edges;
    GrayscaleImage grayscaleImage(this->srcImage);

    detected_edges.blurImage(grayscaleImage, this->config.kernelSize);
    detected_edges.canny(detected_edges, this->config);

    this->dstImage.copyImage(this->srcImage, detected_edges);
    return this->dstImage;
}
