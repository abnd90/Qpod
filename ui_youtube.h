/********************************************************************************
** Form generated from reading ui file 'youtube.ui'
**
** Created: Sat Oct 24 15:04:01 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_YOUTUBE_H
#define UI_YOUTUBE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_YoutubeDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *download;
    QPushButton *cancel;

    void setupUi(QDialog *YoutubeDialog)
    {
        if (YoutubeDialog->objectName().isEmpty())
            YoutubeDialog->setObjectName(QString::fromUtf8("YoutubeDialog"));
        YoutubeDialog->resize(351, 108);
        verticalLayout_2 = new QVBoxLayout(YoutubeDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(YoutubeDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(YoutubeDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        download = new QPushButton(YoutubeDialog);
        download->setObjectName(QString::fromUtf8("download"));

        horizontalLayout->addWidget(download);

        cancel = new QPushButton(YoutubeDialog);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        horizontalLayout->addWidget(cancel);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(YoutubeDialog);
        QObject::connect(cancel, SIGNAL(clicked()), YoutubeDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(YoutubeDialog);
    } // setupUi

    void retranslateUi(QDialog *YoutubeDialog)
    {
        YoutubeDialog->setWindowTitle(QApplication::translate("YoutubeDialog", "Add YouTube Video", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("YoutubeDialog", "Enter the YouTube URL:", 0, QApplication::UnicodeUTF8));
        download->setText(QApplication::translate("YoutubeDialog", "Download", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("YoutubeDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(YoutubeDialog);
    } // retranslateUi

};

namespace Ui {
    class YoutubeDialog: public Ui_YoutubeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YOUTUBE_H
