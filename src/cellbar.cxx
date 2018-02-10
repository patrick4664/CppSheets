#include <QMenu>
#include <QAction>
#include <QColorDialog>

#include "cellbar.hh"
#include "tabwidget.hh"

CellBar::CellBar()
    : cellColor(new QToolButton),
      merge(new QToolButton),
      unmerge(new QToolButton)
{
    QMenu *colorMenu = new QMenu;
    QAction *bg = new QAction("Background",colorMenu);
    QAction *fg = new QAction("Text",colorMenu);
    colorMenu->addAction(bg);
    colorMenu->addAction(fg);

    cellColor->setPopupMode(QToolButton::InstantPopup);
    cellColor->setMenu(colorMenu);

    cellColor->setText("Color");
    merge->setText("Merge Cells");
    unmerge->setText("Unmerge Cells");

    this->addWidget(cellColor);
    this->addWidget(merge);
    this->addWidget(unmerge);

    connect(bg,&QAction::triggered,this,&CellBar::onBgColorClicked);
    connect(fg,&QAction::triggered,this,&CellBar::onFgColorClicked);
    connect(merge,&QToolButton::clicked,this,&CellBar::onMergeClicked);
    connect(unmerge,&QToolButton::clicked,this,&CellBar::onUnMergeClicked);
}

CellBar::~CellBar() {
    delete cellColor;
    delete merge;
}

void CellBar::onBgColorClicked() {
    QColor color = QColorDialog::getColor();
    TabWidget::currentWidget()->currentCell()->setBackgroundColor(color);
}

void CellBar::onFgColorClicked() {
    QColor color = QColorDialog::getColor(Qt::black);
    TabWidget::currentWidget()->currentCell()->setTextColor(color);
}

void CellBar::onMergeClicked() {
    TabWidget::currentWidget()->mergeSelected();
}

void CellBar::onUnMergeClicked() {
    TabWidget::currentWidget()->unMergeSelected();
}