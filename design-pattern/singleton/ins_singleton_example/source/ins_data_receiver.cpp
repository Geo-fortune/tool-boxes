#include "admsg/ins/InsData.hpp"
#include "ins_data_receiver.h"

InsDataReceiver * InsDataReceiver::m_pInsHandler = new InsDataReceiver;

void InsDataReceiver::ReceiveInsData(const lcm::ReceiveBuffer *rbuf, const std::string &channel, const admsg::ins::InsData *msg) {
    m_mtxInsData.lock();

    if (m_deqInsDatas.size() < InsDataLength) {
        m_deqInsDatas.push_back(*msg);
    } else {
        m_deqInsDatas.pop_front();
        m_deqInsDatas.push_back(*msg);
    }

    m_mtxInsData.unlock();
}

admsg::ins::InsData InsDataReceiver::GetInsData() 
{

    if (m_deqInsDatas.size() > 0) {
        return m_deqInsDatas.back();
    }
    else
    {
        return admsg::ins::InsData();
    }

}

InsDataReceiver * InsDataReceiver::Instance()
{
    return m_pInsHandler;
}
