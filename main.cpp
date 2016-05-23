#include "widget.h"
#include "mvctest.h"
#include "setupdatetime.h"

#include <QApplication>
#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>
int main(int argc, char *argv[])
{

//    QApplication app(argc, argv);
//    QWidget *win = new QWidget;

//    QLabel *label = new QLabel("Box");
//    QLabel *label1 = new QLabel("Panel");
//    QLabel *label2 = new QLabel("Winpanel");
//    QLabel *label3 = new QLabel("H line");
//    QLabel *label4 = new QLabel("V line");
//    QLabel *label5 = new QLabel("Styled Panel");

//    label->setFrameStyle(QFrame::Box | QFrame::Raised);
//    label->setLineWidth(2);
//    label1->setFrameStyle(QFrame::Panel | QFrame::Raised);
//    label1->setLineWidth(2);
//    label2->setFrameStyle(QFrame::WinPanel | QFrame::Raised);
//    label2->setLineWidth(2);
//    label3->setFrameStyle(QFrame::HLine | QFrame::Raised);
//    label3->setLineWidth(2);
//    label4->setFrameStyle(QFrame::VLine | QFrame::Raised);
//    label4->setLineWidth(2);
//    label5->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
//    label5->setLineWidth(2);

//    QVBoxLayout *layout = new QVBoxLayout;
//    layout->addWidget(label);
//    layout->addWidget(label1);
//    layout->addWidget(label2);
//    layout->addWidget(label3);
//    layout->addWidget(label4);
//    layout->addWidget(label5);
//    win->setLayout(layout);
//    win->showMaximized();
//    return app.exec();

    QApplication a(argc, argv);

    a.setStyleSheet("QTableView::section {selection-background-color:red;}");
    MVCTest w;
    w.show();

    return a.exec();

}
