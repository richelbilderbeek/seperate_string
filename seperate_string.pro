TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
  main_test.cpp \
  seperate_string.cpp \
  seperate_string_test.cpp

HEADERS += \
  seperate_string.h

# Boost.Test
LIBS += -lboost_unit_test_framework

