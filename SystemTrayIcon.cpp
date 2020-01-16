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
    connect(trayMenu, &TrayMenu::sigSetting, this, &SystemTrayIcon::sigSetting);
    connect(trayMenu, &TrayMenu::sigHelp, this, &SystemTrayIcon::sigHelp);
    connect(trayMenu, &TrayMenu::sigAbout, this, &SystemTrayIcon::sigAbout);
    connect(trayMenu, &TrayMenu::sigQuit, this, &SystemTrayIcon::sigQuit);
    connect(this, &QSystemTrayIcon::activated, this, &SystemTrayIcon::slotOnTrayIconActivated);
}

void SystemTrayIcon::slotOnTrayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (QSystemTrayIcon::Trigger == reason)
    {
        emit sigTriggerShow();
    }
}
