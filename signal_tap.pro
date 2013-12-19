#-------------------------------------------------
#
# Project created by QtCreator 2013-12-08T15:42:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = signal_tap
TEMPLATE = app


SOURCES += \
    src/main.cpp\
    src/MenuEdit.cpp \
    src/MenuFile.cpp \
    src/WaveView.cpp \
    src/WaveTimeLine.cpp \
    src/MenuView.cpp \
    src/MenuReplay.cpp \
    src/MenuHelp.cpp \
    src/MenuCapture.cpp \
    src/MenuBar.cpp \
    src/ToolBar.cpp \
    src/StatusBar.cpp \
    src/SignalTap.cpp \
    src/WaveShow.cpp \
    libs/fst/fastlz.c \
    libs/fst/fstapi.c \
    libs/fst/lz4.c \
    libs/vcd/vcd_header.c \
    libs/vcd/vcd.c \
    usb/st_usb.c \
    usb/UsbHandler.cpp \
    usb/UsbDetector.cpp

HEADERS  += \
    src/MenuEdit.h \
    src/MenuFile.h \
    src/WaveView.h \
    src/WaveTimeLine.h \
    src/MenuView.h \
    src/MenuReplay.h \
    src/MenuHelp.h \
    src/MenuCapture.h \
    src/MenuBar.h \
    src/ToolBar.h \
    src/StatusBar.h \
    src/SignalTap.h \
    src/WaveShow.h \
    libs/fst/fastlz.h \
    libs/fst/fstapi.h \
    libs/fst/linux_x86_64.h \
    libs/fst/lz4.h \
    libs/vcd/vcd_header.h \
    libs/vcd/vcd.h \
    libs/wlf/acc_sc.h \
    libs/wlf/acc_user.h \
    libs/wlf/acc_vhdl.h \
    libs/wlf/mti.h \
    libs/wlf/wlf_api_int.h \
    libs/wlf/wlf_api.h \
    usb/st_usb.h \
    usb/UsbHandler.h \
    usb/UsbDetector.h

FORMS    += signaltap.ui

RESOURCES += \
    signal_tap.qrc

OTHER_FILES += \
    libs/wlf/libwlf_x86.a \
    libs/wlf/libwlf_x86.so

LIBS += -lz

win32: LIBS += -L$$PWD/libs/usb/ -lusb_win_x86

INCLUDEPATH += $$PWD/libs/usb
DEPENDPATH += $$PWD/libs/usb

win32: PRE_TARGETDEPS += $$PWD/libs/usb/libusb_win_x86.a

unix: LIBS += -lz -lusb
