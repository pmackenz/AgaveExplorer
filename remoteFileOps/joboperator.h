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

#ifndef JOBOPERATOR_H
#define JOBOPERATOR_H

#include "../AgaveClientInterface/remotejobdata.h"

#include <QObject>
#include <QMap>
#include <QStandardItemModel>
#include <QTimer>

class RemoteFileWindow;
class RemoteDataInterface;
class RemoteJobLister;
class JobListNode;
class RemoteDataReply;

enum class RequestState;

class JobOperator : public QObject
{
    Q_OBJECT
public:
    explicit JobOperator(QObject * parent);
    ~JobOperator();
    void linkToJobLister(RemoteJobLister * newLister);

    QMap<QString, const RemoteJobData *> getJobsList();

    void requestJobDetails(const RemoteJobData *toFetch);
    void underlyingJobChanged();

    const RemoteJobData * findJobByID(QString idToFind);

signals:
    void newJobData();

public slots:
    void demandJobDataRefresh();

private slots:
    void refreshRunningJobList(RequestState replyState, QList<RemoteJobData> theData);

private:
    static bool listHasJobId(QList<RemoteJobData> theData, QString toFind);

    QMap<QString, JobListNode *> jobData;
    RemoteDataReply * currentJobReply = NULL;

    QStandardItemModel theJobList;
};

#endif // JOBOPERATOR_H
