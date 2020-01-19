#include <QFile>
#include <QApplication>
//#include <QTranslator>
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

bool CommonHelper::setLanguage(QTranslator *translator, Language language)
{
    QString path;
    switch (language) {
    case Chinese:
        path = ":/language/simplified_chinese.qm";
        break;
    case English:
        path = ":/language/english.qm"   ;
        break;
    }

    if (true == translator->load(path)) {
        return qApp->installTranslator(translator);
    }
    else {
        return false;
    }
}
