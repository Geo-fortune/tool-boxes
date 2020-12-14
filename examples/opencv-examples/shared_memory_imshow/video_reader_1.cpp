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

int main(int argc, char ** argv) {

    int running = 1; // 程序持续运行
    void * shm = NULL;
    shared_image_data * shared_data_p = NULL;
    int shmid = shmget((key_t)1212, sizeof(shared_image_data), 0666| IPC_CREAT);
    if(shmid == -1) {
        printf("shmget failed!\n");
        exit(EXIT_FAILURE);
    }

    shm= shmat(shmid, NULL, 0);
    if(shm == (void*)-1) {
        printf("shmat failed\n");
        exit(EXIT_FAILURE);
    }

    std::cout << "cout " << std::endl;

    shared_data_p = (shared_image_data*) shm;

    while (running)
    {

        cv::Mat img(IMAGE_HEIGHT,IMAGE_WIDTH, CV_8UC3, shared_data_p->image_data_);
        
        cv::cvtColor(img,img,cv::COLOR_BGR2GRAY);

        cv::imshow("test1", img);
        cv::waitKey(1);


        // 计时统计，超过5秒，自动断开

    }

    if(shmdt(shm) == -1) {
        printf("shmdt failed\n");
        exit(EXIT_FAILURE);
    }

    if(shmctl(shmid, IPC_RMID, 0) ==-1) {
        printf("shmctl(IPC_RMID) failed");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}