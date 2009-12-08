#include "transferQueue.h"
#include "ipod.h"
#include <iostream>
extern Ipod ipod;

TransferQueue::TransferQueue(QWidget *parent):QTreeWidget(parent)
{
    this->setColumnCount(2);
    this->setHeaderLabels(QStringList()<<"Title"<<"Size");
    header()->setResizeMode(QHeaderView::ResizeToContents);
}

void TransferQueue::append(Itdb_Track *track)
{
    emit empty(0);
    if(isHidden())
        show();
    trackList.push_back(track);
    QTreeWidgetItem* tmpItem = new QTreeWidgetItem(QStringList()
                  << track->title << QVariant(track->size/(1024*1024)).toString()+" Mb");
    addTopLevelItem(tmpItem);
}

void TransferQueue::process()
{
    ipod.DBchanged=true;
    Itdb_Track* track;

            foreach(track,trackList)
    {
        //write to DB and copy to ipod
        QString* path=(QString*)track->userdata;
        track->userdata=NULL;
        itdb_cp_track_to_ipod(track,g_strdup(path->toLatin1()),NULL);
        itdb_track_add(ipod.currDB(),track,-1);

        //add to master playlist
        Itdb_Playlist *mpl = itdb_playlist_mpl(ipod.currDB());
        itdb_playlist_add_track(mpl,track, -1);
        takeTopLevelItem(0);
        QTreeWidgetItem* tmpItem = new QTreeWidgetItem(QStringList() << track->title << track->artist << track->album);

        emit transferred(tmpItem);
        //    if(fp.contains("/tmp/"))          //if temporary, delete file
        //        DeleteFile(fp);
    }
            makeEmpty();
}

void TransferQueue::makeEmpty()
{
    clear();
    hide();
    emit empty(1);
    trackList.clear();
}
