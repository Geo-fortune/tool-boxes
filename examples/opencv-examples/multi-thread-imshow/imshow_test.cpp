
#include <iostream>
#include <memory>
#include <thread>

#include <opencv2/opencv.hpp>

void thread_visualization_1();
void thread_visualization_2();
void thread_visualization_3();

int main(int argc, char* argv[]){

    std::thread thread1, thread2, thread3;

    try
    {
        thread1 = std::thread(thread_visualization_1);
        thread2 = std::thread(thread_visualization_2);
        thread3 = std::thread(thread_visualization_3);
    }
    catch(const std::exception& e)
    {
        thread1.join();
        thread2.join();
        thread3.join();
        std::cerr << e.what() << '\n';
    }

    thread1.join();
    thread2.join();
    thread3.join();

    return EXIT_SUCCESS;
}



void thread_visualization_1(){

    std::string video_path = "/media/Disk0101/Data/video-ins-data/CarLightDetection/data/videos/12_21_14MJPG-0000.avi";
    // cv::Mat img = cv::imread(image_path.c_str(),1);

    cv::VideoCapture vCap;
    vCap.open(video_path.c_str());

    if(not vCap.isOpened()){
        std::cout << "video opened failed!" << std::endl;
        return;
    }

    while (vCap.isOpened())
    {
        cv::Mat img;
        vCap.read(img);
        /* code */
        cv::imshow("test1", img);  
        cv::waitKey(1);  
    }
}

void thread_visualization_2(){

    std::string video_path = "/media/Disk0101/Data/video-ins-data/CarLightDetection/data/videos/12_14_19MJPG-0000.avi";
    cv::VideoCapture vCap;
    vCap.open(video_path.c_str());

    if(not vCap.isOpened()){
        std::cout << "video opened failed!" << std::endl;
        return;
    }

    while (vCap.isOpened())
    {
        cv::Mat img;
        vCap.read(img);
        /* code */
        cv::imshow("test2", img);  
        cv::waitKey(1);  
    }
}

void thread_visualization_3(){

    std::string video_path = "/media/Disk0101/Data/video-ins-data/CarLightDetection/data/videos/12_11_48MJPG-0000.avi";
    cv::VideoCapture vCap;
    vCap.open(video_path.c_str());

    if(not vCap.isOpened()){
        std::cout << "video opened failed!" << std::endl;
        return;
    }

    while (vCap.isOpened())
    {
        cv::Mat img;
        vCap.read(img);
        /* code */
        cv::imshow("test3", img);  
        cv::waitKey(1);  
    }
}

