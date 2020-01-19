#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

class QLabel;
class QPushButton;
class SystemTrayIcon;
class QFrame;
class QSlider;
class QLineEdit;
class QLayout;
class ColorSlider;
class ColorIndicator;
class ColorPickerWidget;

class MainDialog : public QDialog
{
    Q_OBJECT
public:
    MainDialog(QWidget *parent = nullptr);
    ~MainDialog();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void slotPickColor();
    void slotSetColorIndicator();
    void slotSetColorPicked(QColor color);

private:
    void initConnect();
    void initUI();
    void initSystemTrayIcon();
    void initColorPickWidget();
    QLayout* initColorSliderLayout();
    QLayout* initColorIndicatorLayout();
    QLayout* initFeedbackLayout();
    QLayout* initButtonsLayout();

    QFrame          *mainFrame = nullptr;
    ColorSlider     *redColorSlider = nullptr;
    ColorSlider     *greenColorSlider = nullptr;
    ColorSlider     *blueColorSlider = nullptr;

    ColorIndicator  *colorIndicator = nullptr;
    QPushButton     *pickButton = nullptr;
    QPushButton     *copyColorButton = nullptr;

    SystemTrayIcon  *sysTrayIcon = nullptr;
    ColorPickerWidget *colorPickWidget = nullptr;
};
#endif // MAINDIALOG_H
