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
#include "graph_menu.hh"
#include "../window.hh"

GraphMenu::GraphMenu() {
    this->setTitle("Graph");

    showGraph = new QAction("Show Graph Designer",this);

    connect(showGraph,&QAction::triggered,this,&GraphMenu::onShowGraph);

    this->addAction(showGraph);
}

GraphMenu::~GraphMenu() {
    delete showGraph;
}

void GraphMenu::onShowGraph() {
    Window::showGraphWin();
}