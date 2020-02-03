#include <QFile>
#include <QApplication>
<<<<<<< HEAD
#include <QDebug>
#include "CommonHelper.h"

QTranslator* CommonHelper::translator = new QTranslator();

=======
//#include <QTranslator>
#include <QDebug>
#include "CommonHelper.h"

>>>>>>> 4da7d9fe7b6f3bd9228dbcf5380533f8a39c9e1f
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

<<<<<<< HEAD
bool CommonHelper::setLanguage(QString language)
{
    QString path = QString(":/language/%1.qm").arg(language);
    if (true == CommonHelper::translator ->load(path)) {
=======
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
>>>>>>> 4da7d9fe7b6f3bd9228dbcf5380533f8a39c9e1f
        return qApp->installTranslator(translator);
    }
    else {
        return false;
    }
}
