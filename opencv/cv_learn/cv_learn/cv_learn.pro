#-------------------------------------------------
#
# Project created by QtCreator 2016-06-19T11:23:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cv_learn
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    videoplayer.cpp \
    displayimage.cpp \
    img_proc.cpp

HEADERS  += mainwindow.h \
    videoplayer.h \
    displayimage.h \
    img_proc.h

LIBS += -L/usrlocal/lib/ -lopencv_core -lopencv_highgui -lopencv_imgproc

FORMS    += mainwindow.ui
