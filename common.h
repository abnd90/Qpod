#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <QFile>
#include <QDir>
#include <QProcess>
#include <QFileInfo>

#include <gpod/itdb.h>
#include <audioproperties.h>
#include <tag.h>
#include <fileref.h>
#include <mp4v2/mp4v2.h>

void SetTags(Itdb_Track* track,QString fp);
bool DeleteFile(const QString & name);
double usedSpace(const QString&);

#endif // COMMON_H
