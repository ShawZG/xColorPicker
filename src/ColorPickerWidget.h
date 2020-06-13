#ifndef COLORPICKERWIDGET_H
#define COLORPICKERWIDGET_H

#include <QWidget>

class QTimer;
class QPixmap;

class ColorPickerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ColorPickerWidget(QWidget *parent = nullptr);
    ~ColorPickerWidget();

public slots:
    void slotPickColor();

signals:
    void sigColorPicked(QColor color);
    void sigCancelPicked();

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    void setCursorShape();

    QTimer *paintCursorShapeTimer = nullptr;
    QPixmap grabPixmap;
};

#endif // COLORPICKERWIDGET_H
