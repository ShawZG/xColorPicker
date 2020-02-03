#include "MainDialog.h"

#include <QApplication>
#include <QIcon>
#include <QTranslator>
#include "CommonHelper.h"
#include "AppConfig.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#ifdef Q_OS_WIN
    a.setWindowIcon(QIcon(":/images/app_logo.png"));
#elif Q_OS_LINUX
#elif Q_OS_MACOS
#endif
    CommonHelper::setStyle(QString(":/qss/qss_%1.qss").arg(AppConfig::getSkin()));
    CommonHelper::setLanguage(AppConfig::getLanguage());

    MainDialog w;
    w.show();

    return a.exec();
}
