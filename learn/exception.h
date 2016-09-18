#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QObject>
#include <QWidget>
//#include <QException>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <typeinfo>//stl
#include <QMetaEnum>
#include <QStringList>


struct testStruct
{
    int x;
    bool y;
    char z[10];
};

class Exception/* : public QException*/
{
    Q_GADGET
    Q_ENUMS(TestEnum)
    Q_PROPERTY(Qt::Key key_enum)

public:
    enum TestEnum{
        one = 1,
        two,
    };
    Exception(QVariant data)
    {
        qDebug() << data;

        //    TestEnum m_enum;
        //    m_enum = (TestEnum)4;

//        QStringList m_myEnumList;
//        QMetaEnum myEnum = staticMetaObject.enumerator(staticMetaObject.indexOfEnumerator("TestEnum"));
//        for (int i=0; i<myEnum.keyCount(); ++i)
//        {
//            m_myEnumList << myEnum.key(i);
//        }
//        qDebug()<<m_myEnumList;


        int a;

        struct testStruct m_struct = {1, true, "aa"};

        qDebug() << typeid(a).name();
        qDebug() << typeid(m_struct).name();
    }
//    void raise() const { throw *this; }
//    Exception *clone() const { return new Exception(*this); }

};
#endif // EXCEPTION_H
