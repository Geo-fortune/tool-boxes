#include <memory>
#include <thread>
#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>

#include "common_shm.h"

int main(int argc, char ** argv){

/*
    int shmid = myshm::GetShm(4* 1024);
    usleep(1000);
    char* addr = (char*)shmat(shmid, NULL, 0);
    usleep(2000);
    int i=0;

    while (i++ < 25)
    {
        printf("client # %s\n", addr);
        usleep(1000);
    }

    shmdt(addr);
    usleep(1000);
*/


    int running = 1; //程序是否继续运行
    void *shm = NULL; // 分配的原始

    myshm::shared_use_st* shared_shm_data;

    int shmid;
    shmid = shmget( (key_t)1111, sizeof(myshm::shared_use_st),0666|IPC_CREAT);

    //判断是否创建成功
    if(shmid == -1){
        perror("shmget failed\n");
        exit(EXIT_FAILURE);
    }

    shm = shmat(shmid, NULL, 0);
    if(shm == (void*) -1){
        perror("shmat failed\n");
        exit(EXIT_FAILURE);
    }

    shared_shm_data = (myshm::shared_use_st*)shm;

    shared_shm_data->written = 0;

    while (running)
    {
        if(shared_shm_data->written !=0){
            printf("written: %s \n", shared_shm_data->text);
            usleep(1000);
            shared_shm_data->written = 0;
            
            if(strncmp(shared_shm_data->text, "end", 3) == 0){
                running = 0;
            }
        }else{
            usleep(1000);
        }
    }

    if(shmdt(shm) == -1){
        printf("shmdt failed\n");
        exit(EXIT_FAILURE);
    }

    if(shmctl(shmid, IPC_RMID, 0) ==-1){
        printf("shmctl(IPC_RMID) failed");
        exit(EXIT_FAILURE);
    }
     
    return EXIT_SUCCESS;
}