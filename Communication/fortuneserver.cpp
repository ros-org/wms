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

#include "fortuneserver.h"
#include "fortunethread.h"
#ifdef WIN32
#include <winsock.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#endif
#include <stdlib.h>
#include <iostream>

//! [0]
FortuneServer::FortuneServer(QObject *parent)
    : QTcpServer(parent)
{

}
//! [0]

//! [1]
void FortuneServer::incomingConnection(qintptr socketDescriptor)
{
   // QMutexLocker locker(&mutex_incoming);
   if(true == mutex_incoming.tryLock())
    {
    if(CNT_TcpThread+1>MAX_NUM_CLIENT)
    {
        qDebug()<<"Index of TcpThread is MAX!";
        QTcpSocket tcpSocket;
        tcpSocket.setSocketDescriptor(socketDescriptor);
        tcpSocket.disconnectFromHost();
        tcpSocket.waitForDisconnected();
        mutex_incoming.unlock();
        return;
    }
    else
    {
        int Index = 0;
        if(CNT_TcpThread>0)
        {
            Index = -1;
            for(int j =0;j<MAX_NUM_CLIENT;j++)
            {
                if(true ==pTcpThread[j]->NewConnect)
                {
                    if(pTcpThread[j]->socketDescriptor == socketDescriptor)
                    {
                        qDebug()<<"NewConnect is repeat!---thread num:"+QString::number(j);
                        return;
                    }
                    else
                    {
                        //emit SystemInfo_server2main("NewConnect is building!---thread num:"+QString::number(j));
                        continue;
                    }
                }
                if(false ==pTcpThread[j]->IsConnect)
                {
                    if(true ==pTcpThread[j]->IsValid)
                    {
                        //pTcpThread[j]->ptcpSocket->close();
                        //pTcpThread[j]->ptcpSocket->deleteLater();
                        pTcpThread[j]->quit();
                        pTcpThread[j]->IsValid = false;
                        CNT_TcpThread--;
                        if(CNT_TcpThread<0)
                            CNT_TcpThread=0;
                        QString DelThreadInfo = QString::number(j)+"----"+pTcpThread[j]->ClientIP+":"+pTcpThread[j]->ClientPort;
                        qDebug()<<"Thread is quit! Index:"+DelThreadInfo;
//                        pTcpThread[j]->ClientIP.clear();
//                        pTcpThread[j]->ClientPort.clear();
                    }
                    Index =j;
                    break;
                }
            }
            if(Index == -1)
            {
                qDebug()<<"IndexTcpTread is Err!";
                return;
            }
        }

        pTcpThread[Index]->socketDescriptor = socketDescriptor;
        pTcpThread[Index]->NewConnect =true;
        pTcpThread[Index]->thread_run = true;
        qDebug()<<"inCommingConnection!socketDescriptor:"+QString::number(socketDescriptor);
        pTcpThread[Index]->start();
        CNT_TcpThread++;
    }
    mutex_incoming.unlock();
   }
   else
   {
       qDebug()<<"Initail Error!!!inCommingConnection!socketDescriptor:"+QString::number(socketDescriptor);
   }
}

void FortuneServer::slot_receiveFrame_thread2server(const QByteArray Data,const QString ClientIP,const QString ClientPort,const int threadNum)
{
    emit sig_tcpip_msg(Data,ClientIP,ClientPort,threadNum);
}

void FortuneServer::close()
{
    for(int i =0;i<MAX_NUM_CLIENT;i++)
    {
        if(pTcpThread[i]->thread_run)
        {
            pTcpThread[i]->thread_run = false;
        }
        while(pTcpThread[i]->isRunning())
        {
            ;
        }
    }
}
void FortuneServer::init()
{
    CNT_TcpThread = 0;
    IndexTcpThread = 0;
    for(int i =0;i<MAX_NUM_CLIENT;i++)
    {
        FortuneThread *thread = new FortuneThread(this);
        pTcpThread[i] =  thread;
        pTcpThread[i]->IsValid = false;
        pTcpThread[i]->IsConnect = false;
        pTcpThread[i]->NewConnect = false;
        pTcpThread[i]->socketDescriptor = 0;
        pTcpThread[i]->ClientIP = "";
        pTcpThread[i]->ClientPort = "";
        pTcpThread[i]->ThreadNo = i;
        pTcpThread[i]->x = 0;
        pTcpThread[i]->y = 0;
        pTcpThread[i]->angle = 0;
        connect(thread, SIGNAL(sig_receiveFrameEvent(const QByteArray,const QString,const QString,const int)), this, SLOT(slot_receiveFrame_thread2server(const QByteArray,const QString,const QString,const int)),Qt::AutoConnection);
    }
}


/****************************************************************************************************************************
* Function Name :                      PushDownlinkMsg
* Function Main Usage:             Push a maseeage to thread dowlink buffer
*
* Author/Date:                            xu_jf        2016/05/11
* Modefy/Date:
******************************************************************************************************************************/
bool FortuneServer::slot_PushDownlinkMsg(QString IPAddr,QByteArray Msg,int maxRepeatcount)
{
    //for test注释掉，实车调试需恢复
    for(int i=0;i<MAX_NUM_CLIENT;i++)
    {
        if(IPAddr == pTcpThread[i]->ClientIP)
        {
            if((true == pTcpThread[i]->IsValid)&&(true == pTcpThread[i]->IsConnect))
            {
                bool reValue =pTcpThread[i]->PushDownlinkMsg(Msg,maxRepeatcount);
                return reValue;
            }
            else
            {
                return false;
            }
        }
    }
    return false;

  /*  QString test = "send:"+Msg;
    emit SystemInfo_server2main(test);
    cout<<"for test [send]:"<<Msg.toStdString()<<endl;
    return true;*/
}

/****************************************************************************************************************************
* Function Name :                      ClearDownlinkMsg
* Function Main Usage:
*
* Author/Date:                            xu_jf        2016/05/11
* Modefy/Date:
******************************************************************************************************************************/
bool FortuneServer::ClearDownlinkMsg(QString IPAddr)
{
    for(int i=0;i<MAX_NUM_CLIENT;i++)
    {
        if(IPAddr == pTcpThread[i]->ClientIP)
        {
            if((true == pTcpThread[i]->IsValid)&&(true == pTcpThread[i]->IsConnect))
            {
                bool reValue =pTcpThread[i]->ClearDownlinkMsg();
                return reValue;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}
/***********************************************************************************************************************************************/
//! [1]
