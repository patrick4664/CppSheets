// This file is part of CppSheets.
//
// Copyright 2018 Patrick Flynn <patrick_dev2000@outlook.com>
//
// CppSheets is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// CppSheets is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with CppSheets. If not, see <https://www.gnu.org/licenses/>.
#pragma once

#include <QDialog>
#include <QVBoxLayout>
#include <QListWidget>

class GraphListDialog : public QDialog {
    Q_OBJECT
public:
    GraphListDialog();
    ~GraphListDialog();
private:
    QVBoxLayout *layout;
    QListWidget *graphs;
private slots:
    void onDoubleClick(QListWidgetItem *item);
};
