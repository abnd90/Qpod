#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <QFile>
#include <cstdlib>
#include <gpod/itdb.h>
#include <audioproperties.h>
#include <tag.h>
#include <fileref.h>
#include <mpegfile.h>


QString ConvertVid(QString filepath);
QString FnamefrmPath(QString filepath);
void SetTags(Itdb_Track* track,QString fp);
bool DeleteFile(const QString & name);
#endif // COMMON_H
