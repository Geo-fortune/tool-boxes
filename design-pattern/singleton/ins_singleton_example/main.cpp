
// AD Sensor & Perception Group
// author : fengchen
// Data: 10/14/2019

#include <thread>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <signal.h>
#include <unistd.h>
#include <condition_variable>
#include "ins_data_receiver.h"

const std::string INS_CHANNEL = "InsData";
bool if_terminal = false;
void sig_handler(int sig);
void insRecv();

using namespace std;

int main(int argc, char *argv[])
{
    std::thread insLoad(insRecv);
    admsg::ins::InsData insData;
    /*开始采集*/
    while (not if_terminal)
    {
        insData =InsDataReceiver::Instance()->GetInsData();
        if ( insData.lontitude == 0 )
        {
            continue;
        }
        std::cout << insData.timestamp << std::endl;
        std::cout << insData.rmsTimestamp<< std::endl;
        std::cout << insData.heading << std::endl;
        std::cout << insData.headingRms << std::endl;
        std::cout << insData.height << std::endl;
        std::cout << insData.latitude << std::endl;
        std::cout << insData.xAcceleration << std::endl;
        std::string strCurrentTimeStamp = std::to_string(insData.timestamp);
        std::cout << "strCurrentTimeStamp: " << strCurrentTimeStamp <<std::endl;
    }
    insLoad.join();
    std::cout << "Terminated by Ctrl+C signal." << std::endl;
    std::cout << "Finishes data saving or some other work, and then exits.";
    return 0;
}

void sig_handler(int sig)
{
    if (sig == SIGINT)
    {
        if_terminal = true;
    }
}

void insRecv() {
    static lcm::LCM lcm("udpm://239.255.76.67:7667?ttl=1");
    if (!lcm.good()) {
        perror("lcm error");
    }
    InsDataReceiver *receiver = InsDataReceiver::Instance();
    lcm.subscribe("InsTest", &InsDataReceiver::ReceiveInsData, receiver);
    while (not if_terminal)
        lcm.handleTimeout(100);
}