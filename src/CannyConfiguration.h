//
// Created by patrick on 5/6/18.
//

#ifndef OPENCV_EDGE_DETECTOR_CANNYCONFIGURATION_H
#define OPENCV_EDGE_DETECTOR_CANNYCONFIGURATION_H


class CannyConfiguration {
public:
    int lowThreshold = 0;
    int ratio = 0;
    int kernelSize = 0;

    CannyConfiguration(int lowThreshold, int ratio, int kernelSize);

    int getSecondThreshold();
};


#endif //OPENCV_EDGE_DETECTOR_CANNYCONFIGURATION_H
