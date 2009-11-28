#include "common.h"



void SetTags(Itdb_Track* track,const QString fp)
{
    QFile tfile(fp);
    track->size=tfile.size();

    QString filename=QFileInfo(fp).fileName();
    filename.chop(4);


    TagLib::String title;
    if( track->mediatype != ITDB_MEDIATYPE_MOVIE && track->mediatype != ITDB_MEDIATYPE_MUSICVIDEO && track->mediatype != ITDB_MEDIATYPE_TVSHOW )
    {
            TagLib::FileRef f(fp.toLatin1());                //Audio file

            if(!f.isNull())
            {
                 TagLib::String title= f.tag()->title();

                 if(title.isEmpty())               //if title is empty, set filename as title
                 {
                    title=filename.toStdString();
                    f.tag()->setTitle(title);
                    f.save();
                }

                  track->title= g_strdup(title.to8Bit(true).c_str());
                  track->album= g_strdup(f.tag()->album().to8Bit(true).c_str());
                  track->artist= g_strdup(f.tag()->artist().to8Bit(true).c_str());
                  track->comment = g_strdup(f.tag()->comment().to8Bit(true).c_str());
                  track->year = f.tag()->year();
                  track->genre= g_strdup(f.tag()->genre().to8Bit(true).c_str());
                  track->tracklen=f.audioProperties()->length()*1000;
                  track->filetype =g_strdup( "mp3" );
                  track->bitrate =f.audioProperties()->bitrate();
                  track->samplerate =f.audioProperties()->sampleRate();
                  track->filetype_marker=0;
                  //album art

              }
        }
    else               //Movie file
    {
        MP4FileHandle file = MP4Modify(fp.toLatin1() , MP4_DETAILS_ERROR, 0 );       //libmp4v2
        title=filename.toStdString();
        if( file != MP4_INVALID_FILE_HANDLE )
        {
            u_int32_t numTracks = MP4GetNumberOfTracks(file);       //adapted from amarok
            for (u_int32_t i = 0; i < numTracks; i++)
            {
                  MP4TrackId trackId = MP4FindTrackId(file, i);

                  const char* trackType =MP4GetTrackType(file, trackId);

                 if (!strcmp(trackType, MP4_AUDIO_TRACK_TYPE))
                 {
                     MP4Duration trackDuration =
                                      MP4GetTrackDuration(file, trackId);
                     double msDuration =MP4ConvertFromTrackDuration(file, trackId,
                                            trackDuration, MP4_MSECS_TIME_SCALE);

                     track->tracklen=(int)(msDuration);
                  }
               }

             MP4Close( file );
        }
        track->movie_flag = 0x01;
        track->remember_playback_position=0x01;
        track->title= g_strdup(title.to8Bit(true).c_str());
    }
    tfile.close();
}

bool DeleteFile(const QString & name)
{
    QFile del(name);
    return del.remove();
}

double usedSpace(const QString& path)
{
    qlonglong size=0;
    QDir dir(path);
    foreach (QString file, dir.entryList(QDir::Files))
        size += QFileInfo(dir, file).size();
    foreach (QString subdir, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
        size += usedSpace( path + QDir::separator() + subdir);

    return size;
}

