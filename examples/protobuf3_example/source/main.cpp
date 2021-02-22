//
// created by caishuai on 11-09-2018
//

#include <iostream>
#include <fstream>
#include <string>

#include "protos/calibration.pb.h"
#include "include/config_manager.h"

void printConfig(calibration::Config config);

int main(int argc, char **argv)
{
    // Load protobuf config file
    calibration::Config config;
    std::string config_file = "conf/calibration.config";

    if (!ReadConfig(config_file, config))
    {
        std::cout << "Error: can't load configure file " << config_file << std::endl;
        return -1;
    }

    printConfig(config);

    return 0;
}

void printConfig(calibration::Config config)
{
    calibration::RosbagParams proto_bag_params = config.rosbag_params();
    calibration::LidarCalibParams proto_lidar_calib_config = config.lidar_calib_params();
    calibration::CameraCalibParams proto_camera_calib_params = config.camera_calib_params();
    std::string camera_config_path = proto_camera_calib_params.camera_config_path();
    std::cout << camera_config_path <<std::endl;
    calibration::MarkerBoardParmas proto_marker_board_params = config.marker_board_params();
}