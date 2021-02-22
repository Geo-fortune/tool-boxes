

#pragma once

#include <lcm/lcm-cpp.hpp>
#include "admsg/ins/InsData.hpp"
#include <mutex>
#include <deque>
#include <iostream>
#include <memory>
// using namespace std;

const unsigned int InsDataLength = 10;

class InsDataReceiver
{
public:

    static InsDataReceiver * Instance();
    admsg::ins::InsData GetInsData();
    void ReceiveInsData(const lcm::ReceiveBuffer *rbuf, const std::string &channel, const admsg::ins::InsData *msg);

private:
    InsDataReceiver(const InsDataReceiver &) = delete;
    InsDataReceiver &operator=(const InsDataReceiver &) = delete;
    static InsDataReceiver *m_pInsHandler;

    std::mutex m_mtxInsData;
    std::deque< admsg::ins::InsData > m_deqInsDatas;

    InsDataReceiver()
    {
        std::cout << "INS:constructor called!" << std::endl;
    }
};

