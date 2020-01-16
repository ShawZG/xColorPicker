#include "TrayMenu.h"

TrayMenu::TrayMenu(QWidget *parent) : QMenu(parent)
{
    initActions();
    initConnect();
}

void TrayMenu::initActions()
{
    showAction = new QAction(QIcon(":/images/images/menu_show.png"), QString::fromLocal8Bit("  显 示"), this);
    settingAction = new QAction(QIcon(":/images/images/menu_setting.png"), QString::fromLocal8Bit("  设 置"), this);
    helpAction= new QAction(QIcon(":/images/images/menu_help.png"), QString::fromLocal8Bit("  帮 助"), this);
    aboutAction = new QAction(QIcon(":/images/images/menu_about.png"), QString::fromLocal8Bit("  关 于"), this);
    quitAction = new QAction(QIcon(":/images/images/menu_quit.png"), QString::fromLocal8Bit("  退 出"), this);

    addAction(showAction);
    addAction(settingAction);
    addSeparator();
    addAction(helpAction);
    addAction(aboutAction);
    addSeparator();
    addAction(quitAction);
}

void TrayMenu::initConnect()
{
    connect(showAction, &QAction::triggered, this, &TrayMenu::sigShow);
    connect(settingAction, &QAction::triggered, this, &TrayMenu::sigSetting);
    connect(helpAction, &QAction::triggered, this, &TrayMenu::sigHelp);
    connect(aboutAction, &QAction::triggered, this, &TrayMenu::sigAbout);
    connect(quitAction, &QAction::triggered, this, &TrayMenu::sigQuit);
}
