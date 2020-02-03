#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>

class QLabel;
class SystemTrayIcon;
class QLabel;
class StackPickerFrame;
class StackConfigFrame;

class MainDialog : public QDialog
{
    Q_OBJECT
public:
    MainDialog(QWidget *parent = nullptr);
    ~MainDialog();

    void showConfigWidget();
    void showPickerWidget();

protected:
    void closeEvent(QCloseEvent *event);

private:
    void initConnect();
    void initUI();
    void initSystemTrayIcon();

    SystemTrayIcon      *sysTrayIcon = nullptr;

    StackPickerFrame    *stackPickerFrame = nullptr;
    StackConfigFrame    *stackConfigFrame = nullptr;
};
#endif // MAINDIALOG_H
