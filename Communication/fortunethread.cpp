/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "fortunethread.h"
#ifdef WIN32
#include <winsock.h>
#pragma  comment(lib,"ws2_32.lib")
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#endif
#include <QtNetwork>
#include <iostream>
/************************************************************************************/
FortuneThread::FortuneThread(QObject *parent)
    : QThread(parent)
{
    //pRepeatSendtimer =new QBasicTimer();
}
/***************************************************************************************/
void FortuneThread::run()
{
    ptcpSocket = new QTcpSocket();
    QByteArray receivedString;
    QByteArray sendString;

    connect(ptcpSocket,SIGNAL(disconnected()),this,SLOT(DisconnectDeal()));

    while(thread_run)
    {
        if(NewConnect ==true)
        {
            //NewConnect = false;
            if (!ptcpSocket->setSocketDescriptor(socketDescriptor))
            {
                NewConnect = false;
                qDebug()<<ptcpSocket->error();
                qDebug()<<"Socket build Failure! NOIP NOPort["<<ThreadNo<<"]";
                return;
            }
            NewConnect = false;
            //-----------------------------------------------------------------------------
            ClientIP =  ptcpSocket->peerAddress().toString();
            ClientPort =QString::number(ptcpSocket->peerPort());
            IsValid =true;
            IsConnect =true;
            sendMsgFailure = 0;
            //pRepeatSendtimer->start(200,this);
            qDebug()<<"Socket build success!"<<ClientIP<<ClientPort<<"["<<ThreadNo<<"]";
            //---------------------------------------------------------------------------------

            int optval;
#ifdef _WIN32
            int optlen = sizeof(optval);
            optval = 1;
            setsockopt(socketDescriptor, SOL_SOCKET, SO_KEEPALIVE, (const char*)&optval, optlen);
#else
            socklen_t optlen = sizeof(optval);
            optval = 1;
            setsockopt(socketDescriptor, SOL_SOCKET, SO_KEEPALIVE, &optval, optlen);
            // 探测尝试的次数.如果第1次探测包就收到响应了,则后2次的不再发.
            optval = 3;
            setsockopt(socketDescriptor, SOL_TCP, TCP_KEEPCNT, &optval, optlen);
            // 如该连接在1秒内没有任何数据往来,则进行探测
            optval =1;
            setsockopt(socketDescriptor, SOL_TCP, TCP_KEEPIDLE, &optval, optlen);
            // 探测时发包的时间间隔为3 秒
            optval =3;
            setsockopt(socketDescriptor, SOL_TCP, TCP_KEEPINTVL, &optval, optlen);
#endif

            //------------------------------------------------------------------------------------------------------------------

            x = 0;
            y = 0;
            angle = 0;
            status = 0;
            battery = 0;
            //===============================================================================
        }
        if(IsValid == false)
        {
            if(IsConnect ==true)
            {
                IsConnect =false;
                //连续15秒无响应，主动断开
                ptcpSocket->disconnectFromHost();
                ptcpSocket->waitForDisconnected();
                qDebug()<<"Manul Socket DisConnect!"<<ClientIP<<ClientPort<<"["<<ThreadNo<<"]";
            }
            continue;
        }
        //---------------------------------------------------------------------------------------
        //socket write
        //-------------------------------------------------------------------------------------------
        sendString = GetFromSendBuf(100);
        ptcpSocket->write(sendString);
        //ptcpSocket->waitForBytesWritten(0);

        //-------------------------------------------------------------------------------------------
        //socket read
        //-------------------------------------------------------------------------------------------
        if(true == ptcpSocket->waitForReadyRead(5))
        {
            receivedString.clear();
            receivedString = ptcpSocket->readAll();
            receivedBuffer.append(receivedString);
        }
        int returnValue;
        do
        {
            returnValue = ProtocolProcess();
            switch(returnValue)
            {
            case 0:
                MsgProcess();
                break;
            case 1:
                err_count1++;
                break;
            case 2:
                err_count2++;
                break;
            case 3:
                err_count3++;
                break;
            case 4:
                err_count4++;
                break;
            case 5:
                err_count5++;
                break;
            case 6:
                err_count6++;
                break;
            default:
                break;

            }
        }while(receivedBuffer.length() >12 && returnValue == 0);
        msleep(50);
    }

    //    tcpSocket.disconnectFromHost();
    //    tcpSocket.waitForDisconnected();
}

/*****************************************************************************************************************/
bool   FortuneThread:: WriteToSendBuf(QByteArray Msg)
{

    if(writeMutex.tryLock())
    {
        //writeMutex.lock();
        sendBuffer.append(Msg);
        writeMutex.unlock();
        return true;
    }
    else
    {
        return false;
    }
}
/*****************************************************************************************************************/
QByteArray   FortuneThread:: GetFromSendBuf(int ByteNum)
{
    QByteArray returnArray="";
    if(writeMutex.tryLock())
    {
        if(sendBuffer.length()<=ByteNum)
        {
            returnArray = sendBuffer;
            sendBuffer.clear();
        }
        else
        {
            returnArray = sendBuffer.mid(0,ByteNum);
            sendBuffer.remove(0,ByteNum);
        }
        writeMutex.unlock();
    }
    return returnArray;
}
/*********************************************************************************************************************************/
void FortuneThread::DisconnectDeal(void)
{
    IsConnect = false;
    qDebug()<<"System Socket DisConnect!"<<ClientIP<<ClientPort<<"["<<ThreadNo<<"]";
}
