#include "customscrollbar.h"

#include <QApplication>
#include <QPaintEvent>
#include <QPainter>
#include <QStyle>
#include <QStyleOptionButton>
#include <QPixmapCache>
#include <QDebug>

scrollBarStyle::scrollBarStyle(QObject *parent)
    : QProxyStyle()
{
   setParent(parent);
}

QPixmap cached(const QString &img)
{
    if (QPixmap *p = QPixmapCache::find(img))
        return *p;

    QPixmap pm;
    pm = QPixmap::fromImage(QImage(img), Qt::OrderedDither | Qt::OrderedAlphaDither);
    if (pm.isNull())
        return QPixmap();

    QPixmapCache::insert(img, pm);
    return pm;
}

#ifdef DrawComplexControl
void scrollBarStyle::drawComplexControl(QStyle::ComplexControl control, const QStyleOptionComplex *option, QPainter *painter, const QWidget *widget) const
{
    if (control == CC_ScrollBar)
    {
        if (const QStyleOptionSlider *slider = qstyleoption_cast<const QStyleOptionSlider *>(option))
        {
                    QRect groove = subControlRect(CC_Slider, option, SC_SliderGroove, widget);
                    QRect handle = subControlRect(CC_Slider, option, SC_SliderHandle, widget);

                    painter->save();

//                    bool hover = (slider->state & State_Enabled) && (slider->state & State_MouseOver);
//                    if (hover)
//                    {
//                        QRect moderated = widget->rect().adjusted(0, 4, 0, -4);
//                        drawHoverRect(painter, moderated);
//                    }

                    if ((option->subControls & SC_SliderGroove) && groove.isValid())
                    {
                        painter->save();
                        painter->setBrush(QColor("red"));
                        painter->drawRect(groove);
                        painter->restore();

                        //proxy()->drawPrimitive();

//                        QPixmap grv = cached("/home/yange/bar.png");
//                        painter->drawPixmap(QRect(groove.x() + 5, groove.y(),
//                                                  groove.width() - 10, grv.height()),
//                                            grv);
                    }
                    if ((option->subControls & SC_SliderHandle) && handle.isValid())
                    {

                        painter->save();
                        painter->setBrush(QColor("yellow"));
                        painter->drawRect(handle);
                        painter->restore();

//                        QPixmap hndl = cached("/home/yange/handle.png");
//                        painter->drawPixmap(handle.topLeft(), hndl);
                    }

                    painter->restore();
                }
    }
    else
    {
        QProxyStyle::drawComplexControl(control, option, painter, widget);
    }
}
#endif

void scrollBarStyle::drawPrimitive(QStyle::PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    qDebug() << element;

    return         QProxyStyle::drawPrimitive(element, option, painter, widget);
}

void scrollBarStyle::drawControl(QStyle::ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    qDebug() << element;

    return         QProxyStyle::drawControl(element, option, painter, widget);
}

void scrollBarStyle::drawHoverRect(QPainter *painter, const QRect &r) const
{
    qreal h = r.height();
    qreal h2 = r.height() / qreal(2);
    QPainterPath path;
    path.addRect(r.x() + h2, r.y() + 0, r.width() - h2 * 2, r.height());
    path.addEllipse(r.x(), r.y(), h, h);
    path.addEllipse(r.x() + r.width() - h, r.y(), h, h);
    path.setFillRule(Qt::WindingFill);
    painter->setPen(Qt::NoPen);
    painter->setBrush(QColor(191, 215, 191));
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPath(path);
}

CustomScrollBar::CustomScrollBar(QWidget *parent)
    : QScrollBar(parent)
    , m_lineHeight(10)
    , m_handleheight(20)
{
}

void CustomScrollBar::paintEvent(QPaintEvent *e)
{
    //QScrollBar::paintEvent(e);

    QStyleOptionSlider opt;
    initStyleOption(&opt);
    opt.subControls = QStyle::SC_All;

    QRect slider = style()->subControlRect(QStyle::CC_ScrollBar,  &opt, QStyle::SC_ScrollBarSlider, this);

    QRect addPage = style()->subControlRect(QStyle::CC_ScrollBar,  &opt, QStyle::SC_ScrollBarAddPage, this);
    QRect subPage = style()->subControlRect(QStyle::CC_ScrollBar,  &opt, QStyle::SC_ScrollBarSubPage, this);

    QRect addLine = style()->subControlRect(QStyle::CC_ScrollBar,  &opt, QStyle::SC_ScrollBarAddLine, this);
    QRect subLine = style()->subControlRect(QStyle::CC_ScrollBar,  &opt, QStyle::SC_ScrollBarSubLine, this);

    QRect first = style()->subControlRect(QStyle::CC_ScrollBar,  &opt, QStyle::SC_ScrollBarFirst, this);
    QRect last = style()->subControlRect(QStyle::CC_ScrollBar,  &opt, QStyle::SC_ScrollBarLast, this);

    QRect grove = style()->subControlRect(QStyle::CC_ScrollBar,  &opt, QStyle::SC_ScrollBarGroove, this);


    m_lineHeight = addLine.height();
    QPainter p(this);
    drawScrollBarBackground(&p, grove, QColor("yellow"));
    drawHandle(&p, slider, QColor("blue"));
    drawAddSubLine(&p, addLine, QColor("red"));
}

void CustomScrollBar::drawHandle(QPainter *p, QRect rect, QColor backgroundColor)
{
    uint scrollAreaHeight = this->height() - m_lineHeight*2 - m_handleheight;
    double positionProportion = 0;
    if(maximum() != 0)
    {
        positionProportion = (double)value() / (double)maximum();
    }
    uint topY = scrollAreaHeight * positionProportion + m_lineHeight;

    QRect handleRect(0, topY, width(), m_handleheight);
    p->save();
    p->setBrush(backgroundColor);
    p->setPen(backgroundColor);
    p->drawRect(handleRect);
    p->restore();
}

void CustomScrollBar::drawAddSubLine(QPainter *p, QRect rect, QColor backgroundColor)
{
    QRect addLine(QPoint(0, 0), QSize(width(), m_lineHeight));
    QRect subLine(QPoint(0, height() - m_lineHeight), QSize(width(), m_lineHeight));
    p->save();
    p->setBrush(backgroundColor);
    p->drawRect(addLine);
    p->drawRect(subLine);
    p->restore();
}

void CustomScrollBar::drawScrollBarBackground(QPainter *p, QRect rect, QColor backgroundColor)
{
    QRect background(0, 0, width(), height());
    p->save();
    p->setBrush(backgroundColor);
    p->drawRect(background);
    p->restore();
}

void CustomScrollBar::setLineHeight(uint lineheight)
{

}
