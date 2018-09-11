#include "fortunethread.h"
#include <iostream>

/*********************************************************************************************/
int FortuneThread::ProtocolProcess()
{
    int StartIndex,EndIndex;
    QByteArray FrameData;
    bool start_byteFlag = receivedBuffer.contains('*');
    bool end_byteFlag = receivedBuffer.contains('#');
    if((start_byteFlag ==false)&&(end_byteFlag ==false))
    {
        receivedBuffer.clear();
        return 5;
    }
    else if((start_byteFlag == false)&&(end_byteFlag == true))
    {
        receivedBuffer.clear();
        return 6;
    }
    else if((start_byteFlag == true)&&(end_byteFlag == false))
    {
        receivedBuffer.remove(0,receivedBuffer.indexOf('*'));
        return 7;
    }
    StartIndex = receivedBuffer.indexOf('*')+1;
    EndIndex = receivedBuffer.indexOf('#');
    if(EndIndex>StartIndex)
    {
        FrameData = receivedBuffer.mid(StartIndex,EndIndex-StartIndex);
        receivedBuffer.remove(0,receivedBuffer.indexOf('#')+1);
    }
    else
    {
        receivedBuffer.remove(0,receivedBuffer.indexOf('*'));
        return 2;
    }
    int FrameLength = FrameData.mid(6,4).toInt();
    if(FrameLength == FrameData.length())
    {
        LastFrameData = FrameData;
        return 0;
    }
    else
    {
        return 1;
    }
}
/*********************************************************************************************/
void FortuneThread::MsgProcess()
{
    int MainMsg = LastFrameData.mid(10,2).toInt();
    switch(MainMsg)
    {
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    {
        emit sig_receiveFrameEvent(LastFrameData,ClientIP,ClientPort, ThreadNo);
        break;
    }
    default:
    {
        qDebug()<<"not wms-request message";
        break;
    }
    }
    //UplinkRepeat();
}

