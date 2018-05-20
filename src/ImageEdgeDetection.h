//
// Created by patrick on 4/22/18.
//

#ifndef OPENCV_EDGE_DETECTOR_IMAGEEDGEDETECTION_H
#define OPENCV_EDGE_DETECTOR_IMAGEEDGEDETECTION_H

#include "Image.h"
#include "CannyConfiguration.h"


class ImageEdgeDetection {
private:
    Image srcImage;
    Image dstImage;

protected:
    CannyConfiguration config = CannyConfiguration(0, 0, 0);

public:
    ImageEdgeDetection();
    ImageEdgeDetection(Image srcImage, CannyConfiguration config);

    Image detectEdges();
};


#endif //OPENCV_EDGE_DETECTOR_IMAGEEDGEDETECTION_H
