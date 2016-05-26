#include "widget.h"
#include "mvctest.h"
#include "setupdatetime.h"

#include <QApplication>
#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyleSheet("QTableView::section {selection-background-color:red;}");
    setupdatetime w;
    w.show();

    return a.exec();

}
