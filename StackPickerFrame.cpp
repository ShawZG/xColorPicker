#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QApplication>
#include <QTimer>
#include <QEvent>
#include "SystemTrayIcon.h"
#include "ColorLabel.h"
#include "ColorIndicator.h"
#include "ColorSlider.h"
#include "ColorPickerWidget.h"
#include "MainDialog.h"
#include "StackPickerFrame.h"

StackPickerFrame::StackPickerFrame(QWidget *parent) : QFrame(parent)
{
    initUI();
    initColorPickWidget();
    initConnect();
}

void StackPickerFrame::initUI()
{
    QLayout *rgbLayout = initColorSliderLayout();
    QLayout *indicatorLayout = initColorIndicatorLayout();
    QLayout *pickButtonLayout = initButtonsLayout();
    QLayout *feedbackLayout = initFeedbackLayout();

    QHBoxLayout *hLayout1 = new QHBoxLayout();
    hLayout1->setContentsMargins(2, 2, 2, 2);
    hLayout1->setSpacing(4);
    hLayout1->addLayout(rgbLayout);
    hLayout1->addLayout(indicatorLayout);

    QHBoxLayout *hLayout2 = new QHBoxLayout();
    hLayout2->setContentsMargins(2, 2, 2, 2);
    hLayout2->setSpacing(2);
    hLayout2->addLayout(feedbackLayout);
    hLayout2->addLayout(pickButtonLayout);

    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->setContentsMargins(2, 2, 2, 2);
    vLayout->setSpacing(2);
    vLayout->addLayout(hLayout1);
    vLayout->addLayout(hLayout2);
    setLayout(vLayout);
}

void StackPickerFrame::initConnect()
{
    connect(redColorSlider, &ColorSlider::sigColorChanged, this, &StackPickerFrame::slotSetColorIndicator);
    connect(greenColorSlider, &ColorSlider::sigColorChanged, this, &StackPickerFrame::slotSetColorIndicator);
    connect(blueColorSlider, &ColorSlider::sigColorChanged, this, &StackPickerFrame::slotSetColorIndicator);

    connect(pickButton, &QPushButton::clicked, this, &StackPickerFrame::slotPickColor);
    connect(copyColorButton, &QPushButton::clicked, colorIndicator, &ColorIndicator::slotCopyToClip);

    connect(colorPickWidget, &ColorPickerWidget::sigColorPicked, this, &StackPickerFrame::slotSetColorPicked);
    connect(colorPickWidget, &ColorPickerWidget::sigCancelPicked, [this](){this->colorPickWidget->hide(); this->parentWidget()->show();});

    connect(settingButton, &QPushButton::clicked, this, &StackPickerFrame::slotShowConfigWidget);
}

void StackPickerFrame::initColorPickWidget()
{
    colorPickWidget = new ColorPickerWidget();
}

QLayout *StackPickerFrame::initColorSliderLayout()
{
    redColorSlider = new ColorSlider(Qt::red);
    redColorSlider->setObjectName("redColorSlider");
    greenColorSlider = new ColorSlider(Qt::green);
    greenColorSlider->setObjectName("greenColorSlider");
    blueColorSlider = new ColorSlider(Qt::blue);
    blueColorSlider->setObjectName("blueColorSlider");

    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->setContentsMargins(2, 2, 2, 2);
    vLayout->setSpacing(6);
    vLayout->addWidget(redColorSlider);
    vLayout->addWidget(greenColorSlider);
    vLayout->addWidget(blueColorSlider);
    vLayout->addStretch();
    return vLayout;
}

QLayout *StackPickerFrame::initColorIndicatorLayout()
{
    colorIndicator = new ColorIndicator(QColor(255, 255, 255));
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->setContentsMargins(0, 0, 0, 0);
    hLayout->setSpacing(0);
    hLayout->addStretch();
    hLayout->addWidget(colorIndicator);
    return hLayout;
}

QLayout *StackPickerFrame::initFeedbackLayout()
{
    settingButton = new QPushButton(QIcon(":/images/btn_setting.png"), QString());
    settingButton->setToolTip(tr("Setting"));
    settingButton->setFixedSize(24, 24);
    settingButton->setObjectName("settingButton");

    QLabel *feedbackLabel = new QLabel();
    feedbackLabel->setFixedHeight(28);
    feedbackLabel->setText(tr("Author: blueshaw@163.com"));
    setObjectName("feedbackLabel");

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->setContentsMargins(0, 0, 0, 0);
    hLayout->setSpacing(0);
    hLayout->addWidget(settingButton);
    hLayout->addSpacing(8);
    hLayout->addWidget(feedbackLabel);
    hLayout->addStretch();
    return hLayout;
}

QLayout *StackPickerFrame::initButtonsLayout()
{
    pickButton = new QPushButton(QIcon(":/images/btn_pick.png"), tr("Pick"));
    pickButton->setToolTip(tr("Picker color"));
    pickButton->setFixedSize(50, 24);
    pickButton->setObjectName("pickButton");

    copyColorButton = new QPushButton(QIcon(":/images/btn_copy.png"), tr("Copy"));
    copyColorButton->setToolTip(tr("Copy to clip"));
    copyColorButton->setFixedSize(50, 24);
    copyColorButton->setObjectName("copyColorButton");

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->setContentsMargins(2, 2, 2, 2);
    hLayout->setSpacing(10);
    hLayout->addStretch();
    hLayout->addWidget(pickButton);
    hLayout->addWidget(copyColorButton);
    return hLayout;
}

void StackPickerFrame::slotPickColor()
{
    parentWidget()->hide();
    /*use timer to hide maindialog */
    QTimer::singleShot(150, [this](){ this->colorPickWidget->slotPickColor(); colorPickWidget->showFullScreen();});
}

void StackPickerFrame::slotSetColorIndicator()
{
    int red = redColorSlider->getColorValue();
    int green = greenColorSlider->getColorValue();
    int blue = blueColorSlider->getColorValue();
    colorIndicator->slotColorChange(QColor(red, green, blue));
}

void StackPickerFrame::slotSetColorPicked(QColor color)
{
    redColorSlider->slotSetColor(color.red());
    greenColorSlider->slotSetColor(color.green());
    blueColorSlider->slotSetColor(color.blue());
    colorPickWidget->hide();
    colorIndicator->slotCopyToClip();
    parentWidget()->show();
}

void StackPickerFrame::slotShowConfigWidget()
{
    MainDialog* mainDialog = dynamic_cast<MainDialog*>(parentWidget());
    mainDialog->showConfigWidget();
}
