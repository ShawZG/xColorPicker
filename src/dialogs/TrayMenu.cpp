#include "TrayMenu.h"

TrayMenu::TrayMenu(QWidget *parent) : QMenu(parent)
{
    initActions();
    initConnect();
}

void TrayMenu::initActions()
{
    showAction = new QAction(QIcon(":/images/menu_show.png"), tr("Show"), this);
    pickAction = new QAction(QIcon(":/images/menu_pick.png"), tr("Pick"), this);
    quitAction = new QAction(QIcon(":/images/menu_quit.png"), tr("Quit"), this);

    addAction(showAction);
    addAction(pickAction);
    addAction(quitAction);
}

void TrayMenu::initConnect()
{
    connect(showAction, &QAction::triggered, this, &TrayMenu::sigShow);
    connect(pickAction, &QAction::triggered, this, &TrayMenu::sigPick);
    connect(quitAction, &QAction::triggered, this, &TrayMenu::sigQuit);
}
