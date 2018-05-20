//
// Created by patrick on 4/22/18.
//

#ifndef OPENCV_EDGE_DETECTOR_DISPLAYWINDOW_H
#define OPENCV_EDGE_DETECTOR_DISPLAYWINDOW_H

#include "Image.h"


class DisplayWindow {
public:
    virtual void display_image(Image image) = 0;
    virtual void block_gui() = 0;

    const std::string &getWindow_name() const;
    virtual void setWindow_name(const std::string &window_name);

protected:
    std::string window_name;
};

class GTKDisplayWindow: public DisplayWindow {
public:
    void display_image(Image image);
    void block_gui();

    void setWindow_name(const std::string &window_name);
};


#endif //OPENCV_EDGE_DETECTOR_DISPLAYWINDOW_H
