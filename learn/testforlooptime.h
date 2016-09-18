#ifndef TESTFORLOOPTIME_H
#define TESTFORLOOPTIME_H

#include <QObject>

class TestForLoopTime : public QObject
{
    Q_OBJECT
public:
    explicit TestForLoopTime(QObject *parent = 0);

    void test();

    void testAllInLoop();
    void testDivaitionLoop();
    void testNullloop();
signals:

public slots:
};


class Test{
public:

    Test()
    {
        int i = 0;
        i++;
        int a = i;
        a--;
    }
};
#endif // TESTFORLOOPTIME_H
