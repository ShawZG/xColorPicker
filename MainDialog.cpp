#include <QApplication>
#include <QCloseEvent>
#include <QStackedLayout>
#include "SystemTrayIcon.h"
#include "CommonHelper.h"
#include "StackPickerFrame.h"
#include "StackConfigFrame.h"
#include "AppConfig.h"
#include "MainDialog.h"

MainDialog::MainDialog(QWidget *parent)
    : QDialog(parent)
{
    setObjectName("mainDialog");
    initUI();
    initSystemTrayIcon();

    initConnect();
}

MainDialog::~MainDialog()
{
}

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
}

void MainDialog::initUI()
{
    setWindowFlags(Qt::Dialog | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
    setFixedSize(370, 150);

    stackPickerFrame = new StackPickerFrame(this);
    stackConfigFrame = new StackConfigFrame(this);

    QStackedLayout *sLayout = new QStackedLayout();
    sLayout->setContentsMargins(0, 0, 0, 0);
    sLayout->addWidget(stackPickerFrame);
    sLayout->addWidget(stackConfigFrame);
    setLayout(sLayout);

    setWindowTitle(tr("XColorPicker ") + AppConfig::appVer);
}

void MainDialog::initSystemTrayIcon()
{
    sysTrayIcon = new SystemTrayIcon(QIcon(":/images/app_logo.png"), this);
    sysTrayIcon->show();
}

void MainDialog::initConnect()
{
    connect(sysTrayIcon, &SystemTrayIcon::sigPick, stackPickerFrame, &StackPickerFrame::slotPickColor);
    connect(sysTrayIcon, &SystemTrayIcon::sigShow, [this](){this->show();});
    connect(sysTrayIcon, &SystemTrayIcon::sigQuit, [](){QApplication::exit(0);});
}
