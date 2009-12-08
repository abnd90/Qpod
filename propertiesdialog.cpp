#include "propertiesdialog.h"
#include <iostream>
#include "ipod.h"
extern Ipod ipod;

PropertiesDialog::PropertiesDialog(QWidget *parent):QDialog(parent)
{
    setupUi(this);
    QObject::connect(AlbumBox,SIGNAL(textEdited(QString)),this,SLOT(propChanged()));
    QObject::connect(ArtistBox,SIGNAL(textEdited(QString)),this,SLOT(propChanged()));
    QObject::connect(TitleBox,SIGNAL(textEdited(QString)),this,SLOT(propChanged()));
    QObject::connect(localsetButton,SIGNAL(clicked()),this,SLOT(setCover()));
    QObject::connect(removeButton,SIGNAL(clicked()),this,SLOT(removeCover()));
    QObject::connect(this,SIGNAL(accepted()),this,SLOT(write()));
    coverChanged=false;
}

void PropertiesDialog::display(Itdb_Track* track)
{
    currentTrack=track;

    this->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(0);
    this->buttonBox->button(QDialogButtonBox::Apply);
    if(itdb_track_has_thumbnails(track))
    {
        GdkPixbuf* cover=(GdkPixbuf*)itdb_track_get_thumbnail(track,128,128);
        gdk_pixbuf_save (cover, "tmpcover", "jpeg", NULL,
                         "quality", "100", NULL);

        AlbumArt->setPixmap(QPixmap("tmpcover"));
    }
    else
        AlbumArt->setPixmap(QPixmap(":/images/no-cover-art.jpg"));

    AlbumBox->setText(QString(track->album));
    ArtistBox->setText(QString(track->artist));
    TitleBox->setText(QString(track->title));
    this->show();
}

void PropertiesDialog::propChanged()
{
    this->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(1);
}

void PropertiesDialog::write()
{
    ipod.DBchanged=true;
    itdb_track_unlink(currentTrack);
    currentTrack->album=g_strdup(AlbumBox->text().toLatin1());
    currentTrack->artist=g_strdup(ArtistBox->text().toLatin1());
    currentTrack->title=g_strdup(TitleBox->text().toLatin1());
    if(coverChanged)
    {
        itdb_track_remove_thumbnails(currentTrack);
        AlbumArt->pixmap()->save("tmpcover","JPG",100);
        itdb_track_set_thumbnails_from_pixbuf(currentTrack,gdk_pixbuf_new_from_file("tmpcover",NULL));
        coverChanged=false;
    }
    itdb_track_add(ipod.currDB(),currentTrack,-1);
    emit modified();
}

void PropertiesDialog::setCover()
{
    QString filename=QFileDialog::getOpenFileName(this,"Select an image","/home","Images (*.png *.jpg *.jpeg *.gif)");
    if(!filename.isNull())
    {
        QPixmap pic=QPixmap(filename).scaled(128,128,Qt::IgnoreAspectRatio);
        AlbumArt->setPixmap(pic);
        propChanged();
        coverChanged=true;
    }
}

void PropertiesDialog::removeCover()
{
    itdb_track_remove_thumbnails(currentTrack);
    AlbumArt->setPixmap(QPixmap(":/images/no-cover-art.jpg"));
    propChanged();
}

