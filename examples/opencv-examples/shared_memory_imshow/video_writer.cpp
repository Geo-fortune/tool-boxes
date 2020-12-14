#include <memory>
#include <string>
#include <vector>

#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#include "opencv2/opencv.hpp"
#include "shared_image_data.h"

int main(int argc, char ** argv){
    
    std::string video_path = "/media/Disk0101/Data/video-ins-data/CarLightDetection/data/videos/12_11_48MJPG-0000.avi";

    void * shm = NULL;
    shared_image_data * shared_data_p = NULL;
    int shmid = shmget((key_t)1212, sizeof(shared_image_data), 0666| IPC_CREAT);
    if(shmid == -1){
        printf("shmget failed!\n");
        exit(EXIT_FAILURE);
    }    

    shm= shmat(shmid, NULL, 0);
    if(shm == (void*)-1){
        printf("shmat failed\n");
        exit(EXIT_FAILURE);
    }

    shared_data_p = (shared_image_data*) shm;

    cv::VideoCapture vCap;
    vCap.open(video_path.c_str());

    int i = 0;
    while (vCap.isOpened())
    {
        cv::Mat img;
        vCap.read(img);

        if(img.empty()){
            break;
        }
        // cv::cvtColor(img,img,cv::COLOR_BGR2GRAY);

        std::cout << "imgSize:" << img.cols << "," << img.rows << std::endl;

        // cv::imshow("test",img);
        // cv::waitKey(1);
        // std::string str_id = 0;
        // std::string str_time = 0;
         
        // strncpy(shared_data_p->frame_id_, str_id.c_str(), str_id.size());

        // shared_data_p->image_width_ = img.cols;
        // shared_data_p->image_height_ = img.rows;
        // 开辟一块内存地址
        // memset(shared_data_p->image_data_, 0, img.cols * img.rows );

        for(int i=0; i< img.rows; i++){
            for(int j=0; j< img.cols; j++){
                shared_data_p->image_data_[ (i *img.cols + j) * 3 + 0] = img.at<cv::Vec3b>(i,j)[0] ;
                shared_data_p->image_data_[ (i *img.cols + j) * 3 + 1] = img.at<cv::Vec3b>(i,j)[1] ;
                shared_data_p->image_data_[ (i *img.cols + j) * 3 + 2] = img.at<cv::Vec3b>(i,j)[2] ;
            }
        }

        // cv::Mat imgTest = cv::Mat(IMAGE_HEIGHT,IMAGE_WIDTH,CV_8UC1);
        // for(int i=0; i<IMAGE_HEIGHT ; i++){
        //     for(int j=0; j< IMAGE_WIDTH; j++){
        //         imgTest.at<uchar>(i,j) = shared_data_p->image_data_[i* IMAGE_HEIGHT + j];
        //     }
        // }

        // imshow("test2", imgTest);

        // std::cout << "cap image" <<std::endl;
        // cv::waitKey(1000 / vCap.get(cv::VideoCaptureProperties::CAP_PROP_FPS));
    }
    
    if(shmdt(shm) == -1){
        printf("shmdt failed\n");
        exit(EXIT_FAILURE);
    }

    usleep(2000);
    exit(EXIT_SUCCESS);
}