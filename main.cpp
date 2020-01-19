#include "MainDialog.h"

#include <QApplication>
#include <QIcon>
#include <QTranslator>
#include "CommonHelper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#ifdef Q_OS_WIN
    a.setWindowIcon(QIcon(":/images/app_logo.png"));
#elif Q_OS_LINUX
#elif Q_OS_MACOS
#endif
    CommonHelper::setStyle(":/qss/qss_default.qss");
    QTranslator *translator = new QTranslator();
    CommonHelper::setLanguage(translator, CommonHelper::Chinese);

    MainDialog w;
    w.show();

    return a.exec();
}
