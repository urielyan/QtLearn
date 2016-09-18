#include "styleoptionstudy.h"
#include <QStyleOptionButton>
#include <QStyle>
#include <QStyleOption>
#include <QPainter>

StyleOptionStudy::StyleOptionStudy(QWidget *parent) : QPushButton(parent)
{

}

void StyleOptionStudy::paintEvent(QPaintEvent *)
{
    QStyleOptionButton option;
    option.initFrom(this);
    option.state = isDown() ? QStyle::State_Sunken : QStyle::State_Raised;
    if (isDefault())
        option.features |= QStyleOptionButton::DefaultButton;
    option.text = "test";
    option.icon = icon();
    option.palette = QPalette();

    QPainter painter(this);
    style()->drawControl(QStyle::CE_MenuItem, &option, &painter, this);
}

