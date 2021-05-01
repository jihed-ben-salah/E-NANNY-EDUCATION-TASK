#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql network multimedia charts serialport multimediawidgets printsupport  network




greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    accueil.cpp \
    arduino.cpp \
    barchart.cpp \
    dialog1.cpp \
    education.cpp \
        main.cpp \
    connection.cpp \
    mainwindow1.cpp \
    motcle.cpp \
    personned_aides.cpp \
    reclamation.cpp \
    secu.cpp \
    smtp.cpp \
   activite.cpp\
   cours1.cpp\
  devoirs.cpp\
  qcustomplot.cpp\
 timeclass.cpp

HEADERS += \
    accueil.h \
    arduino.h \
    dialog1.h \
    connection.h \
    education.h \
    mainwindow1.h \
    motcle.h \
    personned_aides.h \
    reclamation.h \
    secu.h \
    smtp.h \
   activite.h\
   cours1.h\
   devoirs.h\
   qcustomplot.h\
    timeclass.h

FORMS += \
        accueil.ui \
        dialog1.ui \
        education.ui \
        mainwindow1.ui \
        secu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
RC_ICONS = img/logo.ico
QMAKE_CXXFLAGS += -std=gnu++14
RESOURCES += \
    resource.qrc
