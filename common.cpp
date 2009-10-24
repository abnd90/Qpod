#include "common.h"

QString ConvertVid(QString filepath)                    //TODO VERY dirty conversion process, needs to be redone
{
    QString filename(FnamefrmPath(filepath));

    QString command;

        command.append("ffmpeg -y -i \"");
        command.append(filepath.toLatin1());
        command.append("\"");
        command.append(" -f mp4 \
-acodec libfaac -ar 48000 -ab 160 \
-vcodec mpeg4 -maxrate 2000 -b 1500 \
-qmin 3 -qmax 5 -bufsize 4096 -g 300 \
-s 320x240 -r 30000/1001 \"/tmp/");
        command.append(filename.toLatin1());
        command.append(".mp4");
        command.append("\"");

        system(command.toLatin1());
        QString ret;
        ret.append("/tmp/");
        ret.append(filename);
        ret.append(".mp4");

        return ret;
   }

QString FnamefrmPath(QString filepath)
{
    QString filename(filepath);
    filename.chop(4);
    int repeat=filename.count('/',Qt::CaseInsensitive),toremove=0;
    QString::iterator pro=filename.begin(); //count no of '/'

    for(int i=0;i!=repeat;++pro)  //count no of chars upto the last '/'
    {
        if(*pro=='/')
            ++i;
        ++toremove;
    }
    filename.remove(0,toremove);

return filename;
}

void SetTags(Itdb_Track* track,const QString fp)
{
    QFile tfile(fp);
    track->size=tfile.size();

    TagLib::String title;
    if( track->mediatype != ITDB_MEDIATYPE_MOVIE && track->mediatype != ITDB_MEDIATYPE_MUSICVIDEO && track->mediatype != ITDB_MEDIATYPE_TVSHOW )
    {
            TagLib::FileRef f(fp.toLatin1());                //Audio file

            if(!f.isNull())
            {
                 TagLib::String title= f.tag()->title();

                 if(title.isEmpty())               //if title is empty, set filename as title
                 {
                    title=FnamefrmPath(fp).toStdString();
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
        title=FnamefrmPath(fp).toStdString();
        if( file != MP4_INVALID_FILE_HANDLE )
        {
            //const MP4Tags* tags = MP4TagsAlloc();
            //MP4TagsFetch( tags, file );
            //if( tags->name )                 //set title if the tag has it
            //    title=tags->name;
            u_int32_t numTracks = MP4GetNumberOfTracks(file);       //copied from amarok
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

             //MP4TagsFree( tags );
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
