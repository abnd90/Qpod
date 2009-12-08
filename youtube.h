#ifndef YOUTUBE_H
#define YOUTUBE_H
#include <QString>
#include <QDialog>
#include <QUrl>
#include <QtNetwork>
#include "ui_youtube.h"
//#include <string>

//#include "videodialog.h"
//
//std::string getYoutubeVideo(std::string& yUrl);
//
//
class Youtube : public QDialog, public Ui::YoutubeDialog
{
    Q_OBJECT

private:
    QUrl* pageUrl;
    QUrl downloadUrl;
    QUrl getDownloadLink(QUrl*);
private slots:
    void handleNetworkReply(QNetworkReply*);

public:
    Youtube(QWidget *parent=0);
    Youtube(QUrl* url,QWidget *parent=0);
};



#endif // YOUTUBE_H
