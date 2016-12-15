#include "learn/mvctest.h"
#include "learn/learnqpainter.h"
#include "learn/exception.h"
#include "learn/metaobject.h"
#include "learn/database.h"
#include "learn/syslogstudy.h"

#include "setupdatetime.h"
#include "trendcontextbutton.h"

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

    MVCTest db;
    db.show();

    try
    {
        testQFileResize();
    }
    catch(int i)
    {
        qDebug() << i;
    }

    return a.exec();

}
