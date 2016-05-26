#ifndef MVCTEST_H
#define MVCTEST_H

#include<QDebug>
#include <QObject>
#include <QWidget>
#include <QFrame>
#include <QDialog>
#include <QVBoxLayout>
#include <QSpinBox>

#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QFileSystemModel>
#include <QScrollBar>
#include <QItemDelegate>

class MVCTest :public QWidget
{
public:
    MVCTest(QWidget *parent = 0);

private:
    void initLayout(QTableView *p_tableview);

    void initView(QTableView *p_tableview);
    QAbstractItemModel* initQStandardItemModel(QTableView *p_tableview);
    QAbstractItemModel* initQFileSystemModel(QTableView *p_tableview);
};

class SpinBoxDelegate : public QItemDelegate
 {
 public:
     SpinBoxDelegate(QObject *parent = 0);

     QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const;

     void setEditorData(QWidget *editor, const QModelIndex &index) const;
     void setModelData(QWidget *editor, QAbstractItemModel *model,
                       const QModelIndex &index) const;

     void updateEditorGeometry(QWidget *editor,
         const QStyleOptionViewItem &option, const QModelIndex &index) const;

//      void	paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
//      QSize	sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const;
 };
#endif // MVCTEST_H
