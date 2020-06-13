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
    void sigPick();
    void sigQuit();
    void sigShow();

private:
    void initActions();
    void initConnect();

    QAction *pickAction;
    QAction *showAction;
    QAction *quitAction;
};

#endif // TRAYMENU_H
