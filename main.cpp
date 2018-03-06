/*********************************************************************************
**
** Copyright (c) 2017 The University of Notre Dame
** Copyright (c) 2017 The Regents of the University of California
**
** Redistribution and use in source and binary forms, with or without modification,
** are permitted provided that the following conditions are met:
**
** 1. Redistributions of source code must retain the above copyright notice, this
** list of conditions and the following disclaimer.
**
** 2. Redistributions in binary form must reproduce the above copyright notice, this
** list of conditions and the following disclaimer in the documentation and/or other
** materials provided with the distribution.
**
** 3. Neither the name of the copyright holder nor the names of its contributors may
** be used to endorse or promote products derived from this software without specific
** prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
** EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
** SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
** TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
** BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
** CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
** IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
** SUCH DAMAGE.
**
***********************************************************************************/

// Contributors:
// Written by Peter Sempolinski, for the Natural Hazard Modeling Laboratory, director: Ahsan Kareem, at Notre Dame

#include <QApplication>
#include <QtGlobal>
#include <QFile>
#include <QSslSocket>

#include "instances/explorerdriver.h"
#include "../AgaveClientInterface/remotedatainterface.h"

void emptyMessageHandler(QtMsgType, const QMessageLogContext &, const QString &){}

int main(int argc, char *argv[])
{
    QApplication mainRunLoop(argc, argv);
    bool debugLoggingEnabled = false;
    bool logRawOutput = false;
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i],"enableDebugLogging") == 0)
        {
            debugLoggingEnabled = true;
        }
        if (strcmp(argv[i],"logRawOutput") == 0)
        {
            logRawOutput = true;
        }
    }

    if (debugLoggingEnabled)
    {
        qDebug("NOTE: Debugging text output is enabled.");
    }
    else
    {
        qInstallMessageHandler(emptyMessageHandler);
    }

    ExplorerDriver programDriver(NULL, debugLoggingEnabled);

    QFile simCenterStyle(":/styleCommon/style.qss");
    if (!simCenterStyle.open(QFile::ReadOnly))
    {
        programDriver.fatalInterfaceError("Missing file for graphics style. Your install is probably corrupted.");
    }
    QString commonStyle = QLatin1String(simCenterStyle.readAll());

    mainRunLoop.setQuitOnLastWindowClosed(false);
    //Note: Window closeing must link to the shutdown sequence, otherwise the app will not close
    //Note: Might consider a better way of implementing this.

    if (QSslSocket::supportsSsl() == false)
    {
        programDriver.fatalInterfaceError("SSL support was not detected on this computer.\nPlease insure that some version of SSL is installed,\n such as by installing OpenSSL.\nInstalling a web browser will probably also work.");
    }

    if (debugLoggingEnabled && logRawOutput)
    {
        qDebug("NOTE: Debugging text including raw remote output.");
        programDriver.getDataConnection()->setRawDebugOutput(true);
    }

    programDriver.startup();
    mainRunLoop.setStyleSheet(commonStyle);
    return mainRunLoop.exec();
}
