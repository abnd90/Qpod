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

                  track->title= g_strdup(title.toCString());
                  track->album= g_strdup(f.tag()->album().toCString());
                  track->artist= g_strdup(f.tag()->artist().toCString());
                  track->comment = g_strdup(f.tag()->comment().toCString());
                  track->year = f.tag()->year();
                  track->genre= g_strdup(f.tag()->genre().toCString());
                  track->tracklen=f.audioProperties()->length()*1000;

              }
        }
    else               //Movie file
    {
        track->movie_flag = 0x01;
        track->remember_playback_position=0x01;
        title=FnamefrmPath(fp).toStdString();
        track->title= g_strdup(title.toCString());
    }

}
