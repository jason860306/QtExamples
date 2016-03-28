QT += core widgets
QT -= gui

CONFIG += c++11

TARGET = find_dialog
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    finddialog.cpp

HEADERS += \
    finddialog.h
