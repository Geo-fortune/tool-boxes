

#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include <open3d/Open3D.h>


int main(int argc, char* argv[]){

    open3d::PrintOpen3DVersion();

    std::string pcd_file_path = "/media/Disk0101/Data/point_clouds/pcds/00005665.pcd";

    auto cloud_ptr = std::make_shared<open3d::geometry::PointCloud>();
    if(open3d::io::ReadPointCloud(pcd_file_path.c_str(), *cloud_ptr)){
        open3d::utility::LogInfo("Successfilly read {}", pcd_file_path.c_str());
    } else {
        open3d::utility::LogError("Failed to read {}", pcd_file_path.c_str());
        return EXIT_FAILURE;
    }

    cloud_ptr->NormalizeNormals();
    open3d::visualization::DrawGeometries({cloud_ptr}, "PointCloud", 1200, 720);
    
    open3d::utility::LogInfo("End of the test.");

    return EXIT_SUCCESS;
}
