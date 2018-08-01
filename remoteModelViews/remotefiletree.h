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

#ifndef REMOTEFILEWINDOW_H
#define REMOTEFILEWINDOW_H

#include <QTreeView>
#include <QStandardItem>

#include "../AgaveExplorer/remoteFileOps/filenoderef.h"

//NOTE: FILENAME MUST == 0 for these functions to work.
//The other columns can be changed
enum class FileColumn : int {FILENAME = 0,
                             TYPE = 1,
                             SIZE = 2,
                             LAST_CHANGED = 3,
                             FORMAT = 4,
                             MIME_TYPE = 5,
                             PERMISSIONS = 6};

class RemoteFileItem;
class RemoteFileModel;
enum class RequestState;

class RemoteFileTree : public QTreeView
{
    Q_OBJECT

public:
    explicit RemoteFileTree(QWidget *parent = nullptr);

    FileNodeRef getSelectedFile();
    void selectRowByFile(FileNodeRef toSelect);
    void setModelLink(RemoteFileModel * theModel);

signals:
    void newFileSelected(FileNodeRef newFileData);

public slots:
    void fileEntryTouched(QModelIndex itemTouched);
    void forceSelectionRefresh();

private slots:
    void folderExpanded(QModelIndex itemOpened);

private:
    void selectRowByItem(QStandardItem *linkedItem);

    RemoteFileModel * myModel = nullptr;
};

#endif // REMOTEFILEWINDOW_H
