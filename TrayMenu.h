#ifndef TRAYMENU_H
#define TRAYMENU_H

#include <QObject>
#include <QWidget>
#include <QMenu>
#include <QAction>

class TrayMenu : public QMenu
{
    Q_OBJECT
public:
    explicit TrayMenu(QWidget *parent = nullptr);

signals:
    void sigShow();
    void sigSetting();
    void sigHelp();
    void sigAbout();
    void sigQuit();

private:
    void initActions();
    void initConnect();

    QAction *showAction;
    QAction *settingAction;
    QAction *helpAction;
    QAction *aboutAction;
    QAction *quitAction;
};

#endif // TRAYMENU_H
