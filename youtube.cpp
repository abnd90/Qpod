#include "youtube.h"

#include <curl/curl.h>
#include <fstream>
#include <cstdlib>
#include "ipod.h"

extern Ipod ipod;

using namespace std;
static int writeFunc(char *buffer, size_t size, size_t nmemb, std::string *writerData);

string getDLlinks();
string getTitle();

std::string YoutubeDialog::yUrl;

string getYoutubeVideo(string& yUrl)
{
        curl_global_init(CURL_GLOBAL_ALL);
        CURL *dlhandle = curl_easy_init();

        fstream file;
        file.open("tmp",ios::in|ios::out|ios::trunc);

        string Data;
        string url="http://www.youtubevdl.110mb.com/?url=";
        url+=yUrl;

        curl_easy_setopt(dlhandle, CURLOPT_URL,url.c_str());
        curl_easy_setopt(dlhandle, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(dlhandle, CURLOPT_WRITEFUNCTION, writeFunc);
        curl_easy_setopt(dlhandle, CURLOPT_WRITEDATA, &Data);
        curl_easy_perform(dlhandle);
        curl_easy_cleanup(dlhandle);

        file<<Data;
        string Url=getDLlinks();

        file.close();
        string ytdata;
        CURL *ythandle = curl_easy_init();
        curl_easy_setopt(ythandle, CURLOPT_URL,yUrl.c_str());
        curl_easy_setopt(ythandle, CURLOPT_WRITEFUNCTION, writeFunc);
        curl_easy_setopt(ythandle, CURLOPT_WRITEDATA, &ytdata);
        curl_easy_perform(ythandle);
        curl_easy_cleanup(ythandle);
        file.open("tmp",ios::in|ios::out|ios::trunc);
        file<<ytdata;
        file.close();
        string Title=getTitle();

        //got the url and title, Now download the actual video

        file.open(("/tmp/"+Title+".flv").c_str(),ios::in|ios::out|ios::trunc);

        string dFile;
    CURL *download = curl_easy_init();

    curl_easy_setopt(download, CURLOPT_URL,Url.c_str() );
    curl_easy_setopt(download, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(download, CURLOPT_WRITEFUNCTION, writeFunc);
    curl_easy_setopt(download, CURLOPT_WRITEDATA, &dFile);
    curl_easy_perform(download);
    curl_easy_cleanup(download);
    file<<dFile;

    return ("/tmp/"+Title+".flv");
}

static int writeFunc(char *data, size_t size, size_t nmemb, std::string *writerData)
{
    if (writerData == NULL)
        return 0;

        writerData->append(data, size*nmemb);

        return size * nmemb;
}


string getDLlinks()
{
    fstream file;
    file.open("tmp",ios::in|ios::out);

    string tmp;
    file.seekg(0,ios::end);
    fstream::pos_type end=file.tellg();
    file.seekg(0,ios::beg);
    QString link;
    while(file.tellg()!=end)
    {
        tmp.clear();
        getline(file,tmp);
        QString buff(tmp.c_str());
        if(buff.contains("<br /><br />"))
        {
            tmp.clear();
            getline(file,tmp);

            tmp.clear();
            getline(file,tmp);

            buff.clear();
            link=tmp.c_str();
            break;
        }
      }

    QString::iterator i=link.begin();
    QString URL;
    while(i != link.end())
    {
        if(*i=='\"')
        {  ++i;
           while(*i!='\"')
            {
                URL.append(*i);
                ++i;
            }
           break;
        }
        ++i;
    }
    return URL.toStdString();
}

string getTitle()
{
    fstream file;
    file.open("tmp",ios::in|ios::out);

    string tmp;
    file.seekg(0,ios::end);
    fstream::pos_type end=file.tellg();
    file.seekg(0,ios::beg);
    QString link;
    while(file.tellg()!=end)
    {
        tmp.clear();
        getline(file,tmp);
        QString buff(tmp.c_str());

        if(buff.contains("<title>"))
        {
            link=buff;
            break;
        }

      }

    link.remove("YouTube -");
    link.remove("<title>");
    link.remove("</title>");
    link=link.simplified();
    return link.toStdString();
}

YoutubeDialog::YoutubeDialog(QWidget *parent):QDialog(parent)
{
    setupUi(this);
    connect(this->download,SIGNAL(clicked()),this,SLOT(dloadYtube()));
    connect(this->download,SIGNAL(clicked()),this,SLOT(hide()));
    connect(this->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(setUrl(QString)));
}

void YoutubeDialog::setUrl(QString url)
{
    yUrl=url.toStdString();
}

void YoutubeDialog::dloadYtube()
{
    if(QString(yUrl.c_str()).contains("youtube.com"))
    {
        std::string fp=getYoutubeVideo(yUrl);
        VideoDialog *V=new VideoDialog;
        V->open_video_dialog(QString(fp.c_str()));
        connect(V, SIGNAL(Conv_Done(const QString&,Itdb_Mediatype)),&ipod, SLOT(Add_Video(const QString&,Itdb_Mediatype)));
    }
}
