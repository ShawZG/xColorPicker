#ifndef COLORINDICATOR_H
#define COLORINDICATOR_H

#include <QWidget>
#include <QFrame>
#include <QColor>

class ColorIndicatorLabel;
class QLineEdit;
class ColorIndicator : public QFrame
{
    Q_OBJECT
public:
    explicit ColorIndicator(QColor color, QWidget *parent = nullptr);

public slots:
    void slotColorChange(QColor color);
    void slotCopyToClip();

signals:
    void sigColorChanged(QColor color);

private:
    void initUI();
    void initConnect();

    ColorIndicatorLabel *colorIndicatorLabel = nullptr;
    QLineEdit           *colorHexValueEdit = nullptr;

    QColor color;
};

#endif // COLORINDICATOR_H
