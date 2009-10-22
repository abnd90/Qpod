/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Thu Oct 22 13:18:32 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Quit;
    QAction *actionAbout_Qt;
    QAction *actionSet_Mount_Point;
    QAction *actionReload;
    QAction *actionAbout;
    QAction *actionAdd;
    QAction *actionConvert_and_Add;
    QAction *actionAdd_File;
    QAction *actionAdd_Folder;
    QAction *actionAlbum_View;
    QAction *actionArtist_View;
    QAction *actionList_View;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *ipodimg;
    QProgressBar *progressBar;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_About;
    QMenu *menu_Edit;
    QMenu *menuMovies;
    QMenu *menu_Music;
    QMenu *menu_View;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(765, 469);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        action_Quit = new QAction(MainWindow);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        actionSet_Mount_Point = new QAction(MainWindow);
        actionSet_Mount_Point->setObjectName(QString::fromUtf8("actionSet_Mount_Point"));
        actionReload = new QAction(MainWindow);
        actionReload->setObjectName(QString::fromUtf8("actionReload"));
        actionReload->setShortcutContext(Qt::ApplicationShortcut);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QString::fromUtf8("actionAdd"));
        actionConvert_and_Add = new QAction(MainWindow);
        actionConvert_and_Add->setObjectName(QString::fromUtf8("actionConvert_and_Add"));
        actionAdd_File = new QAction(MainWindow);
        actionAdd_File->setObjectName(QString::fromUtf8("actionAdd_File"));
        actionAdd_Folder = new QAction(MainWindow);
        actionAdd_Folder->setObjectName(QString::fromUtf8("actionAdd_Folder"));
        actionAlbum_View = new QAction(MainWindow);
        actionAlbum_View->setObjectName(QString::fromUtf8("actionAlbum_View"));
        actionArtist_View = new QAction(MainWindow);
        actionArtist_View->setObjectName(QString::fromUtf8("actionArtist_View"));
        actionList_View = new QAction(MainWindow);
        actionList_View->setObjectName(QString::fromUtf8("actionList_View"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setCursor(QCursor(Qt::ArrowCursor));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setMargin(11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 2, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout->setContentsMargins(15, -1, 0, -1);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        ipodimg = new QLabel(centralWidget);
        ipodimg->setObjectName(QString::fromUtf8("ipodimg"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ipodimg->sizePolicy().hasHeightForWidth());
        ipodimg->setSizePolicy(sizePolicy1);
        ipodimg->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(ipodimg);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy2);
        progressBar->setMaximumSize(QSize(120, 10));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        progressBar->setFont(font);
        progressBar->setValue(24);
        progressBar->setTextVisible(false);

        verticalLayout->addWidget(progressBar);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setBaseSize(QSize(0, 0));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        gridLayout->addLayout(verticalLayout, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(20, 13, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 5, 1, 1);

        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy3);
        tableWidget->setBaseSize(QSize(0, 0));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setTabKeyNavigation(false);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setGridStyle(Qt::DotLine);
        tableWidget->setSortingEnabled(true);
        tableWidget->setCornerButtonEnabled(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->verticalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(tableWidget, 2, 6, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 765, 22));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_About = new QMenu(menuBar);
        menu_About->setObjectName(QString::fromUtf8("menu_About"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
        menuMovies = new QMenu(menuBar);
        menuMovies->setObjectName(QString::fromUtf8("menuMovies"));
        menu_Music = new QMenu(menuBar);
        menu_Music->setObjectName(QString::fromUtf8("menu_Music"));
        menu_View = new QMenu(menuBar);
        menu_View->setObjectName(QString::fromUtf8("menu_View"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Edit->menuAction());
        menuBar->addAction(menu_View->menuAction());
        menuBar->addAction(menu_Music->menuAction());
        menuBar->addAction(menuMovies->menuAction());
        menuBar->addAction(menu_About->menuAction());
        menu_File->addAction(actionReload);
        menu_File->addAction(action_Quit);
        menu_About->addAction(actionAbout_Qt);
        menu_About->addAction(actionAbout);
        menu_Edit->addAction(actionSet_Mount_Point);
        menuMovies->addAction(actionAdd);
        menuMovies->addAction(actionConvert_and_Add);
        menu_Music->addAction(actionAdd_File);
        menu_Music->addAction(actionAdd_Folder);
        menu_View->addAction(actionAlbum_View);
        menu_View->addAction(actionArtist_View);
        menu_View->addAction(actionList_View);

        retranslateUi(MainWindow);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindow", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", 0, QApplication::UnicodeUTF8));
        actionSet_Mount_Point->setText(QApplication::translate("MainWindow", "Set Mount Point", 0, QApplication::UnicodeUTF8));
        actionReload->setText(QApplication::translate("MainWindow", "Reload", 0, QApplication::UnicodeUTF8));
        actionReload->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionAdd->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionAdd->setStatusTip(QApplication::translate("MainWindow", "Add a video", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionConvert_and_Add->setText(QApplication::translate("MainWindow", "Convert and Add", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionConvert_and_Add->setStatusTip(QApplication::translate("MainWindow", "Convert and add a video", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionAdd_File->setText(QApplication::translate("MainWindow", "Add File", 0, QApplication::UnicodeUTF8));
        actionAdd_Folder->setText(QApplication::translate("MainWindow", "Add Folder", 0, QApplication::UnicodeUTF8));
        actionAlbum_View->setText(QApplication::translate("MainWindow", "Album View", 0, QApplication::UnicodeUTF8));
        actionArtist_View->setText(QApplication::translate("MainWindow", "Artist View", 0, QApplication::UnicodeUTF8));
        actionList_View->setText(QApplication::translate("MainWindow", "List View", 0, QApplication::UnicodeUTF8));
        ipodimg->setText(QApplication::translate("MainWindow", "ipod icon goes here", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "No iPod Mounted", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Title", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Artist", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Album", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menu_About->setTitle(QApplication::translate("MainWindow", "&About", 0, QApplication::UnicodeUTF8));
        menu_Edit->setTitle(QApplication::translate("MainWindow", "&Edit", 0, QApplication::UnicodeUTF8));
        menuMovies->setTitle(QApplication::translate("MainWindow", "&Videos", 0, QApplication::UnicodeUTF8));
        menu_Music->setTitle(QApplication::translate("MainWindow", "&Music", 0, QApplication::UnicodeUTF8));
        menu_View->setTitle(QApplication::translate("MainWindow", "&View", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
