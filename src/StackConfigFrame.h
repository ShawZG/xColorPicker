#ifndef STACKCONFIGFRAME_H
#define STACKCONFIGFRAME_H

#include <QWidget>
#include <QFrame>

class QPushButton;
class QComboBox;
class QRadioButton;
class QLayout;

class StackConfigFrame : public QFrame
{
    Q_OBJECT
public:
    explicit StackConfigFrame(QWidget *parent = nullptr);

private slots:
    void slotShowPickerWidget();
    void slotSetExitOrHide();

private:
    void initUI();
    QLayout* initLanguageLayout();
    QLayout* initSkinLayout();
    QLayout* initExitLayout();
    QLayout* initReturnLayout();
    void initConnect();
    void loadConfig();

    QComboBox       *languageComboBox = nullptr;
    QComboBox       *skinComboBox = nullptr;
    QRadioButton    *exitRadioButton = nullptr;
    QRadioButton    *hideRadioButton = nullptr;
    QPushButton     *returnButton = nullptr;

    QStringList     languageList = { "english", "simplified_chinese"};
    QStringList     skinList = {"default"};
};

#endif // STACKCONFIGFRAME_H
