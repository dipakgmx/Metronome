#-------------------------------------------------
#
# Project created by QtCreator 2019-05-08T19:23:21
#
#-------------------------------------------------

QT       += core gui\
            multimedia

QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtMetronome
TEMPLATE = app


SOURCES += main.cpp\
    Ticker.cpp \
    Timer.cpp \
    MainWindow.cpp

HEADERS  += \
    Ticker.h \
    Timer.h \
    MainWindow.h

RESOURCES += \
    resource.qrc
