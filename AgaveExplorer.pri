include(../AgaveClientInterface/AgaveClientInterface.pri)

INCLUDEPATH += "../AgaveExplorer/"

SOURCES += \
    $$PWD/remoteFileOps/easyboollock.cpp \
    $$PWD/remoteFileOps/fileoperator.cpp \
    $$PWD/remoteFileOps/filetreenode.cpp \
    $$PWD/remoteFileOps/joboperator.cpp \
    $$PWD/utilFuncs/agavesetupdriver.cpp \
    $$PWD/utilFuncs/authform.cpp \
    $$PWD/utilFuncs/copyrightdialog.cpp \
    $$PWD/utilFuncs/singlelinedialog.cpp \
    $$PWD/remoteFileOps/joblistnode.cpp \
    $$PWD/ae_globals.cpp \
    $$PWD/remoteFileOps/filenoderef.cpp \
    $$PWD/remoteModelViews/linkedstandarditem.cpp \
    $$PWD/remoteModelViews/remotefilemodel.cpp \
    $$PWD/remoteModelViews/remotefiletree.cpp \
    $$PWD/remoteModelViews/remotejoblister.cpp \
    $$PWD/remoteModelViews/selectedfilelabel.cpp \
    $$PWD/remoteModelViews/remotefileitem.cpp \
    $$PWD/utilFuncs/fixforssl.cpp \
    $$PWD/SimCenterCommon/FooterWidget.cpp \
    $$PWD/SimCenterCommon/HeaderWidget.cpp

HEADERS += \
    $$PWD/remoteFileOps/easyboollock.h \
    $$PWD/remoteFileOps/fileoperator.h \
    $$PWD/remoteFileOps/filetreenode.h \
    $$PWD/remoteFileOps/joboperator.h \
    $$PWD/utilFuncs/agavesetupdriver.h \
    $$PWD/utilFuncs/authform.h \
    $$PWD/utilFuncs/copyrightdialog.h \
    $$PWD/utilFuncs/singlelinedialog.h \
    $$PWD/remoteFileOps/joblistnode.h \
    $$PWD/ae_globals.h \
    $$PWD/remoteFileOps/filenoderef.h \
    $$PWD/remoteModelViews/linkedstandarditem.h \
    $$PWD/remoteModelViews/remotefilemodel.h \
    $$PWD/remoteModelViews/remotefiletree.h \
    $$PWD/remoteModelViews/remotejoblister.h \
    $$PWD/remoteModelViews/selectedfilelabel.h \
    $$PWD/remoteModelViews/remotefileitem.h \
    $$PWD/utilFuncs/fixforssl.h \
    $$PWD/SimCenterCommon/FooterWidget.h \
    $$PWD/SimCenterCommon/HeaderWidget.h

FORMS += \
    $$PWD/utilFuncs/authform.ui \
    $$PWD/utilFuncs/copyrightdialog.ui \
    $$PWD/utilFuncs/singlelinedialog.ui

win32 {
FORMS += \
    $$PWD/utilFuncs/fixforssl.ui
}

RESOURCES += \
    $$PWD/SimCenterCommon/commonResources.qrc \
