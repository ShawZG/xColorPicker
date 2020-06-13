#ifndef COLORLABEL_H
#define COLORLABEL_H

#include <QWidget>
#include <QLabel>

class ColorLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ColorLabel(Qt::GlobalColor color, QWidget *parent = nullptr);

public slots:
    void slotColorChange(int value);

protected:
    void paintEvent(QPaintEvent *event);

private:
    Qt::GlobalColor color;
    int redValue = 0;
    int greenValue = 0;
    int blueValue = 0;
};

#endif // COLORLABEL_H
