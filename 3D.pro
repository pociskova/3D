LIBS += -lglut
LIBS += -lGL
LIBS += -lGLU
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    engine.cpp \
    camera.cpp \
    key.cpp \
    point3d.cpp \
    primitives.cpp \
    gloptions.cpp \
    matrix4x4.cpp \
    light.cpp \
    matrixtransform.cpp \
    texturehandler.cpp \
    texture.cpp \
    boundingsphere.cpp

HEADERS += \
    engine.h \
    camera.h \
    key.h \
    point3d.h \
    primitives.h \
    primitives.h \
    gloptions.h \
    matrix4x4.h \
    light.h \
    matrixtransform.h \
    texturehandler.h \
    texture.h \
    boundingsphere.h
