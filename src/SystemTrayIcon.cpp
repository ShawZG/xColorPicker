#include <QEvent>
#include <QDebug>
#include "SystemTrayIcon.h"

SystemTrayIcon::SystemTrayIcon(QObject *parent) : QSystemTrayIcon(parent)
{
    initTrayMenu();
    initConnect();
}

SystemTrayIcon::SystemTrayIcon(const QIcon &icon, QObject *parent) : QSystemTrayIcon(icon, parent)
{
    initTrayMenu();
    initConnect();
}

void SystemTrayIcon::initTrayMenu()
{
    trayMenu = new TrayMenu();
    setContextMenu(trayMenu);
}

void SystemTrayIcon::initConnect()
{
    connect(trayMenu, &TrayMenu::sigShow, this, &SystemTrayIcon::sigShow);
    connect(trayMenu, &TrayMenu::sigPick, this, &SystemTrayIcon::sigPick);
    connect(trayMenu, &TrayMenu::sigQuit, this, &SystemTrayIcon::sigQuit);
}
