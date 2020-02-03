#include "MainDialog.h"

#include <QApplication>
#include <QIcon>
#include <QTranslator>
#include "CommonHelper.h"
<<<<<<< HEAD
#include "AppConfig.h"
=======
>>>>>>> 4da7d9fe7b6f3bd9228dbcf5380533f8a39c9e1f

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#ifdef Q_OS_WIN
    a.setWindowIcon(QIcon(":/images/app_logo.png"));
#elif Q_OS_LINUX
#elif Q_OS_MACOS
#endif
<<<<<<< HEAD
    CommonHelper::setStyle(QString(":/qss/qss_%1.qss").arg(AppConfig::getSkin()));
    CommonHelper::setLanguage(AppConfig::getLanguage());
=======
    CommonHelper::setStyle(":/qss/qss_default.qss");
    QTranslator *translator = new QTranslator();
    CommonHelper::setLanguage(translator, CommonHelper::Chinese);

>>>>>>> 4da7d9fe7b6f3bd9228dbcf5380533f8a39c9e1f
    MainDialog w;
    w.show();

    return a.exec();
}
