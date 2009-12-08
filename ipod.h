#ifndef IPOD_H
#define IPOD_H

#include <QString>
#include <QObject>
#include <QList>
#include <glib.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gpod/itdb.h>
#include "mainwindow.h"
#include "common.h"
#include "transferQueue.h"


class Ipod:public QObject
{
    Q_OBJECT

private:
    Itdb_iTunesDB *database;
    const Itdb_IpodInfo *ipodinfo;
    QString mountpoint;
    GList *tracks;
    void DBwrite();
 public:
    bool DBchanged;
    Ipod();
    void builddb(void);
    bool mpexists(void);
    ~Ipod();
    int usedspaceperc(void);
    bool SupportsVideo(void);
    bool removeTrack(Itdb_Track*);
    Itdb_iTunesDB * currDB();
 public slots:
    void addVideo(const QString&,Itdb_Track*);
    void SetMountPoint(const QString&);
    void AddTrack(const QString&);
    void AddTrack(Itdb_Track*,const QString&);
    void AddFolder(const QString&);
    friend class MainWindow;
 signals:
    void AddedTrack();
};

#endif // IPOD_H
