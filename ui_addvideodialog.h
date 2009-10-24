/********************************************************************************
** Form generated from reading ui file 'addvideodialog.ui'
**
** Created: Sat Oct 24 10:22:17 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ADDVIDEODIALOG_H
#define UI_ADDVIDEODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddVideoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *inputlabel;
    QTextEdit *inputfile;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *typelabel;
    QComboBox *videotype;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *convertCbox;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *conversion_label;
    QProgressBar *conversion_bar;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *convertbutton;
    QPushButton *cancelbutton;

    void setupUi(QDialog *AddVideoDialog)
    {
        if (AddVideoDialog->objectName().isEmpty())
            AddVideoDialog->setObjectName(QString::fromUtf8("AddVideoDialog"));
        AddVideoDialog->resize(560, 120);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddVideoDialog->sizePolicy().hasHeightForWidth());
        AddVideoDialog->setSizePolicy(sizePolicy);
        AddVideoDialog->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(AddVideoDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        inputlabel = new QLabel(AddVideoDialog);
        inputlabel->setObjectName(QString::fromUtf8("inputlabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(inputlabel->sizePolicy().hasHeightForWidth());
        inputlabel->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(inputlabel);

        inputfile = new QTextEdit(AddVideoDialog);
        inputfile->setObjectName(QString::fromUtf8("inputfile"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(inputfile->sizePolicy().hasHeightForWidth());
        inputfile->setSizePolicy(sizePolicy2);
        inputfile->setMinimumSize(QSize(0, 0));
        inputfile->setMaximumSize(QSize(16777215, 30));
        inputfile->setBaseSize(QSize(0, 0));
        inputfile->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        inputfile->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        inputfile->setLineWrapMode(QTextEdit::NoWrap);
        inputfile->setReadOnly(true);
        inputfile->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(inputfile);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        typelabel = new QLabel(AddVideoDialog);
        typelabel->setObjectName(QString::fromUtf8("typelabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(typelabel->sizePolicy().hasHeightForWidth());
        typelabel->setSizePolicy(sizePolicy3);

        horizontalLayout_3->addWidget(typelabel);

        videotype = new QComboBox(AddVideoDialog);
        videotype->setObjectName(QString::fromUtf8("videotype"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(videotype->sizePolicy().hasHeightForWidth());
        videotype->setSizePolicy(sizePolicy4);
        videotype->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        videotype->setMinimumContentsLength(10);

        horizontalLayout_3->addWidget(videotype);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        convertCbox = new QCheckBox(AddVideoDialog);
        convertCbox->setObjectName(QString::fromUtf8("convertCbox"));
        convertCbox->setChecked(false);

        horizontalLayout_3->addWidget(convertCbox);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        conversion_label = new QLabel(AddVideoDialog);
        conversion_label->setObjectName(QString::fromUtf8("conversion_label"));
        conversion_label->setEnabled(true);

        horizontalLayout->addWidget(conversion_label);

        conversion_bar = new QProgressBar(AddVideoDialog);
        conversion_bar->setObjectName(QString::fromUtf8("conversion_bar"));
        conversion_bar->setEnabled(false);
        conversion_bar->setMaximumSize(QSize(16777215, 20));
        conversion_bar->setValue(24);
        conversion_bar->setTextVisible(false);

        horizontalLayout->addWidget(conversion_bar);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        convertbutton = new QPushButton(AddVideoDialog);
        convertbutton->setObjectName(QString::fromUtf8("convertbutton"));

        horizontalLayout->addWidget(convertbutton);

        cancelbutton = new QPushButton(AddVideoDialog);
        cancelbutton->setObjectName(QString::fromUtf8("cancelbutton"));

        horizontalLayout->addWidget(cancelbutton);


        verticalLayout->addLayout(horizontalLayout);

#ifndef QT_NO_SHORTCUT
        inputlabel->setBuddy(inputfile);
        typelabel->setBuddy(videotype);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(inputfile, videotype);

        retranslateUi(AddVideoDialog);
        QObject::connect(cancelbutton, SIGNAL(clicked()), AddVideoDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(AddVideoDialog);
    } // setupUi

    void retranslateUi(QDialog *AddVideoDialog)
    {
        AddVideoDialog->setWindowTitle(QApplication::translate("AddVideoDialog", "Convert Options", 0, QApplication::UnicodeUTF8));
        inputlabel->setText(QApplication::translate("AddVideoDialog", "Input Video", 0, QApplication::UnicodeUTF8));
        typelabel->setText(QApplication::translate("AddVideoDialog", "Video Type:", 0, QApplication::UnicodeUTF8));
        videotype->clear();
        videotype->insertItems(0, QStringList()
         << QApplication::translate("AddVideoDialog", "Movie", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddVideoDialog", "TV Show", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddVideoDialog", "Music Video", 0, QApplication::UnicodeUTF8)
        );
#ifndef QT_NO_TOOLTIP
        convertCbox->setToolTip(QApplication::translate("AddVideoDialog", "Convert into .mp4 and add", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        convertCbox->setText(QApplication::translate("AddVideoDialog", "Convert Video", 0, QApplication::UnicodeUTF8));
        conversion_label->setText(QApplication::translate("AddVideoDialog", "Conversion in progress   ", 0, QApplication::UnicodeUTF8));
        convertbutton->setText(QApplication::translate("AddVideoDialog", "Add", 0, QApplication::UnicodeUTF8));
        cancelbutton->setText(QApplication::translate("AddVideoDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(AddVideoDialog);
    } // retranslateUi

};

namespace Ui {
    class AddVideoDialog: public Ui_AddVideoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDVIDEODIALOG_H
