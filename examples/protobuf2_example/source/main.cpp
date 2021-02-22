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


    // // Get image and cloud files from rosbag file
    // calibration::RosbagParams proto_bag_params = config.rosbag_params();
    // RosbagLoaderParams bag_params;
    // bag_params.m_bag_file = proto_bag_params.bag_file();
    // bag_params.m_save_pth = proto_bag_params.save_pth();
    // bag_params.m_image_topic = proto_bag_params.image_topic();
    // bag_params.m_cloud_topic = proto_bag_params.cloud_topic();

    // if (config.use_rosbag())
    // {
    //     RosbagLoader bag_loader;
    //     if (!bag_loader.Init(bag_params))
    //         return -1;
    //     bag_loader.Load();
    // }

    // std::vector<std::string> pcd_files;

    // if (!GetFileNamesInFolderById(bag_params.m_save_pth, ".pcd", &pcd_files))
    // {
    //     std::cout << "Cant find 'pcd' files in " << bag_params.m_save_pth
    //               << std::endl;
    //     return -1;
    // }

    // //Load calibratin configure
    // ConfigSettings calib_config;
    // calibration::LidarCalibParams proto_lidar_calib_config = config.lidar_calib_params();
    // calib_config.s = cv::Size(proto_lidar_calib_config.image_size(0), proto_lidar_calib_config.image_size(1));
    // calib_config.xyz_.push_back(std::make_pair(proto_lidar_calib_config.xyz_range(0), proto_lidar_calib_config.xyz_range(1)));
    // calib_config.xyz_.push_back(std::make_pair(proto_lidar_calib_config.xyz_range(2), proto_lidar_calib_config.xyz_range(3)));
    // calib_config.xyz_.push_back(std::make_pair(proto_lidar_calib_config.xyz_range(4), proto_lidar_calib_config.xyz_range(5)));
    // calib_config.intensity_thresh = proto_lidar_calib_config.intensity_threshold();
    // calib_config.num_of_markers = proto_lidar_calib_config.marker_count();
    // calib_config.useCameraInfo = proto_lidar_calib_config.use_camera_info();

    // float p[12];
    // for (int i = 0; i < 12; i++)
    // {
    //     p[i] = proto_lidar_calib_config.project_matrix(i);
    // }

    // cv::Mat(3, 4, CV_32FC1, &p).copyTo(calib_config.P);
    // calib_config.MAX_ITERS = proto_lidar_calib_config.iteration_count();

    // for (int i = 0; i < 3; ++i)
    // {
    //     calib_config.initialRot.push_back(proto_lidar_calib_config.lidar_init_rot(i));
    // }

    // for (int i = 0; i < 3; ++i)
    // {
    //     calib_config.lidar_origin.push_back(proto_lidar_calib_config.lidar_origin(i));
    // }

    // Eigen::Matrix3d coordinate_transMatrix = 
    //     Eigen::AngleAxisd(-calib_config.initialRot[0], Eigen::Vector3d::UnitX()).toRotationMatrix() * 
    //     Eigen::AngleAxisd(calib_config.initialRot[1], Eigen::Vector3d::UnitY()).toRotationMatrix() * 
    //     Eigen::AngleAxisd(calib_config.initialRot[2], Eigen::Vector3d::UnitZ()).toRotationMatrix();

    // // Select corner points
    // LidarCornersSelection selector(calib_config);

    // // Image marker detection
    // calibration::CameraCalibParams proto_camera_calib_params = config.camera_calib_params();
    // std::string camera_config_path = proto_camera_calib_params.camera_config_path();
    // cv::FileStorage fs(camera_config_path.c_str(), cv::FileStorage::READ);

    // if (!fs.isOpened())
    // {
    //     std::cout << "camera_config file open failed!" << std::endl;
    // }

    // cv::Mat K, D;
    // fs["camera_matrix"] >> K;
    // fs["distortion_coefficients"] >> D;
    // cv::Size image_size = calib_config.s ;
    // myaruco::CameraParameters cam_paras;
    // cam_paras.setParams(K, D, image_size);
    // std::vector<myaruco::Marker> vec_markers;
    // myaruco::MarkerDetector detector;

    // // Set marker board parameters
    // calibration::MarkerBoardParmas proto_marker_board_params = config.marker_board_params();
    // std::vector<float> board;
    // double marker_size_meter = proto_marker_board_params.marker_length() * 1e-2;
    // board.push_back(proto_marker_board_params.board_length_e1() * 1e-2);
    // board.push_back(proto_marker_board_params.board_length_e2() * 1e-2);
    // board.push_back(proto_marker_board_params.board_length_b1() * 1e-2);
    // board.push_back(proto_marker_board_params.board_length_b2() * 1e-2);
    // board.push_back(proto_marker_board_params.marker_length() * 1e-2);

    // // R|t calculator 
    // RTCalculation rt_calculator;

    // for (size_t i = 0; i < pcd_files.size(); ++i)
    // {
    //     // load pcd file
    //     std::string pcd_file = bag_params.m_save_pth + "/" + pcd_files[i];
    //     pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_xyzi(new pcl::PointCloud<pcl::PointXYZI>);

    //     if (pcl::io::loadPCDFile(pcd_file, *cloud_xyzi) < 0)
    //     {
    //         std::cout << "Could not load pcd file: " << pcd_file << std::endl;
    //         continue;
    //     }
    //     std::cout << "Load file: " << pcd_file << ", contain points: " << cloud_xyzi->size()
    //               << std::endl;
        
    //     selector.Select(cloud_xyzi);
    //     Eigen::MatrixXd lidar_corner_pts = selector.ReturnCornerPts();
    
    //     // load img file
    //     std::string img_file = pcd_file.substr(0, pcd_file.length() - 4) + ".jpg";
    //     cv::Mat img_src = cv::imread(img_file.c_str(), IMREAD_GRAYSCALE);
    //     cv::equalizeHist(img_src, img_src);

    //     if (img_src.empty())
    //     {
    //         std::cout << "src image is empty!" << std::endl;
    //         continue;
    //     }

    //     detector.detect(img_src, vec_markers, cam_paras, marker_size_meter, true);

    //     if (vec_markers.size() > 0)
    //     {
    //         std::cout << vec_markers[0].id << std::endl;
    //         cv::Mat output_image;
    //         img_src.copyTo(output_image);

    //         //draw marker
    //         for (size_t k = 0; k < vec_markers.size(); k++)
    //         {
    //             vec_markers[k].draw(output_image, cv::Scalar(0, 0, 255), 2);
    //             myaruco::CvDrawingUtils::draw3dCube(output_image, vec_markers[k], cam_paras);
    //             myaruco::CvDrawingUtils::draw3dAxis(output_image, vec_markers[k], cam_paras);
    //         }

    //         cv::namedWindow("marker", WINDOW_FREERATIO);
    //         cv::imshow("marker", output_image);
    //         cv::waitKey(1);
    //     }
    //     else
    //     {
    //         std::cout << "Maeker detect failde!" << std::endl;
    //     }

    //     ArucoMapping aruco_detector;
    //     aruco_detector.SetVecMarkers(vec_markers);
    //     aruco_detector.readArucoPose(board);
    //     Eigen::MatrixXd image_corner_pts = aruco_detector.GetCornerPts();
    
    //     std::cout << "cloud corners: " << lidar_corner_pts << std::endl;
    //     std::cout << "image corners: " << image_corner_pts << std::endl;

    //     if (lidar_corner_pts.cols() != image_corner_pts.cols())
    //     {
    //         continue;
    //     }

    //     rt_calculator.Calculate(lidar_corner_pts, image_corner_pts);
        
    //     std::cout << "current matrix:\n " << rt_calculator.m_current_matrix << std::endl;
    //     std::cout << "average matrix:\n " << rt_calculator.m_average_matrix << std::endl;
    // }

    // Eigen::Matrix4d result_average_matrix;
    // result_average_matrix.setIdentity(4, 4);
    // result_average_matrix.topLeftCorner(3, 3) = (coordinate_transMatrix * rt_calculator.m_average_matrix.topLeftCorner(3, 3)).inverse();
    // result_average_matrix.col(3) = rt_calculator.m_average_matrix.col(3);
    // std::cout << "result matrix:\n" << result_average_matrix << std::endl;

    // std::ofstream out_file("data/result.txt", ios::out);
    // out_file << "Rigid-body transformation: imu to camera :\n" << result_average_matrix << std::endl;
    // out_file.close();
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