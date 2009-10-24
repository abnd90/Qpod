#ifndef YOUTUBE_H
#define YOUTUBE_H
#include <string>
#include <QString>
#include "ui_youtube.h"
#include "videodialog.h"

std::string getYoutubeVideo(std::string& yUrl);

class YoutubeDialog : public QDialog, public Ui::YoutubeDialog
{
    Q_OBJECT

public:
    YoutubeDialog(QWidget *parent=0);
    static std::string yUrl;
private slots:
    void setUrl(QString);
    void dloadYtube();
};



#endif // YOUTUBE_H
