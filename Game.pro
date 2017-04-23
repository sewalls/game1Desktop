QT += widgets
QT += multimedia

CONFIG += gui
CONFIG += c++11

SOURCES += \
    main.cpp \
    vec2d.cpp \
    graphics.cpp \
    vec3d.cpp \
    plugin.cpp 

HEADERS  += \
    graphics.h \
    vec2d.h \
    graphics.h \
    window.h \
    vec3d.h \
    plugin.h 

DISTFILES += \
    data/ShortLaser.wav \
    data/comp.png

