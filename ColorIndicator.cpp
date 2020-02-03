#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRegExpValidator>
#include <QRegExp>
#include "ColorIndicatorLabel.h"
#include "ColorIndicator.h"

ColorIndicator::ColorIndicator(QColor color, QWidget *parent) : QFrame(parent)
{
    this->color = color;
    initUI();
    initConnect();
}

void ColorIndicator::slotColorChange(QColor color)
{
    colorIndicatorLabel->slotColorChange(color);
    colorHexValueEdit->setText(color.name(QColor::HexRgb).toUpper());
}

void ColorIndicator::slotCopyToClip()
{
    colorHexValueEdit->selectAll();
    colorHexValueEdit->copy();
    colorHexValueEdit->deselect();
}

void ColorIndicator::initUI()
{
    colorIndicatorLabel = new ColorIndicatorLabel(color);
    colorIndicatorLabel->setFixedSize(70, 70);

    QLabel *label = new QLabel(tr("Hex"));
    label->setFixedSize(24, 24);

    colorHexValueEdit = new QLineEdit(color.name(QColor::HexRgb).toUpper());
    colorHexValueEdit->setFixedSize(50, 24);
    colorHexValueEdit->setAlignment(Qt::AlignCenter);
    QRegExp regExpIP("(\\xhhhhhh)");
    colorHexValueEdit->setValidator(new QRegExpValidator(regExpIP));

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->setContentsMargins(2, 2, 2, 2);
    hLayout->setSpacing(2);
    hLayout->addWidget(label);
    hLayout->addWidget(colorHexValueEdit);
    hLayout->addStretch();

    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->setContentsMargins(2, 2, 2, 2);
    vLayout->setSpacing(10);
    vLayout->addWidget(colorIndicatorLabel, Qt::AlignCenter);
    vLayout->addLayout(hLayout, Qt::AlignCenter);

    setLayout(vLayout);
}

void ColorIndicator::initConnect()
{
}
<<<<<<< HEAD

=======
>>>>>>> 4da7d9fe7b6f3bd9228dbcf5380533f8a39c9e1f
