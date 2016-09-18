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
#include <QPainter>

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
    SpinBoxDelegate(QObject *parent = 0): QItemDelegate(parent){}

     QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const;

     void setEditorData(QWidget *editor, const QModelIndex &index) const;
     void setModelData(QWidget *editor, QAbstractItemModel *model,
                       const QModelIndex &index) const;

     void updateEditorGeometry(QWidget *editor,
         const QStyleOptionViewItem &option, const QModelIndex &index) const;
     //1.重新实现下列虚函数：（注意函数后面的const关键字不要忘掉）
     /*创建自己要显示的控件 QWidget类*/
     //virtual QWidget * createEditor ( QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
     /*绘制View显示的item的属性,paint() 函数会被每一个item独立调用，而sizeHint()函数则可以定义每一个item 的大小*/
     virtual void	paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
     /*给控件赋值函数*/
     //virtual void	setEditorData ( QWidget * editor, const QModelIndex & index ) const;
     /*编辑完成，将控件值付给model的函数*/
    // virtual void	setModelData ( QWidget * editor, QAbstractItemModel * model, const QModelIndex & index ) const;
     /*返回合适的大小*/
     //virtual QSize	sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const{}
     /*更新显示控件的位置大小*/
     //virtual void updateEditorGeometry ( QWidget * editor, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
 };


#endif // MVCTEST_H
