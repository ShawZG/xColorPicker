#ifndef COLORSLIDER_H
#define COLORSLIDER_H

#include <QWidget>
#include <QFrame>
#include <QColor>

class ColorLabel;
class QSlider;
class QLineEdit;

class ColorSlider : public QFrame
{
    Q_OBJECT
public:
    explicit ColorSlider(Qt::GlobalColor color, QWidget *parent = nullptr);
    int  getColorValue();

public slots:
    void slotSetColor(int value);
signals:
    void sigColorChanged(Qt::GlobalColor color, int value);

private:
    void initUI();
    void initConnect();

    Qt::GlobalColor     color;
    ColorLabel          *colorLabel = nullptr;
    QSlider             *colorSlider = nullptr;
    QLineEdit           *colorValueEdit = nullptr;
};

#endif // COLORSLIDER_H
