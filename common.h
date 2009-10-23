#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <QFile>
#include <cstdlib>
#include <gpod/itdb.h>
#include <audioproperties.h>
#include <tag.h>
#include <fileref.h>
#include <mp4v2/mp4v2.h>


QString ConvertVid(QString filepath);
QString FnamefrmPath(QString filepath);
void SetTags(Itdb_Track* track,QString fp);
bool DeleteFile(const QString & name);
#endif // COMMON_H
