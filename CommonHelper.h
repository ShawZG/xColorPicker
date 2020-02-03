#ifndef COMMONHELPER_H
#define COMMONHELPER_H

#include <QObject>
#include <QTranslator>

class CommonHelper : public QObject
{
    Q_OBJECT
public:
    explicit CommonHelper(QObject *parent = nullptr);

<<<<<<< HEAD
    static void setStyle(const QString &style);
    static bool setLanguage(QString language);

private:
    static QTranslator *translator;
=======
    enum Language {Chinese, English};

    static void setStyle(const QString &style);
    static bool setLanguage(QTranslator *translator, Language language);
>>>>>>> 4da7d9fe7b6f3bd9228dbcf5380533f8a39c9e1f
};

#endif // COMMONHELPER_H
