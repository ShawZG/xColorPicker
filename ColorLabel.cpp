#include <QPainter>
#include <QColor>
#include <QPaintEvent>

#include "ColorLabel.h"
ColorLabel::ColorLabel(Qt::GlobalColor color, QWidget *parent) : QLabel(parent)
{
    this->color = color;
    if (Qt::red == color)
        redValue = 255;
    else if (Qt::green == color)
        greenValue = 255;
    else if (Qt::blue == color)
        blueValue = 255;
}

void ColorLabel::slotColorChange(int value)
{
    if (Qt::red == color)
        redValue = value;
    else if (Qt::green == color)
        greenValue = value;
    else if (Qt::blue == color)
        blueValue = value;
    update();
}

void ColorLabel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(QPen(QColor(redValue, greenValue, blueValue), 0));
    painter.setBrush(QColor(redValue, greenValue, blueValue));
    painter.drawRoundedRect(event->rect(), 4, 4);
}
