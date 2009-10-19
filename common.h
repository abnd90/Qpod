#ifndef COMMON_H
#define COMMON_H

#include <QString>
#include <cstdlib>
#include <gpod/itdb.h>
#include <audioproperties.h>
#include <tag.h>
#include <fileref.h>


QString ConvertVid(QString filepath);
QString FnamefrmPath(QString filepath);
void SetTags(Itdb_Track* track,QString fp);
void PlayFile();
#endif // COMMON_H
