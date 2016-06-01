#include "learnqpainter.h"
#include <QPainter>
#include <QPushButton>

LearnQPainter::LearnQPainter(QWidget *parent) : QWidget(parent)
{
}

void LearnQPainter::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setPen(QColor("red"));
    painter.drawText(10, 10, "10.10");
    painter.drawText(20, 20, "20.20");

    painter.translate(QPointF(0,rect().height()));
    painter.rotate(70);
    for(int i = 0; i < 5; i++)
    {
        painter.drawText(200,-i * 5*40, QString::number(i));
        painter.drawText(210, -i * 5*40,  QString::number(i + 1));
        painter.drawText(220, -i * 5*40,  QString::number(i - 1));
    }

    QWidget::paintEvent(e);
}

