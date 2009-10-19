#include "ui_addvideodialog.h"
#include <QApplication>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    Ui::addvideodialog ui;
    QDialog *dialog= new QDialog;
    ui.setupUi(dialog);
    dialog->show();

    return app.exec();
}

