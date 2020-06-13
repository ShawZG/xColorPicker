#include <QFile>
#include <QApplication>
#include <QDebug>
#include "CommonHelper.h"

QTranslator* CommonHelper::translator = new QTranslator();

#include <QTranslator>
#include <QDebug>
#include "CommonHelper.h"

CommonHelper::CommonHelper(QObject *parent) : QObject(parent)
{
}

void CommonHelper::setStyle(const QString &style)
{
    QFile qss(style);
    if (true == qss.open(QFile::ReadOnly))
    {
        qApp->setStyleSheet(qss.readAll());
        qss.close();
    }
}

bool CommonHelper::setLanguage(QString language)
{
    QString path = QString(":/language/%1.qm").arg(language);
    if (true == CommonHelper::translator ->load(path)) {
        return qApp->installTranslator(translator);
    }
    else {
        return false;
    }
}
