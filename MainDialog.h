#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

class QLabel;
<<<<<<< HEAD
class SystemTrayIcon;
class QLabel;
class StackPickerFrame;
class StackConfigFrame;
=======
class QPushButton;
class SystemTrayIcon;
class QFrame;
class QSlider;
class QLineEdit;
class QLayout;
class ColorSlider;
class ColorIndicator;
class ColorPickerWidget;
>>>>>>> 4da7d9fe7b6f3bd9228dbcf5380533f8a39c9e1f

class MainDialog : public QDialog
{
    Q_OBJECT
public:
    MainDialog(QWidget *parent = nullptr);
    ~MainDialog();

<<<<<<< HEAD
    void showConfigWidget();
    void showPickerWidget();

protected:
    void closeEvent(QCloseEvent *event);

=======
protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void slotPickColor();
    void slotSetColorIndicator();
    void slotSetColorPicked(QColor color);

>>>>>>> 4da7d9fe7b6f3bd9228dbcf5380533f8a39c9e1f
private:
    void initConnect();
    void initUI();
    void initSystemTrayIcon();
<<<<<<< HEAD

    SystemTrayIcon      *sysTrayIcon = nullptr;

    StackPickerFrame    *stackPickerFrame = nullptr;
    StackConfigFrame    *stackConfigFrame = nullptr;
=======
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
>>>>>>> 4da7d9fe7b6f3bd9228dbcf5380533f8a39c9e1f
};
#endif // MAINDIALOG_H
