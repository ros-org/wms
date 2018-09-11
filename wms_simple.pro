                        QT += core
QT += network sql websockets
QT -= gui

TARGET = wms_simple
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11
TEMPLATE = app

SOURCES += main.cpp \
    Communication/downlink.cpp \
    Communication/fortuneserver.cpp \
    Communication/fortunethread.cpp \
    Communication/uplink.cpp \
    Database/db.cpp \
    Communication/websocketserver.cpp \
    Interface/interface_wms.cpp \
    API/api_websocket.cpp \
    API/api_tcpip.cpp \
    API/api_thread.cpp \
    API/api_task.cpp \
    Communication/opcua.cpp \
    API/api_opcua.cpp

HEADERS += \
    Communication/fortuneserver.h \
    Communication/fortunethread.h \
    Database/db.h \
    Communication/websocketserver.h \
    Interface/interface_wms.h \
    API/api_common.h \
    API/api_thread.h \
    Communication/opcua.h


LIBS += $$PWD/Communication/lib/libcoremodule.a \
                              $$PWD/Communication/lib/libcoremoduled.a \
                              $$PWD/Communication/lib/libuabase.a \
                              $$PWD/Communication/lib/libuabased.a \
                              $$PWD/Communication/lib/libuaclient.a \
                              $$PWD/Communication/lib/libuaclientd.a \
                              $$PWD/Communication/lib/libuamodels.a \
                              $$PWD/Communication/lib/libuamodelsd.a \
                              $$PWD/Communication/lib/libuamodule.a \
                              $$PWD/Communication/lib/libuamoduled.a \
                              $$PWD/Communication/lib/libuapki.a \
                              $$PWD/Communication/lib/libuapkid.a \
                              $$PWD/Communication/lib/libxmlparser.a \
                              $$PWD/Communication/lib/libxmlparserd.a \
                              $$PWD/Communication/lib/libuastack.so \
                              $$PWD/Communication/lib/libuastackd.so



unix:!macx: LIBS += -L$$PWD/Communication/lib/  -luamodule -luamodels -lcoremodule -luabase -luastack -lxmlparser -luapki -luaclient -lxml2 -lssl -lcrypto


INCLUDEPATH += $$PWD/Communication/include \
               $$PWD/Communication/include/uabase \
               $$PWD/Communication/include/uaclient \
               $$PWD/Communication/include/uamodels \
               $$PWD/Communication/include/uapki \
               $$PWD/Communication/include/uaserver \
               $$PWD/Communication/include/uastack \
               $$PWD/Communication/include/xmlparser

INCLUDEPATH += lib
DEPENDPATH += lib

unix:!macx: PRE_TARGETDEPS += $$PWD/Communication/lib/libcoremodule.a \
                              $$PWD/Communication/lib/libcoremoduled.a \
                              $$PWD/Communication/lib/libuabase.a \
                              $$PWD/Communication/lib/libuabased.a \
                              $$PWD/Communication/lib/libuaclient.a \
                              $$PWD/Communication/lib/libuaclientd.a \
                              $$PWD/Communication/lib/libuamodels.a \
                              $$PWD/Communication/lib/libuamodelsd.a \
                              $$PWD/Communication/lib/libuamodule.a \
                              $$PWD/Communication/lib/libuamoduled.a \
                              $$PWD/Communication/lib/libuapki.a \
                              $$PWD/Communication/lib/libuapkid.a \
                              $$PWD/Communication/lib/libxmlparser.a \
                              $$PWD/Communication/lib/libxmlparserd.a \
                              $$PWD/Communication/lib/libuastack.so \
                              $$PWD/Communication/lib/libuastackd.so


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/Communication/lib/release/ -luaclientd
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/Communication/lib/debug/ -luaclientd
else:unix: LIBS += -L$$PWD/Communication/lib/ -luaclientd

INCLUDEPATH += include
DEPENDPATH += include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/Communication/lib/release/libuaclientd.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/Communication/lib/debug/libuaclientd.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/Communication/lib/release/uaclientd.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/Communication/lib/debug/uaclientd.lib
else:unix: PRE_TARGETDEPS += $$PWD/Communication/lib/libuaclientd.a
