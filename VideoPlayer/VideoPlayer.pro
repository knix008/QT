QT += core gui multimedia multimediawidgets widgets

CONFIG += c++11

TARGET = VideoPlayer
TEMPLATE = app

SOURCES += \
    main.cpp \
    videoplayer.cpp

HEADERS += \
    videoplayer.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
