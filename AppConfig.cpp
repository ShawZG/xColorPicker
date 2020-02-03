#include <QApplication>
#include <QFile>
#include <QSettings>
#include "CommonHelper.h"
#include "AppConfig.h"

QString AppConfig::appVer = "v1.1.0";
QSettings* AppConfig::setting = nullptr;
QString AppConfig::skin = "";
QString AppConfig::language = "";
QString AppConfig::exit = "";

AppConfig::AppConfig(QObject *parent) : QObject(parent)
{
}

void AppConfig::setSkin(QString skin)
{
    if (nullptr == AppConfig::setting) {AppConfig::loadConfig();}
    AppConfig::setting->setValue("skin", skin);
    AppConfig::setting->sync();
}

QString AppConfig::getSkin()
{
    if (nullptr == AppConfig::setting) {AppConfig::loadConfig();}
    return AppConfig::setting->value("skin", QString("default")).toString();
}

#include <QDebug>
void AppConfig::setLanguage(QString language)
{
    if (nullptr == AppConfig::setting) {AppConfig::loadConfig();}
    AppConfig::setting->setValue("language", language);
    AppConfig::setting->sync();

    qDebug() << CommonHelper::setLanguage(language);
}

QString AppConfig::getLanguage()
{
    if (nullptr == AppConfig::setting) {AppConfig::loadConfig();}
    return AppConfig::setting->value("language", QString("english")).toString();
}

void AppConfig::setExit(QString exit)
{
    if (nullptr == AppConfig::setting) {AppConfig::loadConfig();}
    AppConfig::setting->setValue("exit", exit);
    AppConfig::setting->sync();
}

QString AppConfig::getExit()
{
    if (nullptr == AppConfig::setting) {AppConfig::loadConfig();}
    return AppConfig::setting->value("exit", QString("hide")).toString();
}

#include <QDebug>
void AppConfig::loadConfig()
{
    QString dirPath = QApplication::applicationDirPath();
    QString filePath = QString("%1/%2").arg(dirPath).arg("config.ini");

//    if ( false == QFile::exists(filePath))
//    {
//        QFile file(filePath);
//        file.open(QIODevice::ReadWrite);
//        file.close();
//    }

    AppConfig::setting = new QSettings(filePath, QSettings::IniFormat);
    qDebug() << filePath;
    /*
    do not need function saveConfig, because QSettings::sync() is called automatically from QSettings's destructor
    and by the event loop at regular intervals, so you normally don't need to call it yourself.
    QSettings::sync() Writes any unsaved changes to permanent storage, and reloads any settings
    that have been changed in the meantime by another application.
    */
}
