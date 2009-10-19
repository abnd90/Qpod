#ifndef VIDEODIALOG_H
#define VIDEODIALOG_H
#include "ui_addvideodialog.h"
#include <QtGui>

#include "common.h"


class VideoDialog : public QDialog, public Ui::AddVideoDialog
{
    Q_OBJECT

public:
    VideoDialog(QWidget *parent=0);

private:
    QString filepath;
    void setfname(void);
private slots:
    void open_video_dialog(const QString& fpath);
    void ConvertVideo(void);
signals:
    void Conv_Done(const QString&);
};
#endif // VIDEODIALOG_H
