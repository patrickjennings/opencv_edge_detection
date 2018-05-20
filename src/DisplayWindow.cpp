//
// Created by patrick on 4/22/18.
//

#include "DisplayWindow.h"

const std::string &DisplayWindow::getWindow_name() const {
    return window_name;
}

void DisplayWindow::setWindow_name(const std::string &window_name) {
    DisplayWindow::window_name = window_name;
}

void GTKDisplayWindow::display_image(Image image) {
    cv::imshow(GTKDisplayWindow::window_name, image.getMatrix());
}

void GTKDisplayWindow::block_gui() {
    cv::waitKey(0);
}

void GTKDisplayWindow::setWindow_name(const std::string &window_name) {
    DisplayWindow::setWindow_name(window_name);
    cv::destroyAllWindows();
    cv::namedWindow(GTKDisplayWindow::window_name, cv::WINDOW_NORMAL);
}
