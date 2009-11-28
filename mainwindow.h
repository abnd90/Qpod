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
    void initTable(void);

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

private:
    Ui::MainWindow *ui;
    Itdb_Track* getTrack(int row,int col);
    void createContextMenu();
    void createActions();
    QString tmp;

    QAction *actionProperties;
    QAction *actionDelete;
    PropertiesDialog trackproperties;


};



#endif // MAINWINDOW_H
