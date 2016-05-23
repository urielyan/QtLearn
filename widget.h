#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAbstractItemView>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

private slots:
    void slotViewClicked(QModelIndex index);
};

class headerView : QAbstractItemView
{

};
#endif // WIDGET_H
