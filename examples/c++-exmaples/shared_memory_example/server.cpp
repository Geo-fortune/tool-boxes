#include <memory>
#include <thread>
#include <string>
#include <vector>
#include <string.h>
#include "common_shm.h"

int main(int argc, char ** argv){

    // int shmid = myshm::CreateShm(4*1024);
    // char * addr =(char*) shmat(shmid, NULL, 0);
    // usleep(2000);
    // int i=0;
    // while(i<26){

    //     addr[i] = 'A' + i;

    //     i++;
    //     addr[i] = 0; //给下一个char初始化
    //     usleep(1000);
    // }
    // shmdt(addr);
    // usleep(2000);
    // myshm::DestroyShm(shmid); 


    int running = 1;
    void * shm = NULL;
    myshm::shared_use_st *shared_use_data =NULL;
    int shmid;
    shmid = shmget((key_t)1111, sizeof(myshm::shared_use_st), 0666|IPC_CREAT);

    if(shmid == -1){
        printf("shmget failed!\n");
        exit(EXIT_FAILURE);
    }

    shm= shmat(shmid, NULL, 0);

    if(shm == (void*)-1){
        printf("shmat failed\n");
        exit(EXIT_FAILURE);
    }

    shared_use_data = (myshm::shared_use_st*) shm;

    while (running)
    {
        while (shared_use_data->written == 1) {
            usleep(5000);
            printf("waitting...\n");
        }
        std::string str;
        printf("Enter some text: ");
        std::cin >> str;
        strncpy(shared_use_data->text, str.c_str(), TEXT_SIZE);
        std::cout<< "input text:" << shared_use_data->text << std::endl ;
        shared_use_data->written = 1;
        if(strncmp(shared_use_data->text, "end", 3) == 0){
            running = 0;
        }
        usleep(1000);
    }
    
    if(shmdt(shm) == -1){
        printf("shmdt failed\n");
        exit(EXIT_FAILURE);
    }

    usleep(2000);
    return EXIT_SUCCESS;
}