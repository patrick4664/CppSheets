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

#include <QMenu>
#include <QAction>

class FormatMenu : public QMenu {
    Q_OBJECT
public:
    FormatMenu();
    ~FormatMenu();
private:
    QAction *bold, *italic, *underline;
    QMenu *colorMenu;
    QAction *bg, *fg, *border;
    QAction *setFont;
private slots:
    void onBoldClicked();
    void onItalicClicked();
    void onUnderlineClicked();
    void onBgColorClicked();
    void onFgColorClicked();
    void onBorderClicked();
    void onSetFontClicked();
};
