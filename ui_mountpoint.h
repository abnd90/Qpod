/********************************************************************************
** Form generated from reading ui file 'mountpoint.ui'
**
** Created: Fri Oct 16 07:41:46 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MOUNTPOINT_H
#define UI_MOUNTPOINT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MountPoint
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MountPoint)
    {
        if (MountPoint->objectName().isEmpty())
            MountPoint->setObjectName(QString::fromUtf8("MountPoint"));
        MountPoint->resize(400, 105);
        verticalLayout = new QVBoxLayout(MountPoint);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(MountPoint);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        plainTextEdit = new QPlainTextEdit(MountPoint);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy);
        plainTextEdit->setMaximumSize(QSize(16777215, 30));
        plainTextEdit->setBaseSize(QSize(0, 0));
        plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);

        horizontalLayout->addWidget(plainTextEdit);

        pushButton = new QPushButton(MountPoint);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(MountPoint);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(MountPoint);
        QObject::connect(buttonBox, SIGNAL(rejected()), MountPoint, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), MountPoint, SLOT(accept()));

        QMetaObject::connectSlotsByName(MountPoint);
    } // setupUi

    void retranslateUi(QDialog *MountPoint)
    {
        MountPoint->setWindowTitle(QApplication::translate("MountPoint", "Set Mount Point", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MountPoint", "MountPoint :", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        Q_UNUSED(MountPoint);
    } // retranslateUi

};

namespace Ui {
    class MountPoint: public Ui_MountPoint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOUNTPOINT_H
