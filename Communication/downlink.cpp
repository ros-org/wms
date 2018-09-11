#include "fortunethread.h"
#include <iostream>
/**************************************************************************************************/
//timestamp is six nummber intervaltime is SDK compute time
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
bool FortuneThread::PushDownlinkMsg(QByteArray Msg,int maxRepeatcount)
{
    if(MsgMutex.tryLock())
    {
        int timeStamp = Msg.mid(1,6).toInt();
        SendMsgInfo TempMsg;
        TempMsg.Msg = Msg;
        TempMsg.MaxRepeatCount = maxRepeatcount;
        TempMsg.RepeatCount = 0;
        DownlinkMsgInfoMap.insert(timeStamp,TempMsg);
        lastCommand = Msg;
        bool success = false;
        do
        {
            success = WriteToSendBuf(Msg);
        }while(!success);

        //for test
        if(success)
        {
            if(Msg.mid(11,2).toInt() != 29)
            {
                qDebug("[%d][%s:%s]sendmsg: %s", ThreadNo, qPrintable(ClientIP), qPrintable(ClientPort), qPrintable(Msg));
                //qDebug()<<"Buffer Write Success:"<<Msg<<ClientIP<<ClientPort<<"["<<ThreadNo<<"]";
            }
        }
        else
        {
            qDebug()<<"Buffer Write Failed:"<<Msg<<ClientIP<<ClientPort<<"["<<ThreadNo<<"]";
        }
        //for test
        MsgMutex.unlock();
        return success;
    }
    else
    {
        qDebug()<<"Buffer Write Failed:"<<Msg<<ClientIP<<ClientPort<<"["<<ThreadNo<<"]";
        return false;
    }
}

/**************************************************************************************************/
//
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void FortuneThread::RepeatCheck(void)
{
    QMap<int,SendMsgInfo>::iterator Index;
    if(0 == DownlinkMsgInfoMap.size())
        return;

    if(MsgMutex.tryLock())
    {
        if(0 == DownlinkMsgInfoMap.size())
        {
            MsgMutex.unlock();
            return;
        }
        for( Index =DownlinkMsgInfoMap.begin(); Index != DownlinkMsgInfoMap.end(); Index++)
        {
            if(Index.value().RepeatCount >= Index.value().MaxRepeatCount)
            {
                qDebug()<<"Msg send failed :"<<Index.value().Msg<<ClientIP<<ClientPort<<"["<<ThreadNo<<"]";
                Index =DownlinkMsgInfoMap.erase(Index);
                sendMsgFailure++;
                if(sendMsgFailure>4)
                {
                    IsValid = false;
                    sendMsgFailure = 0;
                    //clear DownlinkMsgInfoMap
                    QMap<int,SendMsgInfo> TempInfo;
                    DownlinkMsgInfoMap.swap(TempInfo);
                }
                break;
            }
            else
            {
                Index.value().RepeatCount++;

                //bool success = false;
                //                do
                //                {
                WriteToSendBuf(Index.value().Msg);
                //                }while(!success);

                //for test
                if(Index.value().RepeatCount>1)
                {
                    qDebug()<<"Repeat Send:"<<Index.value().Msg<<ClientIP<<ClientPort<<"["<<ThreadNo<<"]";

                }
                //for test
            }
        }
        MsgMutex.unlock();
    }
    else
    {
        qDebug()<<"Downlink Can't erase :"<<ClientIP<<ClientPort<<"["<<ThreadNo<<"]";
    }

}
/**************************************************************************************************/
//timestamp is six nummber
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
bool FortuneThread::ClearDownlinkMsg(void)
{
    if(MsgMutex.tryLock())
    {
        QMap<int,SendMsgInfo> TempInfo;
        DownlinkMsgInfoMap.swap(TempInfo);
        MsgMutex.unlock();
        return true;
    }
    else
    {
        return false;
    }
}
