/********************************************************************************
** Form generated from reading ui file 'propertiesdialog.ui'
**
** Created: Sat Oct 24 13:44:05 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PROPERTIESDIALOG_H
#define UI_PROPERTIESDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_PropertiesDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *AlbumArt;
    QDialogButtonBox *buttonBox;
    QLabel *AlbumLabel;
    QLabel *ArtistLabel;
    QLabel *TitleLabel;
    QLineEdit *ArtistBox;
    QLineEdit *TitleBox;
    QLineEdit *AlbumBox;

    void setupUi(QDialog *PropertiesDialog)
    {
        if (PropertiesDialog->objectName().isEmpty())
            PropertiesDialog->setObjectName(QString::fromUtf8("PropertiesDialog"));
        PropertiesDialog->resize(409, 178);
        gridLayout = new QGridLayout(PropertiesDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        AlbumArt = new QLabel(PropertiesDialog);
        AlbumArt->setObjectName(QString::fromUtf8("AlbumArt"));
        AlbumArt->setMinimumSize(QSize(128, 128));

        gridLayout->addWidget(AlbumArt, 0, 0, 5, 1);

        buttonBox = new QDialogButtonBox(PropertiesDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 2, 1, 1);

        AlbumLabel = new QLabel(PropertiesDialog);
        AlbumLabel->setObjectName(QString::fromUtf8("AlbumLabel"));

        gridLayout->addWidget(AlbumLabel, 3, 1, 1, 1);

        ArtistLabel = new QLabel(PropertiesDialog);
        ArtistLabel->setObjectName(QString::fromUtf8("ArtistLabel"));

        gridLayout->addWidget(ArtistLabel, 2, 1, 1, 1);

        TitleLabel = new QLabel(PropertiesDialog);
        TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));

        gridLayout->addWidget(TitleLabel, 1, 1, 1, 1);

        ArtistBox = new QLineEdit(PropertiesDialog);
        ArtistBox->setObjectName(QString::fromUtf8("ArtistBox"));

        gridLayout->addWidget(ArtistBox, 2, 2, 1, 1);

        TitleBox = new QLineEdit(PropertiesDialog);
        TitleBox->setObjectName(QString::fromUtf8("TitleBox"));

        gridLayout->addWidget(TitleBox, 1, 2, 1, 1);

        AlbumBox = new QLineEdit(PropertiesDialog);
        AlbumBox->setObjectName(QString::fromUtf8("AlbumBox"));

        gridLayout->addWidget(AlbumBox, 3, 2, 1, 1);


        retranslateUi(PropertiesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PropertiesDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PropertiesDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PropertiesDialog);
    } // setupUi

    void retranslateUi(QDialog *PropertiesDialog)
    {
        PropertiesDialog->setWindowTitle(QApplication::translate("PropertiesDialog", "Track Properties", 0, QApplication::UnicodeUTF8));
        AlbumArt->setText(QApplication::translate("PropertiesDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Bitstream Vera Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/images/no-cover-art.jpg\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        AlbumLabel->setText(QApplication::translate("PropertiesDialog", "Album:", 0, QApplication::UnicodeUTF8));
        ArtistLabel->setText(QApplication::translate("PropertiesDialog", "Artist:", 0, QApplication::UnicodeUTF8));
        TitleLabel->setText(QApplication::translate("PropertiesDialog", "Title:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(PropertiesDialog);
    } // retranslateUi

};

namespace Ui {
    class PropertiesDialog: public Ui_PropertiesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTIESDIALOG_H
