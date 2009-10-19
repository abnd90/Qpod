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
    conversion_label->hide();
    conversion_bar->hide();        //TODO implement progress bar
    this->show();
 }

void VideoDialog::ConvertVideo()
{
    emit Conv_Done(ConvertVid(filepath));
    this->hide();
}
