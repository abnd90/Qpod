#include "videodialog.h"
#include "ipod.h"
#include <iostream>

extern Ipod ipod;

VideoDialog::VideoDialog(QWidget *parent):QDialog(parent)
{
}

VideoDialog::VideoDialog(const QString& fpath,QWidget *parent):QDialog(parent)
{
    setupUi(this);
    hiddengbox->hide();
    progressBar->hide();
    progressLabel->hide();
    connect(convertbutton,SIGNAL(clicked(bool)),this,SLOT(convertClicked()));
    connect(this, SIGNAL(conversionDone(const QString&,Itdb_Track*)),&ipod, SLOT(addVideo(const QString&,Itdb_Track*)));
    connect(&process,SIGNAL(readyReadStandardError()),this, SLOT(displayError()));
    connect(&process,SIGNAL(finished(int, QProcess::ExitStatus)),
            this, SLOT(processFinished(int, QProcess::ExitStatus)));
    connect(&process,SIGNAL(error(QProcess::ProcessError)),this,
            SLOT(processError(QProcess::ProcessError)));
    connect(videotype,SIGNAL(currentIndexChanged(QString)),this,SLOT(enableMore(QString)));
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
    inputfile->setText(fpath);
    filepath=fpath;
    if(fpath.contains(".mp4"))
    {
        this->convertCbox->setCheckState(Qt::Unchecked);
    }
    else
    {
        this->convertCbox->setCheckState(Qt::Checked);
        connect(this->convertCbox,SIGNAL(clicked(bool)),this,SLOT(alwaysChecked()));
    }

    this->show();
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

    this->show();
 }

void VideoDialog::convertClicked()
{
    convertbutton->setEnabled(0);
    track=itdb_track_new();
    QString videoType=this->videotype->currentText();
    QString filename=QFileInfo(filepath).fileName();
        filename.chop(4);
    track->title=g_strdup(filename.toLatin1());
    if(videoType=="Movie")
        track->mediatype=ITDB_MEDIATYPE_MOVIE;
    else if(videoType=="Music Video")
    {
        track->mediatype=ITDB_MEDIATYPE_MUSICVIDEO;
        track->title=g_strdup(lineEdit1->text().toLatin1());
        track->artist=g_strdup(lineEdit2->text().toLatin1());
        track->album=g_strdup(lineEdit3->text().toLatin1());
    }

    else if(videoType=="TV Show")
        track->mediatype=ITDB_MEDIATYPE_TVSHOW;


    if(this->convertCbox->isChecked())
    {
        convertToMp4(filepath);
    }
    else
    {
        progressBar->show();
        progressLabel->show();
        progressLabel->setText("Adding video...");
        emit conversionDone(filepath,track);
        this->close();
    }
}

void VideoDialog::alwaysChecked()
{
    this->convertCbox->setCheckState(Qt::Checked);
}

void VideoDialog::convertToMp4(QString filepath)                    //VERY dirty conversion process, needs to be redone using ffmpeg api
{
    QString filename=QFileInfo(filepath).fileName();
    QStringList args;
    filename.chop(4);

    args<<"-y"<<"-i"<<filepath;
    args<<"-f"<<"mp4"<<"-acodec"<<"libfaac"<<"-ar"<<"48000"<<"-ab"<<"160"<<"-vcodec"<<"mpeg4"<<"-maxrate"<<"2000"<<"-b"<<"1500"<<"-qmin"<<"3"<<"-qmax"<<"5"<<"-bufsize"<<"4096"<<"-g"<<"300"<<"-s"<<"320x240"<<"-r"<<"30000/1001";
    args<<"/tmp/"+filename+".mp4";

    progressBar->show();
    progressLabel->show();
    progressLabel->setText("Converting video...");
    process.start("ffmpeg",args);

    if(filepath.contains("/tmp/"))          //delete if tmp file
          DeleteFile(filepath);  //youtube video's get downloaded into /tmp/
}

void VideoDialog::processError(QProcess::ProcessError error)
{
    if(error == QProcess::FailedToStart)
        QMessageBox::critical(this, "Convert failed", "Error: ffmpeg not found. Install ffmpeg for video conversion support.",QMessageBox::NoButton,QMessageBox::Default|QMessageBox::Ok);

    this->close();
}

void VideoDialog::processFinished(int exitcode, QProcess::ExitStatus status)
{
    if( exitcode != 0 )
        QMessageBox::warning(this, "Convert failed", "Conversion to .mp4 failed, Video not added to iPod",QMessageBox::NoButton,QMessageBox::Default|QMessageBox::Ok);
    else
    {
        QString filename=QFileInfo(filepath).fileName();
        filename.chop(4);
        emit conversionDone("/tmp/"+filename+".mp4",track);
    }

    this->close();
}

void VideoDialog::displayError()
{
    QString error(process.readAllStandardError());
    std::cerr<<error.toStdString();
}

void VideoDialog::enableMore(QString value)
{
    if(value=="Music Video")
    {
        morebutton->setEnabled(1);
        QString filename=QFileInfo(filepath).fileName();
        filename.chop(4);
        lineEdit1->setText(filename);
    }
    else
        morebutton->setEnabled(0);
}
