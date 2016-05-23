#include "widget.h"
#include "ui_widget.h"
#include <QFrame>
#include <qframe.h>
#include <QHeaderView>

#include <QFileSystemModel>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QPushButton>
#include <QLabel>
#include <QScrollBar>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);


    this->showMaximized();

    QLabel *p_button = new QLabel("dadadadadadadadadadadadadadadadadadadadadadadadadadada", this);
    p_button->setObjectName("1");
    this->ui->gridLayout->addWidget(p_button);
    p_button->setFrameStyle(QFrame::VLine | QFrame::Raised);

    QLabel *p_button2 = new QLabel("dadadadadadadadada", this);
    p_button2->setObjectName("2");
    p_button2->setFixedWidth(100);
    this->ui->gridLayout->addWidget(p_button2);
    p_button2->setFrameStyle(QFrame::VLine | QFrame::Raised);

    QPushButton *p_button3 = new QPushButton("dadadadadadadadada", this);
    p_button3->setObjectName("2");
    p_button3->setFixedWidth(100);
    this->ui->gridLayout->addWidget(p_button3);

    //ui->tableView->hide();
    this->setStyleSheet("QComboBox {"
                        "font: 30px;"
                        "}"
                        "QComboBox QAbstractItemView {"
                        "border: 2px solid darkgray;"
                        "selection-background-color: lightgray;"
                        "}"
                        "QComboBox:on {"
                        "padding-top: 3px;"
                        "padding-left: 4px;"
                        "}"
                        "QLabel#1,QLabel#2{"
                        "background-color:blue;"
                        "}"
                        );

}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotViewClicked(QModelIndex index)
{
}
