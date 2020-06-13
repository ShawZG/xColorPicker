#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <QObject>
class QSettings;

class AppConfig : public QObject
{
    Q_OBJECT
public:
    explicit AppConfig(QObject *parent = nullptr);

    static void     setSkin(QString skin);
    static QString  getSkin();

    static void     setLanguage(QString language);
    static QString  getLanguage();

    static void     setExit(QString exit);
    static QString  getExit();

    static QString  appVer;
private:
    static void     loadConfig();
    static void     saveConfig();

    static QSettings *setting;

    static QString skin;
    static QString language;
    static QString exit;
};

#endif // APPCONFIG_H
