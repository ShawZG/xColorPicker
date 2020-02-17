#ifndef STACKPICKERFRAME_H
#define STACKPICKERFRAME_H

#include <QWidget>
#include <QFrame>

class QLabel;
class QPushButton;
class QSlider;
class QLineEdit;
class QLayout;
class ColorSlider;
class ColorIndicator;
class ColorPickerWidget;

class StackPickerFrame : public QFrame
{
    Q_OBJECT
public:
    explicit StackPickerFrame(QWidget *parent = nullptr);

public slots:
    void slotPickColor();
    void slotSetColorIndicator();
    void slotSetColorPicked(QColor color);

private slots:
    void slotShowConfigWidget();

private:
    void initUI();
    void initConnect();

    void initColorPickWidget();
    QLayout* initColorSliderLayout();
    QLayout* initColorIndicatorLayout();
    QLayout* initFeedbackLayout();
    QLayout* initButtonsLayout();

    ColorSlider     *redColorSlider = nullptr;
    ColorSlider     *greenColorSlider = nullptr;
    ColorSlider     *blueColorSlider = nullptr;

    ColorIndicator  *colorIndicator = nullptr;
    QPushButton     *pickButton = nullptr;
    QPushButton     *copyColorButton = nullptr;
    QPushButton     *settingButton = nullptr;

    ColorPickerWidget *colorPickWidget = nullptr;
};

#endif // STACKPICKERFRAME_H
