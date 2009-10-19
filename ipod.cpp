#include "ipod.h"
//#include <iostream>


Ipod::Ipod()
{
   mountpoint="/media/ABHINANDH'S";
}

void Ipod::builddb(void)
{
  bool dbvalid=mpexists();
  if(dbvalid)
    {
        if(database)
            itdb_free(database);
        database=itdb_parse(mountpoint.toLatin1(),NULL);
        ipodinfo=itdb_device_get_ipod_info(database->device);
        tracks=NULL;
        tracks=(GList *)database->tracks;
   }
}

bool Ipod::mpexists(void)
{
    Itdb_iTunesDB* tmp;
    struct stat st;                   //check if mountpoint exists
    if(stat(mountpoint.toLatin1(),&st)==0)
    {
        if((tmp=itdb_parse(mountpoint.toLatin1(),NULL))!=NULL)
        {
            itdb_free(tmp);
            return 1;
        }
    }

    return 0;
}

Ipod::~Ipod()
{
    if(database)
       itdb_free(database);
}

int Ipod::usedspaceperc(void)
{
  struct statvfs fs;
  statvfs(mountpoint.toLatin1(),&fs);
  int totalsize=(fs.f_blocks*fs.f_frsize)/1024;
  int freesize=(fs.f_bfree*fs.f_frsize)/1024;
  int usedsize=totalsize-freesize;
  return ((float)usedsize/totalsize)*100;
}

void Ipod::Add_Video(const QString& fp)
{
    Itdb_Track* video=itdb_track_new();

    video->mediatype=ITDB_MEDIATYPE_MOVIE;  //set media type before calling SetTags
    SetTags(video,fp);

    video->itdb=database;
    video->filetype =g_strdup( "m4v video" );
    //write to DB and copy to ipod
    itdb_cp_track_to_ipod(video,g_strdup(fp.toLatin1()),NULL);
    itdb_track_add(database,video,-1);

    //add to master playlist
    Itdb_Playlist *mpl = itdb_playlist_mpl(database);
    itdb_playlist_add_track(mpl, video, -1);
    //write the DB
    itdb_write(database,NULL);

}

void Ipod::SetMountPoint(const QString& mp)
{
    mountpoint=mp;
}

bool Ipod::SupportsVideo(void)
{
    return itdb_device_supports_video(database->device);
}

void Ipod::AddTrack(const QString& fp)
{
    Itdb_Track* track=itdb_track_new();
    track->mediatype=ITDB_MEDIATYPE_AUDIO;
    SetTags(track,fp);

    track->itdb=database;
    track->filetype =g_strdup( "audio file" );
    //write to DB and copy to ipod
    itdb_cp_track_to_ipod(track,g_strdup(fp.toLatin1()),NULL);
    itdb_track_add(database,track,-1);

    //add to master playlist
    Itdb_Playlist *mpl = itdb_playlist_mpl(database);
    itdb_playlist_add_track(mpl, track, -1);
    //write the DB
    itdb_write(database,NULL);
    emit AddedTrack();
}

void Ipod::AddTrack(Itdb_Track* track,const QString& fp)
{
    track->mediatype=ITDB_MEDIATYPE_AUDIO;
    SetTags(track,fp);
    track->itdb=database;
    track->filetype =g_strdup( "audio file" );
    //write to DB and copy to ipod
    itdb_cp_track_to_ipod(track,g_strdup(fp.toLatin1()),NULL);
    itdb_track_add(database,track,-1);

    //add to master playlist
    Itdb_Playlist *mpl = itdb_playlist_mpl(database);
    itdb_playlist_add_track(mpl, track, -1);
    //write the DB
    itdb_write(database,NULL);
}

void Ipod::AddFolder(const QString& fp)
{
   QDir dir(fp);
   QStringList filters;
   filters << "*.mp3" << "*.aac";

   QStringList list;
   list=dir.entryList(filters,QDir::Files);

   QList<QString>::iterator i;
   Itdb_Track* track[list.count()];
   int j=0;
   for (i = list.begin();j<list.count(); ++i,j++)
   {
      QString abspath=fp+"/"+*i;
      track[j]=itdb_track_new();
      AddTrack(track[j],abspath);
   }


   emit AddedTrack();
}


