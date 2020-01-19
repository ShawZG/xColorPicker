#ifndef COMMONHELPER_H
#define COMMONHELPER_H

#include <QObject>
#include <QTranslator>

class CommonHelper : public QObject
{
    Q_OBJECT
public:
    explicit CommonHelper(QObject *parent = nullptr);

    enum Language {Chinese, English};

    static void setStyle(const QString &style);
    static bool setLanguage(QTranslator *translator, Language language);
};

#endif // COMMONHELPER_H
