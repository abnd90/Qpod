#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QMessageBox>
#include <QPicture>
#include <QFileDialog>
#include <QString>
#include "ipod.h"
#include "videodialog.h"
#include "propertiesdialog.h"
#include "youtube.h"


namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void initTable();

private slots:
    void reload();
    void about();
    void actionVideoAdd();
    void addFile();
    void addFolder();
    void setMP();
    void showProperties();
    void deleteTrack();
    void addYoutube();
    void searchTracks();
    void searchDone(QString);

private:
    Ui::MainWindow *ui;
    Itdb_Track* getTrack(QTreeWidgetItem *);
    void createContextMenu();
    void createActions();
    void createToolbars();
    QString tmp;
    QAction *actionProperties;
    QAction *actionDelete;
    QToolBar *fileToolbar;
    QToolBar *musicToolbar;
    QToolBar *videoToolbar;
    QToolBar *searchToolbar;
    QLineEdit *searchBox;
    PropertiesDialog* propertyDialog;
};



#endif // MAINWINDOW_H
