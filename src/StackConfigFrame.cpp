#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QRadioButton>
#include <QHBoxLayout>
#include "CommonHelper.h"
#include "MainDialog.h"
#include "AppConfig.h"
#include "StackConfigFrame.h"

StackConfigFrame::StackConfigFrame(QWidget *parent) : QFrame(parent)
{   
    initUI();
    loadConfig();
    initConnect();
}

void StackConfigFrame::slotShowPickerWidget()
{
    MainDialog *mainDialog = dynamic_cast<MainDialog*>(parentWidget());
    mainDialog->showPickerWidget();
}

void StackConfigFrame::slotSetExitOrHide()
{

    if (true == exitRadioButton->isChecked())
    {
        AppConfig::setExit("exit");
    }
    else if(true == hideRadioButton->isChecked())
    {
        AppConfig::setExit("hide");
    }
}

void StackConfigFrame::initUI()
{
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->setContentsMargins(8, 8, 8, 2);
    vLayout->setSpacing(2);
    vLayout->addLayout(initLanguageLayout());
    vLayout->addLayout(initSkinLayout());
    vLayout->addLayout(initExitLayout());
    vLayout->addStretch();
    vLayout->addLayout(initReturnLayout());

    setLayout(vLayout);
}

QLayout* StackConfigFrame::initLanguageLayout()
{
    QLabel *languageLabel = new QLabel(tr("Language"));
    languageLabel->setFixedSize(80, 24);
    languageLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    languageComboBox = new QComboBox();
    languageComboBox->addItem(QIcon(":/images/language_english.png"), tr("English"), languageList.at(0));
    languageComboBox->addItem(QIcon(":/images/language_simplified_chinese.png"), tr("Simplified Chinese"), languageList.at(1));

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->setContentsMargins(2, 2, 2, 2);
    hLayout->setSpacing(4);
    hLayout->addWidget(languageLabel, Qt::AlignVCenter);
    hLayout->addWidget(languageComboBox, Qt::AlignVCenter);
    return hLayout;
}

QLayout *StackConfigFrame::initSkinLayout()
{
    QLabel *skinLabel = new QLabel(tr("Skin"));
    skinLabel->setFixedSize(80, 24);
    skinLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    skinLabel->hide();

    skinComboBox = new QComboBox();
    skinComboBox->addItem(tr("Default"), QString("default"));
    skinComboBox->hide();

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->setContentsMargins(2, 2, 2, 2);
    hLayout->setSpacing(4);
    hLayout->addWidget(skinLabel, Qt::AlignVCenter);
    hLayout->addWidget(skinComboBox, Qt::AlignVCenter);
    return hLayout;
}

QLayout *StackConfigFrame::initExitLayout()
{
    QLabel *exitLabel = new QLabel(tr("Close Button"));
    exitLabel->setFixedSize(80, 24);
    exitLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    exitRadioButton = new QRadioButton(tr("Exit program"));
    hideRadioButton = new QRadioButton(tr("Hide to system tray"));

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->setContentsMargins(2, 2, 2, 2);
    hLayout->setSpacing(4);
    hLayout->addWidget(exitLabel, Qt::AlignVCenter);
    hLayout->addWidget(exitRadioButton, Qt::AlignVCenter);
    hLayout->addWidget(hideRadioButton, Qt::AlignVCenter);
    return hLayout;
}

QLayout *StackConfigFrame::initReturnLayout()
{
    returnButton = new QPushButton(QIcon(":/images/btn_return.png"), tr("Return"));
    returnButton->setToolTip(tr("Return to picker dialog"));
    returnButton->setFixedSize(80, 24);
    returnButton->setObjectName("returnButton");

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->setContentsMargins(2, 2, 2, 2);
    hLayout->setSpacing(4);
    hLayout->addStretch();
    hLayout->addWidget(returnButton, Qt::AlignVCenter);
    return hLayout;
}

void StackConfigFrame::initConnect()
{
    connect(returnButton, &QPushButton::clicked, this, &StackConfigFrame::slotShowPickerWidget);

    connect(languageComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            [this](){ AppConfig::setLanguage(this->languageComboBox->currentData().toString());
                      this->parentWidget()->hide();
                      this->parentWidget()->show();
                    });

    connect(skinComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            [this](){AppConfig::setLanguage(this->skinComboBox->currentData().toString());});

    connect(exitRadioButton, &QRadioButton::clicked, this, &StackConfigFrame::slotSetExitOrHide);
    connect(hideRadioButton, &QRadioButton::clicked, this, &StackConfigFrame::slotSetExitOrHide);
}

void StackConfigFrame::loadConfig()
{
    QString language = AppConfig::getLanguage();
    languageComboBox->setCurrentIndex(languageList.indexOf(language.toLower()));

    QString skin = AppConfig::getSkin();
    skinComboBox->setCurrentIndex(skinList.indexOf(skin.toLower()));

    if (0 == QString::compare(AppConfig::getExit(), "exit", Qt::CaseInsensitive))
    {
        exitRadioButton->setChecked(true);
    }
    else if (0 == QString::compare(AppConfig::getExit(), "hide", Qt::CaseInsensitive))
    {
        hideRadioButton->setChecked(true);
    }
}
