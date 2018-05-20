//
// Created by patrick on 5/6/18.
//

#include "CannyConfiguration.h"

CannyConfiguration::CannyConfiguration(int lowThreshold, int ratio, int kernelSize) {
    this->lowThreshold = lowThreshold;
    this->ratio = ratio;
    this->kernelSize = kernelSize;
}

int CannyConfiguration::getSecondThreshold() {
    return this->lowThreshold * this->ratio;
}
