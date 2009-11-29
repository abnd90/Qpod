#include "videodialog.h"
#include "ipod.h"

extern Ipod ipod;

VideoDialog::VideoDialog(QWidget *parent):QDialog(parent)
{
}

VideoDialog::VideoDialog(const QString& fpath,QWidget *parent):QDialog(parent)
{
    setupUi(this);
    connect(convertbutton,SIGNAL(clicked(bool)),this,SLOT(convertClicked()));
    connect(this, SIGNAL(conversionDone(const QString&,Itdb_Mediatype)),&ipod, SLOT(Add_Video(const QString&,Itdb_Mediatype)));

    connect(&process,SIGNAL(readyReadStandardError()),this, SLOT(displayError()));
    connect(&process,SIGNAL(finished(int, QProcess::ExitStatus)),
            this, SLOT(processFinished(int, QProcess::ExitStatus)));
    connect(&process,SIGNAL(error(QProcess::ProcessError)),this, SLOT(processError(QProcess::ProcessError)));

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
    QString videoType=this->videotype->currentText();

    if(videoType=="Movie")
        type=ITDB_MEDIATYPE_MOVIE;
    else if(videoType=="Music Video")
        type=ITDB_MEDIATYPE_MUSICVIDEO;
    else if(videoType=="TV Show")
        type=ITDB_MEDIATYPE_TVSHOW;


    if(this->convertCbox->isChecked())
    {
        convertToMp4(filepath);
    }
    else
    {
        emit conversionDone(filepath,type);
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
        emit conversionDone("/tmp/"+filename+".mp4",type);
    }

    this->close();
}

void VideoDialog::displayError()
{
    QString error(process.readAllStandardError());
    std::cerr<<error.toStdString();
}
