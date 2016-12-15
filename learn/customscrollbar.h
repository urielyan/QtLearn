#ifndef CUSTOMSCROLLBAR_H
#define CUSTOMSCROLLBAR_H

#include <QScrollBar>
#include <QCommonStyle>
#include <QProxyStyle>
#include <QTableView>

class scrollBarStyle : public QProxyStyle
{
    Q_OBJECT
public:
    scrollBarStyle(QObject *parent = 0);

protected:
#define DrawComplexControl
#ifdef DrawComplexControl

    void drawComplexControl(ComplexControl control, const QStyleOptionComplex * option, QPainter * painter, const QWidget * widget = 0) const;
#endif
    void drawPrimitive(PrimitiveElement element, const QStyleOption * option, QPainter * painter, const QWidget * widget = 0) const;
    void drawControl(ControlElement element, const QStyleOption * option, QPainter * painter, const QWidget * widget = 0) const;

    void drawHoverRect(QPainter *painter, const QRect &rect) const;

};


#include <QPaintEvent>
class CustomScrollBar : public QScrollBar
{
    Q_OBJECT

public:
    CustomScrollBar(QWidget *parent);

    void paintEvent(QPaintEvent *e);
    void drawHandle(QPainter *p, QRect rect, QColor backgroundColor);
    void drawAddSubLine(QPainter *p, QRect rect, QColor backgroundColor);
    void drawScrollBarBackground(QPainter *p, QRect rect, QColor backgroundColor);

    void setLineHeight(uint lineheight);

private:
    uint m_lineHeight;
    uint m_handleheight;

};

#endif // CUSTOMSCROLLBAR_H
