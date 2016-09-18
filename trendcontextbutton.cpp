#include "trendcontextbutton.h"
void TrendContextModel::indexClicked(QModelIndex index)
{

}

QVariant TrendContextModel::data(const QModelIndex &index, int role) const
{
    QStringList strList;
    strList.clear();
    strList.append("All \n Data");
    strList.append("/home/yange/F270/yg/Image/trend/all_data_d.png");

    return strList;
}

void TrendContextDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int x = option.rect.x();
    int y = option.rect.y();
    int width = option.rect.width();
    int height = option.rect.height();

    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);

    QString text, imagePath;
    QStringList list;
    QPixmap pixmap, sPixmap;
    QPixmap pixmapOn("/home/yange/F270/yg/Image/common/radio_on.png");
    QPixmap pixmapOff("/home/yange/F270/yg/Image/common/radio_off.png");

    list = index.data().toStringList();

    text = list[0];

    imagePath = list[1];

    if (!pixmap.load(imagePath))
        qDebug()<<"image load error";

    sPixmap = pixmap.scaled(112, 112, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter->drawImage(QRect(x, y, width, height * 2 / 5),sPixmap.toImage());

    painter->setPen(Qt::red);
    painter->drawText(x, y + height * 2 / 5, width, height / 4, Qt::AlignHCenter, text);

    painter->drawImage(QRect(x, y + height * 3 / 5, width/5, height/5),pixmapOn.toImage());
    painter->drawText(x + width / 5, y+ height * 3 / 5, width * 4 /5, height/5, Qt::AlignHCenter, "on");


    painter->drawImage(QRect(x, y + height * 4 / 5, width/5, height/5),pixmapOff.toImage());
    painter->drawText(x + width / 5, y+ height * 4 / 5, width * 4 /5, height/5, Qt::AlignHCenter, "Off");

    painter->restore();
}



void TrendContextView::mousePressEvent(QMouseEvent *event)
{
//    QPoint m_point = event->pos();
//    //m_startPoint = m_point;
//    QModelIndex index = indexAt(m_point);
//    QRect rect = visualRect(index);
//    int x = rect.x();
//    int y = rect.y();
//    int width = rect.width();
//    int height = rect.height();



//    m_priIndex = index;

////    qDebug("row:%d   col:%d", index.row(), index.column());

//    if (((m_point.x() >= x + width/8) && (m_point.x() <= x + width*7/8)) &&
//            ((m_point.y() >= y + height/32) && (m_point.y() <= y + height *3/4 + height/32))) {
//        TrendContextModel * model = (TrendContextModel*)this->model();

//        model->setIndexBtnPush(index, true);

//        update(index);
//    }

    QTableView::mousePressEvent(event);
}


QString TrendContextBtnInfo::getBtnImagePath (MenuBtnImageType type) {
    switch (type) {
    case MenuBtnImageType_Normal:
        return m_imagePath;
    case MenuBtnImageType_Push:
        return m_imagePathPush;
    case MenuBtnImageType_Gray:
        return m_imagePathGray;
    default:
        return "";
    }
}

void TrendContextBtnInfo::setBtnImagePath (MenuBtnImageType type, QString path) {
    switch (type) {
    case MenuBtnImageType_Normal:
        m_imagePath = path;
        break;
    case MenuBtnImageType_Push:
        m_imagePathPush = path;
        break;
    case MenuBtnImageType_Gray:
        m_imagePathGray = path;
        break;
    default:
        break;
    }
}

QString TrendContextBtnInfo::getBtnImagePathSwitch(TrendContextBtnInfo::MenuBtnImageType type)
{
    switch (type) {
    case MenuBtnImageType_Normal:
        return m_imagePathSwitch;
    case MenuBtnImageType_Push:
        return m_imagePathPushSwitch;
    case MenuBtnImageType_Gray:
        return m_imagePathGraySwitch;
    default:
        return "";
    }
}

void TrendContextBtnInfo::setBtnImagePathSwitch(TrendContextBtnInfo::MenuBtnImageType type, QString path)
{
    switch (type) {
    case MenuBtnImageType_Normal:
        m_imagePathSwitch = path;
        break;
    case MenuBtnImageType_Push:
        m_imagePathPushSwitch = path;
        break;
    case MenuBtnImageType_Gray:
        m_imagePathGraySwitch = path;
        break;
    default:
        break;
    }
}
