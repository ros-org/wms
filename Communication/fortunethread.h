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

#ifndef FORTUNETHREAD_H
#define FORTUNETHREAD_H

#include <QThread>
#include <QBasicTimer>
#include <QTcpSocket>
#include    <QMutex>
#define REPEATTIMES 5
using namespace std;

typedef class SendMsgInfo
{
public:
    QByteArray  Msg;
    int                 MaxRepeatCount;
    //private:
    int                 RepeatCount;
}SendMsgInfo;

enum robotStatus
{
    ROBOT_UP_STOP = 0, //Stop
    ROBOT_UP_MOVE = 1, //Move
    ROBOT_UP_CLOCKWISE = 2, //clockwise
    ROBOT_UP_UNCLOCKWISE = 3 //unclockwise
};
/******************************************************************************************************************/
class  FortuneThread : public QThread
{
    Q_OBJECT

public:
    QTcpSocket *ptcpSocket;
    bool    IsValid;
    bool    IsConnect;
    bool    NewConnect;
    int socketDescriptor;
    QString ClientIP;
    QString ClientPort;
    QByteArray LastFrameData;
    int         ThreadNo;
    int     sendMsgFailure;

    //-----------------------------------------------------------------------------------------------------
    int battery;
    double  x;
    double  y;
    double  angle;
    int     status; //0-stop 1-move 2-clockwise rotate 3-unclockwise rotate
    QByteArray lastCommand;
    bool thread_run;
    //bool isTurn;
    //QString  currentTurnCardID;
    //    int     waitTimes;
    //    int     awkFlag;
    //-------------------------------------------------------------------------------------------------------
    FortuneThread(QObject *parent);

    void    run() Q_DECL_OVERRIDE;
    int     ProtocolProcess();
    void    MsgProcess();
    bool    WriteToSendBuf(QByteArray);
    bool    PushDownlinkMsg(QByteArray , int );
    void    RepeatCheck(void);
    bool    ClearDownlinkMsg(void);

signals:
    void sig_receiveFrameEvent(const QByteArray ,const QString,const QString, const int);
public slots:
    void DisconnectDeal(void);
protected:
    //void timerEvent(QTimerEvent *);
private:
    QByteArray      receivedBuffer;
    QByteArray      sendBuffer;
    QMutex            writeMutex;
    QMutex            MsgMutex;
    QMap<int,SendMsgInfo>    DownlinkMsgInfoMap;
    //QBasicTimer *pRepeatSendtimer;
    //for test
    int err_count1;
    int err_count2;
    int err_count3;
    int err_count4;
    int err_count5;
    int err_count6;
    QByteArray   GetFromSendBuf(int);
};

#endif
