QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vizs_project
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        object.cpp

INCLUDEPATH += C:\opencv\new\build\install\include
LIBS += -LC:\opencv\new\build\install\x86\mingw\lib \
    -lopencv_core320.dll \
    -lopencv_highgui320.dll \
    -lopencv_imgcodecs320.dll \
    -lopencv_imgproc320.dll \
    -lopencv_features2d320.dll \
    -lopencv_flann320.dll \
    -lopencv_ml320.dll \
    -lopencv_calib3d320.dll \
    -lopencv_videoio320.dll

HEADERS  += mainwindow.h \
            object.h

FORMS    += mainwindow.ui
