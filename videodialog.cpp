#include "videodialog.h"

VideoDialog::VideoDialog(QWidget *parent):QDialog(parent)
{
    setupUi(this);
    connect(convertbutton,SIGNAL(clicked(bool)),this,SLOT(ConvertVideo()));
}

void VideoDialog::open_video_dialog(const QString& fpath)  //SLOT
{
    inputfile->setText(fpath);
    filepath=fpath;
    if(fpath.contains(".mp4"))
    {
        this->convertCbox->setCheckState(Qt::Unchecked);
    }
    else
    {
        this->convertCbox->setCheckState(Qt::Checked);
        connect(this->convertCbox,SIGNAL(clicked(bool)),this,SLOT(alwaysChecked()));     //readonly
    }
    conversion_label->hide();
    conversion_bar->hide();        //TODO implement progress bar
    this->show();
 }

void VideoDialog::ConvertVideo()
{
    QString videoType=this->videotype->currentText();
    Itdb_Mediatype type;
    if(videoType=="Movie")
        type=ITDB_MEDIATYPE_MOVIE;
    else if(videoType=="Music Video")
        type=ITDB_MEDIATYPE_MUSICVIDEO;
    else if(videoType=="TV Show")
        type=ITDB_MEDIATYPE_TVSHOW;


    if(this->convertCbox->isChecked())
         emit Conv_Done(ConvertVid(filepath),type);
    else
        emit Conv_Done(filepath,type);
    this->close();
}

void VideoDialog::alwaysChecked()
{
    this->convertCbox->setCheckState(Qt::Checked);
}
