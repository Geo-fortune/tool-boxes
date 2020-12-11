#pragma once

#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#define PROJ_ID 0x6666
#define PATH_NAME "."
#define TEXT_SIZE 4096
namespace myshm{

struct shared_use_st{

    int written;
    char text[TEXT_SIZE];
};


int CreateShm(int size);
int DestroyShm(int shmid);
int GetShm(int size);

};