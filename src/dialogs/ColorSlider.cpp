#include <QSlider>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRegExp>
#include <QRegExpValidator>
#include "ColorLabel.h"
#include "ColorSlider.h"

ColorSlider::ColorSlider(Qt::GlobalColor color, QWidget *parent) : QFrame(parent)
{
    this->color = color;
    initUI();
    initConnect();
}

int ColorSlider::getColorValue()
{
    return colorSlider->value();
}

void ColorSlider::initUI()
{
    colorLabel = new ColorLabel(color);
    colorLabel->setFixedSize(20, 20);

    colorSlider = new QSlider(Qt::Horizontal);
    colorSlider->setFixedWidth(192);
    colorSlider->setRange(0, 255);
    colorSlider->setSingleStep(1);
    colorSlider->setValue(colorSlider->maximum());

    colorValueEdit = new QLineEdit(QString::number(colorSlider->maximum()));
    colorValueEdit->setFixedSize(36, 24);
    colorValueEdit->setAlignment(Qt::AlignCenter);
    QRegExp regExpIP("(\\d|[1-9]\\d|1\\d{2}|2[0-4]\\d|25[0-5])");
    colorValueEdit->setValidator(new QRegExpValidator(regExpIP));

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->setContentsMargins(2, 2, 2, 2);
    hLayout->setSpacing(2);
    hLayout->addWidget(colorLabel);
    hLayout->addWidget(colorSlider);
    hLayout->addWidget(colorValueEdit);
    setLayout(hLayout);
}

void ColorSlider::initConnect()
{
    connect(colorSlider, &QSlider::valueChanged, colorLabel, &ColorLabel::slotColorChange);
    connect(colorSlider, &QSlider::valueChanged, [this](int value){this->colorValueEdit->setText(QString::number(value));});
    connect(colorValueEdit, &QLineEdit::textEdited, [this](QString value){this->colorSlider->setValue(value.QString::toInt());});
    connect(colorSlider, &QSlider::valueChanged, [this](int value){emit this->sigColorChanged(color, value);});
}

void ColorSlider::slotSetColor(int value)
{
    colorSlider->setValue(value);
}
