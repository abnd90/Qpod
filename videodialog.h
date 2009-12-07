#ifndef VIDEODIALOG_H
#define VIDEODIALOG_H
#include "ui_addvideodialog.h"
#include <QtGui>
#include <QProcess>
#include <QMessageBox>
#include "common.h"

class VideoDialog : public QDialog, public Ui::AddVideoDialog
{
    Q_OBJECT

public:
    VideoDialog(QWidget *parent=0);
    VideoDialog(const QString&,QWidget *parent=0);

private:
    QString filepath;
    QProcess process;
    void convertToMp4(QString filepath);
    Itdb_Track* track;

public slots:
    void open_video_dialog(const QString& fpath); //to be removed

private slots:
    void convertClicked();
    void alwaysChecked();
    void processError(QProcess::ProcessError);
    void processFinished(int, QProcess::ExitStatus);
    void displayError();
    void enableMore(QString);

signals:
    void conversionDone(const QString&,Itdb_Track*);
};
#endif // VIDEODIALOG_H
