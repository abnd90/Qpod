#ifndef PROPERTIESDIALOG_H
#define PROPERTIESDIALOG_H
#include "ui_propertiesdialog.h"

class PropertiesDialog : public QDialog, public Ui::PropertiesDialog
{
    Q_OBJECT

public:
    PropertiesDialog(QWidget *parent=0);
};
#endif // PROPERTIESDIALOG_H
