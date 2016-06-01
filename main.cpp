#include "widget.h"
#include "learn/mvctest.h"
#include "learn/learnqpainter.h"
#include "setupdatetime.h"

#include <QApplication>
#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyleSheet("QTableView::section {selection-background-color:red;}");

//    setupdatetime w;
//    w.show();

    LearnQPainter learnPaint;
    learnPaint.showMaximized();

//    MVCTest mvc;
//    mvc.show();

    return a.exec();

}
