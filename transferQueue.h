#ifndef TRANSFERQUEUE_H
#define TRANSFERQUEUE_H
#include <QTreeWidget>
#include <gpod/itdb.h>

class TransferQueue : public QTreeWidget
{
    Q_OBJECT
private:
    QList<Itdb_Track*> trackList;
public:
    TransferQueue(QWidget *parent=0);
    void append(Itdb_Track*);
public slots:
    void process();
    void makeEmpty();
 signals:
    void transferred(QTreeWidgetItem*);
    void empty(bool);
};
#endif // TRANSFERQUEUE_H
