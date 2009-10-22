#ifndef IPOD_H
#define IPOD_H

#include <QString>
#include <QObject>
#include <QList>
#include <glib.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <gpod/itdb.h>
#include "mainwindow.h"
#include <sys/stat.h>
#include <cstdlib>
#include <sys/statvfs.h>
#include "common.h"


class Ipod:public QObject
{
    Q_OBJECT

private:
    Itdb_iTunesDB *database;
    const Itdb_IpodInfo *ipodinfo;
    bool DBchanged;
    QString mountpoint;
    GList *tracks;
    void DBwrite();
 public:
    Ipod();
    void builddb(void);
    bool mpexists(void);
    ~Ipod();
    int usedspaceperc(void);
    void Add_Video(const QString& fp);
    bool SupportsVideo(void);
    bool removeTrack(Itdb_Track*);
 public slots:
    void SetMountPoint(const QString&);
    void AddTrack(const QString&);
    void AddTrack(Itdb_Track*,const QString&);
    void AddFolder(const QString&);
    friend class MainWindow;
 signals:
    void AddedTrack();
};

#endif // IPOD_H
