#ifndef PROPERTIESDIALOG_H
#define PROPERTIESDIALOG_H
#include "ui_propertiesdialog.h"
#include <gpod/itdb.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <QPushButton>


class PropertiesDialog : public QDialog, public Ui::PropertiesDialog
{
    Q_OBJECT
private:
    bool changed;
    Itdb_Track* currentTrack;
public:
    PropertiesDialog(QWidget *parent=0);
    void display(Itdb_Track*);
private slots:
    void propChanged();
    void write();
    void setCover();
signals:
    void modified();
};
#endif // PROPERTIESDIALOG_H
