#include <QPainter>
#include <QPaintEvent>

#include "ColorIndicatorLabel.h"

ColorIndicatorLabel::ColorIndicatorLabel(QColor color, QWidget *parent) : QLabel(parent)
{
    red = color.red();
    green = color.green();
    blue = color.blue();
}

void ColorIndicatorLabel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(QColor(red, green, blue), 0));
    painter.setBrush(QColor(red, green, blue));
    painter.drawRoundedRect(event->rect(), 4, 4);
}

void ColorIndicatorLabel::slotColorChange(QColor color)
{
    red = color.red();
    green = color.green();
    blue = color.blue();
    update();
}
