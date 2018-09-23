// Copyright 2018 Patrick Flynn
//
// Redistribution and use in source and binary forms, with or without modification, 
// are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, 
//	this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this 
//	list of conditions and the following disclaimer in the documentation and/or 
//	other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may 
//	be used to endorse or promote products derived from this software 
//	without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
// IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#include "cellmenu.hh"
#include "../actions/format_actions.hh"
#include "../tabwidget.hh"

CellMenu::CellMenu() {
    this->setTitle("Cells");
    
    merge = new QAction("Merge Cells",this);
    unMerge = new QAction("Unmerge Cells",this);
    insCol = new QAction("Insert Column",this);
    insRow = new QAction("Insert Row",this);
    
    connect(merge,&QAction::triggered,this,&CellMenu::onMergeClicked);
    connect(unMerge,&QAction::triggered,this,&CellMenu::onUnMergeClicked);
    connect(insCol,&QAction::triggered,this,&CellMenu::onInsertCol);
    connect(insRow,&QAction::triggered,this,&CellMenu::onInsertRow);
    
    this->addAction(merge);
    this->addAction(unMerge);
    this->addAction(insCol);
    this->addAction(insRow);
}

CellMenu::~CellMenu() {
    delete merge;
    delete unMerge;
    delete insCol;
    delete insRow;
}

void CellMenu::onMergeClicked() {
    FormatActions::merge();
}

void CellMenu::onUnMergeClicked() {
    FormatActions::unMerge();
}

void CellMenu::onInsertCol() {
    auto current = TabWidget::currentWidget();
    int col = current->currentCell()->column();
    current->currentTable()->insertColumn(col+1);
    current->currentTable()->loadHeaders();
    current->setSaved(false);
}

void CellMenu::onInsertRow() {
    auto current = TabWidget::currentWidget();
    int row = current->currentCell()->row();
    current->currentTable()->insertRow(row+1);
    current->setSaved(false);
}

