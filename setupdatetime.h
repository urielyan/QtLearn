#ifndef SETUPDATETIME_H
#define SETUPDATETIME_H

#include <QWidget>
#include <QButtonGroup>
#include <QList>
#include <QList>

#include<QLabel>
#include <QDateTime>
namespace Ui {

class setupdatetime;
}

class setupdatetime : public QWidget
{
    Q_OBJECT

public:
    enum ENUM_DATETIME
    {
        YEAR = 0,
        MONTH,
        DAY,
        HOUR,
        MINUTE,
    };
    explicit setupdatetime(QWidget *parent = 0);
  void show_and_refresh();

private slots:
    void on_pushButton_2_clicked();

    void on_p_buttonPlus_clicked();//useless

    void on_p_buttonSub_clicked();//useless

    void slotButtonUpClicked(int id);
    void slotButtonDownClicked(int id);

private:
    Ui::setupdatetime *ui;
    QButtonGroup m_buttonGroupUp, m_buttonGroupDown;
    QList<QLabel*> m_labelList;

    void setLabelCurrentDateTime();
    void examineDayLabelIsRight();
    QString getSetDateTime();
};

class DateTimeFrame : public QFrame
{
    //useless
    Q_OBJECT
public:
    DateTimeFrame(QWidget *parent = 0);
};
#endif // SETUPDATETIME_H
