#ifndef COLORINDICATORLABEL_H
#define COLORINDICATORLABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class ColorIndicatorLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ColorIndicatorLabel(QColor color, QWidget *parent = nullptr);

public slots:
    void slotColorChange(QColor color);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int red = 0;
    int green = 0;
    int blue = 0;
};

#endif // COLORINDICATORLABEL_H
