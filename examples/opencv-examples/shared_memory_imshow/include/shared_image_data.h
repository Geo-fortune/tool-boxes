#pragma once
#include <vector>
#include <string>
#include <memory>

#include "opencv2/opencv.hpp"

#define IMAGE_WIDTH 2180
#define IMAGE_HEIGHT 1240
#define IMAGE_CHANNEL 3
struct shared_image_data{

    // std::string frame_id_;
    // std::string timestamp_;
    // int image_width_;
    // int image_height_;
    char  image_data_[IMAGE_WIDTH * IMAGE_HEIGHT * IMAGE_CHANNEL];
};
