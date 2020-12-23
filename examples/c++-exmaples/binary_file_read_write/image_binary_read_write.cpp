#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include <opencv2/opencv.hpp>

bool cvMatWrite(std::string &filename, cv::Mat &img);
bool cvMatRead(std::string & filename, cv::Mat &img);


int main(int argc, char** argv){
    
    std::string test_data_path = argv[1];
    cv::Mat test_img = cv::imread(test_data_path.c_str());

    cv::imshow("test",test_img);
    cv::waitKey(0);

    //开辟内存进行二进制图像保存

    std::string file_path = "test.binary";

    if(!cvMatWrite(file_path, test_img)){
    
        std::cout << "binary write failed!" << std::endl;
        return EXIT_FAILURE;
    } 
    cv::Mat binary_image;
    if(!cvMatRead(file_path, binary_image)){
        
        std::cout << "binary read failed!" << std::endl;
        return EXIT_FAILURE;
    }

    cv::imshow("test_binary", binary_image);
    cv::waitKey(0);

    // cv::FileStorage fs("test.xml", cv::FileStorage::WRITE);
    // fs << "test image" << binary_image;
    // fs.release();
    return EXIT_SUCCESS;
}


bool cvMatWrite(std::string &filename, cv::Mat &img){

    FILE *file_write_p = fopen(filename.c_str(), "wb");
    if(file_write_p == NULL || img.empty()){
        return false;
    }

    fwrite("img", sizeof(char), 3, file_write_p);
    int headData[3] = {img.cols, img.rows, img.type()};
    fwrite(headData, sizeof(int), 3, file_write_p);
    fwrite(img.data, sizeof(char), img.step*img.rows, file_write_p);
    fclose(file_write_p);
    return true;
}

bool cvMatRead(std::string & filename, cv::Mat &img){

    FILE *file_read_p = fopen(filename.c_str(), "rb");
    if(file_read_p ==NULL){
        return false;
    }
    char buf[6];
    int pre_name = fread(buf, sizeof(char), 3, file_read_p);
    if(strncmp(buf, "img", 3) != 0){
        std::cout << "Invalidate cvMat Data file  "<< filename << std::endl;
        return false; 
    }

    int pre_head[3] ;
    fread(pre_head, sizeof(int), 3, file_read_p);
    std::cout << "pre_head:" << pre_head[0] << ","<< pre_head[1] << ","<< pre_head[2] << std::endl;
    cv::Mat M(pre_head[1], pre_head[0], pre_head[2]);
    fread(M.data, sizeof(char), M.step * M.rows, file_read_p);
    std::cout << "M:" << M.step << "," << M.rows << std::endl;
    fclose(file_read_p);
    M.copyTo(img);

    return true;
}
