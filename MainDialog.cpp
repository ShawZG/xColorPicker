<<<<<<< HEAD
﻿#include <QApplication>
#include <QCloseEvent>
#include <QStackedLayout>
#include "SystemTrayIcon.h"
#include "CommonHelper.h"
#include "StackPickerFrame.h"
#include "StackConfigFrame.h"
#include "AppConfig.h"
=======
﻿#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QApplication>
#include <QCloseEvent>
#include "SystemTrayIcon.h"
#include "ColorLabel.h"
#include "ColorIndicator.h"
#include "ColorSlider.h"
#include "ColorPickerWidget.h"
#include "CommonHelper.h"
>>>>>>> 4da7d9fe7b6f3bd9228dbcf5380533f8a39c9e1f
#include "MainDialog.h"

MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
{
    setObjectName("mainDialog");
    initUI();
    initSystemTrayIcon();
<<<<<<< HEAD

=======
    initColorPickWidget();
>>>>>>> 4da7d9fe7b6f3bd9228dbcf5380533f8a39c9e1f
    initConnect();
}

MainDialog::~MainDialog()
{
}

<<<<<<< HEAD
void MainDialog::showConfigWidget()
{
    QStackedLayout *slayout = dynamic_cast<QStackedLayout*>(layout());
    slayout->setCurrentWidget(stackConfigFrame);
}

void MainDialog::showPickerWidget()
{
    QStackedLayout *slayout = dynamic_cast<QStackedLayout*>(layout());
    slayout->setCurrentWidget(stackPickerFrame);
}

void MainDialog::closeEvent(QCloseEvent *event)
{
    if (0 == QString::compare(AppConfig::getExit(), "hide", Qt::CaseInsensitive))
    {
        event->ignore();
        hide();
    }
=======
void MainDialog::closeEvent(QCloseEvent *event)
{
    event->ignore();
    hide();
>>>>>>> 4da7d9fe7b6f3bd9228dbcf5380533f8a39c9e1f
}

void MainDialog::initUI()
{
    setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    setFixedSize(370, 150);

<<<<<<< HEAD
    stackPickerFrame = new StackPickerFrame(this);
    stackConfigFrame = new StackConfigFrame(this);

    QStackedLayout *sLayout = new QStackedLayout();
    sLayout->setContentsMargins(0, 0, 0, 0);
    sLayout->addWidget(stackPickerFrame);
    sLayout->addWidget(stackConfigFrame);
    setLayout(sLayout);

    setWindowTitle(tr("XColorPicker ") + AppConfig::appVer);
=======
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
    QString ver = "v1.0.0";
    setWindowTitle(tr("XColorPicker") + ver);
>>>>>>> 4da7d9fe7b6f3bd9228dbcf5380533f8a39c9e1f
}

void MainDialog::initSystemTrayIcon()
{
    sysTrayIcon = new SystemTrayIcon(QIcon(":/images/app_logo.png"), this);
    sysTrayIcon->show();
}

<<<<<<< HEAD
void MainDialog::initConnect()
{
    connect(sysTrayIcon, &SystemTrayIcon::sigPick, stackPickerFrame, &StackPickerFrame::slotPickColor);
    connect(sysTrayIcon, &SystemTrayIcon::sigShow, [this](){this->show();});
    connect(sysTrayIcon, &SystemTrayIcon::sigQuit, [](){QApplication::exit(0);});
=======
void MainDialog::initColorPickWidget()
{
    colorPickWidget = new ColorPickerWidget();
}

QLayout *MainDialog::initColorSliderLayout()
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

QLayout *MainDialog::initColorIndicatorLayout()
{
    colorIndicator = new ColorIndicator(QColor(255, 255, 255));
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->setContentsMargins(0, 0, 0, 0);
    hLayout->setSpacing(0);
    hLayout->addStretch();
    hLayout->addWidget(colorIndicator);
    return hLayout;
}

QLayout *MainDialog::initFeedbackLayout()
{
    QLabel *feedbackLabel = new QLabel();
    feedbackLabel->setFixedHeight(28);
    feedbackLabel->setText(tr("Author: blueshaw@163.com"));
    setObjectName("feedbackLabel");

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->setContentsMargins(0, 0, 0, 0);
    hLayout->setSpacing(0);
    hLayout->addWidget(feedbackLabel);
    hLayout->addStretch();
    return hLayout;
}

QLayout *MainDialog::initButtonsLayout()
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

void MainDialog::initConnect()
{
    connect(sysTrayIcon, &SystemTrayIcon::sigPick, this, &MainDialog::slotPickColor);
    connect(sysTrayIcon, &SystemTrayIcon::sigShow, [this](){this->show();});
    connect(sysTrayIcon, &SystemTrayIcon::sigQuit, [](){QApplication::exit(0);});

    connect(redColorSlider, &ColorSlider::sigColorChanged, this, &MainDialog::slotSetColorIndicator);
    connect(greenColorSlider, &ColorSlider::sigColorChanged, this, &MainDialog::slotSetColorIndicator);
    connect(blueColorSlider, &ColorSlider::sigColorChanged, this, &MainDialog::slotSetColorIndicator);

    connect(pickButton, &QPushButton::clicked, this, &MainDialog::slotPickColor);
    connect(copyColorButton, &QPushButton::clicked, colorIndicator, &ColorIndicator::slotCopyToClip);

    connect(colorPickWidget, &ColorPickerWidget::sigColorPicked, this, &MainDialog::slotSetColorPicked);
    connect(colorPickWidget, &ColorPickerWidget::sigCancelPicked, [this](){this->colorPickWidget->hide(); this->show();});
}

void MainDialog::slotPickColor()
{
    hide();
    colorPickWidget->slotPickColor();
    colorPickWidget->show();
}

void MainDialog::slotSetColorIndicator()
{
    int red = redColorSlider->getColorValue();
    int green = greenColorSlider->getColorValue();
    int blue = blueColorSlider->getColorValue();
    colorIndicator->slotColorChange(QColor(red, green, blue));
}

void MainDialog::slotSetColorPicked(QColor color)
{
    redColorSlider->slotSetColor(color.red());
    greenColorSlider->slotSetColor(color.green());
    blueColorSlider->slotSetColor(color.blue());
    colorPickWidget->hide();
    colorIndicator->slotCopyToClip();
    show();
>>>>>>> 4da7d9fe7b6f3bd9228dbcf5380533f8a39c9e1f
}
