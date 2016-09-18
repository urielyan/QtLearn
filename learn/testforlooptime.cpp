#include "testforlooptime.h"

#include <QDebug>
#include <sys/time.h>

#define LOOP_MAX 1000
TestForLoopTime::TestForLoopTime(QObject *parent) : QObject(parent)
{

}

void TestForLoopTime::test()
{
    //测试可知 两个循环大约是一个循环的两倍时间。
    testAllInLoop();

    testDivaitionLoop();

    testNullloop();
}

void TestForLoopTime::testAllInLoop()
{
    struct timeval tpstart,tpend;
    float timeuse;
    gettimeofday(&tpstart,NULL);


    int max;
    for(int i = 0; i < LOOP_MAX; i++)
    {
        if(i / 2 == 0)
        {
            max += i;
        }

        if(i / 2 != 0)
        {
            max -= i;
        }

        int a = 3;
        max += a;
        max -= 3;

    }


    gettimeofday(&tpend,NULL);
    timeuse=(1000000*(tpend.tv_sec-tpstart.tv_sec) + tpend.tv_usec-tpstart.tv_usec)/1000000.0;
    qDebug()<<timeuse<<"s";

}

void TestForLoopTime::testDivaitionLoop()
{
    struct timeval tpstart,tpend;
    float timeuse;
    gettimeofday(&tpstart,NULL);

    int max;
    for(int i = 0; i < LOOP_MAX; i++)
    {
        if(i / 2 == 0)
        {
            max += i;
        }
    }

    for(int i = 0; i < LOOP_MAX; i++)
    {
        if(i / 2 != 0)
        {
            max -= i;
        }
    }

    gettimeofday(&tpend,NULL);
    timeuse=(1000000*(tpend.tv_sec-tpstart.tv_sec) + tpend.tv_usec-tpstart.tv_usec)/1000000.0;
    qDebug()<<timeuse<<"s";

}

void TestForLoopTime::testNullloop()
{
    struct timeval tpstart,tpend;
    float timeuse;
    gettimeofday(&tpstart,NULL);

    for(int i = 0; i < LOOP_MAX; i++)
    {
//        int a =0;
//        int b = 3;
//        int add = a + b;
//        add -= 2;
        Test *test = new Test;
        delete test;
    }

    gettimeofday(&tpend,NULL);
    timeuse=(1000000*(tpend.tv_sec-tpstart.tv_sec) + tpend.tv_usec-tpstart.tv_usec)/1000000.0;
    qDebug() << __FUNCTION__ << timeuse << "s";
}

