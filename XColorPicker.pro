QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = xcolorpicker

SOURCES += \
    src/AppConfig.cpp \
    src/ColorIndicator.cpp \
    src/ColorIndicatorLabel.cpp \
    src/ColorLabel.cpp \
    src/ColorPickerWidget.cpp \
    src/ColorSlider.cpp \
    src/CommonHelper.cpp \
    src/StackConfigFrame.cpp \
    src/StackPickerFrame.cpp \
    src/SystemTrayIcon.cpp \
    src/TrayMenu.cpp \
    src/main.cpp \
    src/MainDialog.cpp

HEADERS += \
    src/AppConfig.h \
    src/ColorIndicator.h \
    src/ColorIndicatorLabel.h \
    src/ColorLabel.h \
    src/ColorPickerWidget.h \
    src/ColorSlider.h \
    src/CommonHelper.h \
    src/MainDialog.h \
    src/StackConfigFrame.h \
    src/StackPickerFrame.h \
    src/SystemTrayIcon.h \
    src/TrayMenu.h

RESOURCES += \
    src/resource/Res.qrc

TRANSLATIONS += english.ts \
                simplified_chinese.ts

CONFIG(debug, debug|release) {
    BUILD_MODE = debug
} else {
    BUILD_MODE = release
}
DESTDIR = $${PWD}/build/$${BUILD_MODE}/bin
MOC_DIR = $${PWD}/build/$${BUILD_MODE}/moc
RCC_DIR = $${PWD}/build/$${BUILD_MODE}/rcc
UI_DIR = $${PWD}/build/$${BUILD_MODE}/ui
unix:OBJECTS_DIR = $${PWD}/build/$${BUILD_MODE}/obj/unix
win32:OBJECTS_DIR = $${PWD}/build/$${BUILD_MODE}/obj/win32
macx:OBJECTS_DIR = $${PWD}/build/$${BUILD_MODE}/obj/mac
