#include "customscrollbar.h"
#include "mvctest.h"
#include "../trendcontextbutton.h"

#include <QRadioButton>
#include <QToolButton>

MVCTest::MVCTest(QWidget *parent)
    :QWidget(parent)
{
    QTableView *p_tableview;
    p_tableview = new QTableView;
    p_tableview->setObjectName("h");
    initView(p_tableview);
    initQStandardItemModel(p_tableview);
    //initQFileSystemModel(p_tableview);

    //connect(p_tableview, SIGNAL(clicked(QModelIndex)), this, SLOT(slotViewClicked(QModelIndex)));

    //p_tableview->setStyleSheet("QTableCornerButton::section {background: red;border: 2px outset red;}");
    //p_tableview->horizontalHeader()->setStyleSheet("QTableView::item{selection-background-color:red;}");
    //this->setStyleSheet("#h {selection-background-color: qlineargradient(x1: 0, y1: 0, x2: 0.5, y2: 0.5,stop: 0 #FF92BB, stop: 1 white);}");
    initLayout(p_tableview);

    QItemDelegate *p_d = new SpinBoxDelegate();
    p_tableview->setItemDelegateForRow(0,p_d);

    this->setStyleSheet("QScrollBar:vertical {"\
                        "width: 36px;"\
                        "background:rgba(0,0,0,10%);"\
                        "margin:0px,0px,0px,0px;"\
                        "padding-top:0px;   "\
                        "padding-bottom:0px;}"\
                        "QScrollBar::handle:vertical {"\
                        "background: rgba(1,26,134,80%);"\
                        "min-height: 20px;"\
                        "min-width: 4px;}"\
                        "QScrollBar::down-button,QScrollBar::up-button{background:rgba(255, 255, 255, 255); width:36px;height:50px;margin:0px,0px,0px,0px;padding:0px;border:0px;"
                        "border-radius:4px;"
                        "}"
                        "QTableView::item:selected{background: red;}"
                        "QTableView{selection-background-color:red;}");

}

void MVCTest::initLayout(QTableView *p_tableview)
{
    QVBoxLayout *p_layout_main = new QVBoxLayout(this);

    p_layout_main->addWidget(p_tableview);

    this->setFixedSize(800, 600);
}

void MVCTest::initView(QTableView *p_tableview)
{
    //QHeaderView *p_horizontalHeader = new QHeaderView(Qt::Horizontal, this);
    p_tableview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置垂直滚动条显示模式
    p_tableview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置水平滚动条显示模式
    p_tableview->setSelectionBehavior(QAbstractItemView::SelectRows); //设置选择行为时每次选择一行
    p_tableview->setSelectionMode(QAbstractItemView::SingleSelection);//设置选择模式：单选、多选、等
    p_tableview->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    p_tableview->setSortingEnabled(true);//设置可以排序:call to sortByColumn() with the current sort section and order.
   // p_tableview->setGridStyle(Qt::SolidLine);
    p_tableview->setShowGrid(false); //设置不显示格子线
    //p_tableview->setFrameShape(QFrame::NoFrame); //设置无边框

    //p_tableview->verticalHeader()->setFrameStyle(QFrame::VLine | QFrame::Raised);
    //p_tableview->verticalHeader()->setVisible(false); //设置垂直头不可见
    p_tableview->verticalHeader()->setDefaultSectionSize(140); //设置行高

    p_tableview->horizontalHeader()->setSectionHidden(1, true);//TODO: useless,隐藏列
    p_tableview->horizontalHeader()->setFrameShape(QFrame::NoFrame);//TODO:
    //p_tableview->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //p_tableview->horizontalHeader()->setDefaultAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    p_tableview->horizontalHeader()->setHighlightSections(false);
    p_tableview->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
    p_tableview->horizontalHeader()->resizeSection(0,50); //TODO: useless,设置表头第一列的宽度为150//
    //p_tableview->horizontalHeader()->setFixedWidth(900);

    p_tableview->setVerticalScrollBar(new CustomScrollBar(p_tableview));

}

QAbstractItemModel *MVCTest::initQStandardItemModel(QTableView *p_tableview)
{
    QStandardItemModel * m = new QStandardItemModel(this);
    for (int i = 0; i < 30; i++)
    {
        QStandardItem *item1 = new QStandardItem(QString::number(i) + "1111");
        m->setItem(i, 0, item1);
        QStandardItem *item2 = new QStandardItem(QString::number(i) + "2222");
        m->setItem(i, 1, item2);
    }
    p_tableview->setModel(m);
    m->setHorizontalHeaderItem(0,new QStandardItem("1"));
    m->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignHCenter);

    return m;

}

QAbstractItemModel *MVCTest::initQFileSystemModel(QTableView *p_tableview)
{
    QFileSystemModel *m = new QFileSystemModel(this);

    m->setRootPath(".");
    p_tableview->setModel(m);
    p_tableview->setRootIndex(m->index("."));

    m->setHeaderData(0, Qt::Vertical, tr("File name"));
    m->setHeaderData(1, Qt::Horizontal, tr("File name"));
    return m;
}



QWidget *SpinBoxDelegate::createEditor(QWidget *parent,
     const QStyleOptionViewItem &/* option */,
     const QModelIndex &/* index */) const
 {
     QSpinBox *editor = new QSpinBox(parent);
     editor->setMinimum(0);
     editor->setMaximum(100);

     return editor;
 }
void SpinBoxDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const
 {
     int value = index.model()->data(index, Qt::DisplayRole).toInt();

     QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
     spinBox->setValue(value);
 }
void SpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
 {
     QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
     spinBox->interpretText();
     int value = spinBox->value();

     model->setData(index, value);
 }
void SpinBoxDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    editor->setGeometry(option.rect);
}

#include <QApplication>
#include <QStyleOptionButton>
void SpinBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QColor backGroundColor = QColor(0,187,255);

    if(option.state  & QStyle::State_Selected)
    {
        QBrush brush(backGroundColor);
        painter->setBrush(brush);
        QRect rect = option.rect;
        rect.setX(rect.x() - 1);
        rect.setY(rect.y() - 1);
        rect.setWidth(rect.width() + 2);
        rect.setHeight(rect.height() + 2);

        painter->drawRect(rect);
        painter->setPen(backGroundColor);
        painter->drawLine(option.rect.topRight().x() + 1, option.rect.topRight().y(),
                          option.rect.bottomRight().x() + 1, option.rect.bottomRight().y());
    }
    painter->setPen("black");
    painter->drawText(option.rect, Qt::AlignCenter|Qt::AlignLeft, index.data().toString());//在index中的矩形框下画一个当前时间文字。
    painter->setPen(backGroundColor);
//    QStyleOptionButton radio_box_style_option;
//    radio_box_style_option.rect = option.rect;
    //    QApplication::style()->drawControl(QStyle::CE_RadioButton,&radio_box_style_option,painter);
}
