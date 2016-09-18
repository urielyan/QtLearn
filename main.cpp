#include "learn/mvctest.h"
#include "learn/learnqpainter.h"
#include "learn/exception.h"
#include "learn/metaobject.h"
#include "learn/database.h"
#include "learn/syslogstudy.h"

#include "setupdatetime.h"
#include "trendcontextbutton.h"
#include "styleoptionstudy.h"
#include "testforlooptime.h"

#include <QApplication>
#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>

void testQFileResize(){
    throw 1;
    QFile file("./testresize.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
            return;
    file.resize(0);

    file.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyleSheet("QTableView::section {selection-background-color:red;}");

    TestForLoopTime testFroTime;
    testFroTime.test();

    //    setupdatetime w;
//    w.show();

//    LearnQPainter learnPaint;
//    learnPaint.showMaximized();

//    MVCTest mvc;
//    mvc.show();

    DataBase db;
    db.show();
    qDebug()<< "size:" << sizeof(db) << sizeof(testFroTime);
//    WinAbstractTrendContextDialog dialog;
//    dialog.exec();

//    StyleOptionStudy s;
//    s.show();

    try
    {
        testQFileResize();
        MetaObjectNoQObject mNo;
        //throw Exception(1);
        // m;
    }
    catch(int i)
    {
        qDebug() << i;
    }

//    catch (QException e) {
//        qDebug() << "success";
//    }

    return a.exec();

}
