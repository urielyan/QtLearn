#ifndef METAOBJECT_H
#define METAOBJECT_H

#include <QObject>
#include <QDebug>
#include <QMetaEnum>
#include <QStringList>


class MetaObject : public QObject
{
    Q_OBJECT
    Q_ENUMS(TestEnum)

public:
    enum TestEnum{
        one = 1,
        two,
    };
    explicit MetaObject(QObject *parent = 0) : QObject(parent)
    {
        //TestEnum m_enum;
        //m_enum = (TestEnum)4;

        //Q_ENUM(TestEnum)

        int index = metaObject()->indexOfEnumerator("TestEnum");
        QMetaEnum myEnum = metaObject()->enumerator(index);
        QStringList m_myEnumList;
        for (int i=0; i<myEnum.keyCount(); ++i)
        {
            m_myEnumList << myEnum.key(i);
        }
        qDebug()<<m_myEnumList;

        throw m_myEnumList.size();




        //qDebug() << (typeid(m_enum).name() == typeid(TestEnum).name()) << ;

    }

signals:

public slots:
};

class MetaObjectNoQObject{
    Q_GADGET
    Q_PROPERTY(Qt::Key key_enum)
   public:
    enum EnumTest{one, two};

    Qt::Key key_enum;
    Q_ENUMS(EnumTest)
    explicit MetaObjectNoQObject()
    {
        typedef enum EnumTest currentEnum;
        const QMetaObject &mo = staticMetaObject;
        int prop_index = mo.indexOfProperty("EnumTest");
        QMetaProperty metaProperty = mo.property(prop_index);
        QMetaEnum metaEnum = metaProperty.enumerator();
        qDebug() << "MetaObjectNoQObject:" << metaEnum.name();

        QMetaEnum myEnum = staticMetaObject.enumerator(prop_index);
        QStringList m_myEnumList;
        for (int i=0; i<myEnum.keyCount(); ++i)
        {
            m_myEnumList << myEnum.key(i);
        }
        qDebug()<<m_myEnumList;

        qDebug()<< "size:" << m_myEnumList.size();
    }
};
#endif // METAOBJECT_H
