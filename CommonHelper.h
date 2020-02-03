#ifndef COMMONHELPER_H
#define COMMONHELPER_H

#include <QObject>
#include <QTranslator>

class CommonHelper : public QObject
{
    Q_OBJECT
public:
    explicit CommonHelper(QObject *parent = nullptr);

    static void setStyle(const QString &style);
    static bool setLanguage(QString language);

private:
    static QTranslator *translator;
};

#endif // COMMONHELPER_H
