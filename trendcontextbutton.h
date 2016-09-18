#ifndef TRENDCONTEXTBUTTON_H
#define TRENDCONTEXTBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QFileSystemModel>
#include <QScrollBar>
#include <QItemDelegate>
#include <QPainter>
#include <QDialog>
#include <QDebug>

typedef enum _MenuItemID {
    MenuItemID_Quit = 0,
    MenuItemID_DataSearch,
    MenuItemID_AllDataDisplay,
    MenuItemID_Message,
    MenuItemID_FreeMessage,

}MenuItemID;

class TrendContextBtnInfo : public QObject {
    Q_OBJECT
public:
    TrendContextBtnInfo(QObject *parent = 0) : QObject(parent)
    {
        m_push = false;
        m_gray = false;
    }
    ~TrendContextBtnInfo(){}

    typedef enum _MenuBtnImageType {
        MenuBtnImageType_Normal = 0,
        MenuBtnImageType_Push,
        MenuBtnImageType_Gray,
    } MenuBtnImageType;

    MenuItemID getBtnID() {return m_btnId;}
    void setBtnID(MenuItemID id) {m_btnId = id;}

    bool getBtnStatus() {return m_status;}
    void setBtnStatus(bool status) {m_status = status;}

    QString getBtnImagePath (MenuBtnImageType type);
    void setBtnImagePath (MenuBtnImageType type, QString path);

    QString getBtnImagePathSwitch (MenuBtnImageType type);
    void setBtnImagePathSwitch (MenuBtnImageType type, QString path);

    QString getBtnText() {return m_text;}
    void setBtnText(QString text) {m_text = text;}

    QString getBtnTextSwitch() {return m_textSwitch;}
    void setBtnTexSwitcht(QString text) {m_textSwitch = text;}

    bool getBtnGray() {return m_gray;}
    void setBtnGray(bool gray) {m_gray = gray;}

    bool getBtnPush() {return m_push;}
    void setBtnPush(bool push) {m_push = push;}

    bool getBtnSwitchFlag() {return m_switch;}
    void setBtnSwitchFlag(bool switchFlag) {m_switch = switchFlag;}

private:
    bool m_status;//显示/隐藏
    MenuItemID m_btnId;
    QString m_imagePath, m_imagePathPush, m_imagePathGray;
    QString m_imagePathSwitch, m_imagePathPushSwitch, m_imagePathGraySwitch;
    QString m_text, m_textSwitch;

    bool m_push,m_gray;
    bool m_switch;

};
class TrendContextModel : public QAbstractTableModel
{
public:
    TrendContextModel() : QAbstractTableModel(){}
    //int getDataSize() {return m_btnList.size();}

    void indexClicked(QModelIndex index);

private:
    int columnCount(const QModelIndex &parent = QModelIndex()) const{return 1;}
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const{return 1;}

private slots:
    //void slotUpdataModel();

private:
};

class TrendContextView : public QTableView {
public:
    TrendContextView(QWidget *parent = 0) : QTableView(parent){
        this->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
        this->verticalHeader()->setMinimumHeight(200);
    }

private:
    void mousePressEvent(QMouseEvent *event);
//    void mouseReleaseEvent(QMouseEvent *event);
//    void mouseMoveEvent(QMouseEvent *event);
};

class TrendContextDelegate : public QAbstractItemDelegate {
public:
    TrendContextDelegate(QObject *parent = 0) : QAbstractItemDelegate(parent){/*p_view = (QTableView*)parent;*/}

    virtual void	paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;

    virtual QSize	sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const
    {
        return option.rect.size();
    }

private:

    QTableView *p_view;
};

class WinAbstractTrendContextDialog : public QDialog
{
public:
    explicit WinAbstractTrendContextDialog() : QDialog()
    {
        p_model = new TrendContextModel();
        p_tableView =  new TrendContextView();
        p_delegate = new TrendContextDelegate();

        p_tableView->setModel(p_model);
        p_tableView->setItemDelegate(p_delegate);

        this->setLayout(&m_vLavout);
        m_vLavout.addWidget(p_tableView);
    }

private:
    TrendContextModel *p_model;
    TrendContextView *p_tableView;
    TrendContextDelegate *p_delegate;

    QVBoxLayout m_vLavout;
};

#endif // TRENDCONTEXTBUTTON_H
