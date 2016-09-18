#include "database.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QHeaderView>
#include <QScrollBar>
#include <QApplication>
#include <QDesktopWidget>

DataBase::DataBase()
{
    if(connectDataBase("QSQLITE", "test.db"))
    {
        initSqlRelationTableModel();
    }
    initView();

    initLayout();
    this->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
    //this->setGeometry(0, 0, QApplication::desktop()->width(),QApplication::desktop()->height());
}

bool DataBase::connectDataBase(QString driver, QString name)
{
    if(QSqlDatabase::isDriverAvailable(driver))
    {
        m_sqlDatabase = QSqlDatabase::addDatabase(driver, name);
        m_sqlDatabase.setDatabaseName(name);
    }else
    {
        qDebug() <<  "Not addDatabase:" << m_sqlDatabase.lastError().text();
        return false;
    }

    if(!m_sqlDatabase.open())
    {
        qDebug() << "Not Open:" << m_sqlDatabase.lastError().text();
        return false;
    }
    qDebug() << m_sqlDatabase.tables();

    return true;
}

void DataBase::initView()
{
    p_Tableview = new QTableView(this);
    p_Tableview->setModel(p_SqlRelationTableModel);
    p_Tableview->setItemDelegate(new QSqlRelationalDelegate(p_Tableview));//提供了一种用于编辑外键的方式
    //QHeaderView *p_horizontalHeader = new QHeaderView(Qt::Horizontal, this);
    p_Tableview->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置垂直滚动条显示模式
    p_Tableview->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);//设置水平滚动条显示模式
    //p_Tableview->setSelectionBehavior(QAbstractItemView::SelectRows); //设置选择行为时每次选择一行
    p_Tableview->setSelectionMode(QAbstractItemView::SingleSelection);//设置选择模式：单选、多选、等
    //p_Tableview->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可编辑
    p_Tableview->setSortingEnabled(true);//设置可以排序:call to sortByColumn() with the current sort section and order.
    p_Tableview->sortByColumn(0, Qt::AscendingOrder);
   // m_view->setGridStyle(Qt::SolidLine);
    p_Tableview->setShowGrid(false); //设置不显示格子线
    //m_view->setFrameShape(QFrame::NoFrame); //设置无边框

    //m_view->verticalHeader()->setFrameStyle(QFrame::VLine | QFrame::Raised);
    //m_view->verticalHeader()->setVisible(false); //设置垂直头不可见
    p_Tableview->verticalHeader()->setDefaultSectionSize(40); //设置行高

    //p_view->horizontalHeader()->setSectionHidden(1, true);//TODO: useless,隐藏列
    p_Tableview->horizontalHeader()->setFrameShape(QFrame::NoFrame);//TODO:
    //m_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //m_view->horizontalHeader()->setDefaultAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    p_Tableview->horizontalHeader()->setHighlightSections(false);
    p_Tableview->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
    //p_Tableview->horizontalHeader()->resizeSection(0,100); //TODO: useless,设置表头第一列的宽度为150//
    //m_view->horizontalHeader()->setFixedWidth(900);


    p_Tableview->horizontalHeader()->setStyleSheet("QHeaderView{"
                                                   "text-align:left center;"
                                                   "}"
                                                   "QHeaderView::section {"
                                                   "height: 40px;"
                                                   "background-color: rgb(250, 250, 250);"
                                                   "color: black;"
                                                   "padding-left: 4px;"
                                                   "border: 1px solid rgb(235, 235, 235);"
                                                   "}"); //设置表头背景色

    //m_view->setStyleSheet("QTableView{selection-background-color:red;}"); //设置选中背景色


    p_Tableview->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:30px;}"
      "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
      "QScrollBar::handle:hover{background:gray;}"
      "QScrollBar::sub-line{background:red;}"
      "QScrollBar::add-line{background:transparent;}");

      p_Tableview->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 30px;}"
      "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
      "QScrollBar::handle:hover{background:gray;}"
      "QScrollBar::sub-line{background:red;}"
                                                 "QScrollBar::add-line{background:red;}");
}

void DataBase::initSqlTableModel()
{
    p_SqlTableModel = new QSqlTableModel(this, m_sqlDatabase);
    p_SqlTableModel->setTable("employee");
    p_SqlTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    p_SqlTableModel->select();
    p_SqlTableModel->setFilter("name!=11");
    p_SqlTableModel->setHeaderData(0, Qt::Horizontal, tr("ID"));
    p_SqlTableModel->setHeaderData(1, Qt::Horizontal, tr("Name"));
    p_SqlTableModel->setHeaderData(2, Qt::Horizontal, tr("Name"));
}

void DataBase::initSqlRelationTableModel()
{
    p_SqlRelationTableModel = new QSqlRelationalTableModel(this, m_sqlDatabase);
    p_SqlRelationTableModel->setTable("people");

    p_SqlRelationTableModel->setRelation(1, QSqlRelation("employee","id", "id"));//三个字符串：第一个是表名，第二个是外键名，第三个是要显示的列名。

    p_SqlRelationTableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    p_SqlRelationTableModel->select();
//    p_SqlRelationTableModel->setHeaderData(0, Qt::Horizontal, tr("identification"));
//    p_SqlRelationTableModel->setHeaderData(1, Qt::Horizontal, tr("companyId"));
//    p_SqlRelationTableModel->setHeaderData(2, Qt::Horizontal, tr("name"));
}

void DataBase::initLayout()
{
    this->setLayout(&m_mainStackedLayout);
    m_mainStackedLayout.addWidget(p_Tableview);
}

