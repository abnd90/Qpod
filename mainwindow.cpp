#include "mainwindow.h"
#include "ui_mainwindow.h"

Ipod ipod;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Qpod"));
    setWindowIcon(QIcon(":/images/ipod_icon.png"));

    connect(&ipod,SIGNAL(AddedTrack()), this,SLOT(reload()));
    ipod.DBchanged=false;        //initialising
    createActions();
    createContextMenu();
    createToolbars();

    reload();

}

MainWindow::~MainWindow()
{
    if(ipod.DBchanged)
        ipod.DBwrite();

    delete ui;
}

void MainWindow::reload()   //SLOT
{
    ipod.builddb();
    initTable();
}

void MainWindow::about()   //SLOT about Qpod
{
    QMessageBox::about(this,"About Qpod",
                       "<h2>Qpod 0.1</h2>"
                       "<p>A Qt4 application which"
                       " manages your iPod collection."
                       "<p>Still an early alpha, so it may eat your iPod");
}

void MainWindow::initTable()
{
    if(!ipod.mpexists())
    {
        ui->label->setText("No iPod Mounted");
        ui->tableWidget->clearContents();
        ui->tableWidget->setEnabled(0);
        ui->ipodimg->setPixmap(QPixmap(":/images/ipod_unmount.png"));
        ui->progressBar->setValue(0);
        ui->menuMovies->setEnabled(0);
        ui->menu_Music->setEnabled(0);
        return;
    }

    ui->tableWidget->setEnabled(1);
    ui->progressBar->setValue(ipod.usedspaceperc());
    ui->label->setText("iPod Mounted");
    ui->ipodimg->setPixmap(QPixmap(":/images/ipod_mount.png"));

    if(ipod.SupportsVideo())
         ui->menuMovies->setEnabled(1);

    ui->menu_Music->setEnabled(1);
    /*populate the table with tracks*/

        ui->tableWidget->clearContents();
           Itdb_Track *tmp;
           GList *tmptracklst=ipod.tracks;
           int row=0,column=0;
           int rowcount=0;


           while(tmptracklst!=NULL)
           {
                 tmp=(Itdb_Track*)tmptracklst->data;

                 if(QString(tmp->title).isEmpty())       //stale entries
                 {
                     tmptracklst=tmptracklst->next;
                     continue;
                 }
                 ++rowcount;
                 ui->tableWidget->setRowCount(rowcount);
                 QTableWidgetItem *title = new QTableWidgetItem(tmp->title);
                 QTableWidgetItem *artist = new QTableWidgetItem(tmp->artist);
                 QTableWidgetItem *album = new QTableWidgetItem(tmp->album);

                 ui->tableWidget->setItem(row, column, title);
                 ui->tableWidget->setItem(row, ++column, artist);
                 ui->tableWidget->setItem(row++, ++column, album);
                 column=0;
                 tmptracklst=tmptracklst->next;



       }
}

void MainWindow::actionVideoAdd()
{
    QString filename=QFileDialog::getOpenFileName(this,"Select a video file","/","Videos (*.flv *.avi *.wmv *.m4v *.mp4)");

    if(!filename.isNull())
        new VideoDialog(filename);

}

Itdb_Track* MainWindow::getTrack(int row,int col=0)
{
    QTableWidgetItem* titleitem=ui->tableWidget->item(row,0);
    QTableWidgetItem* artistitem=ui->tableWidget->item(row,1);
    QTableWidgetItem* albumitem=ui->tableWidget->item(row,2);
    GList *tmptracklst=ipod.tracks;

    if(titleitem==NULL)
        return NULL;

    while(1)
    {
        if(titleitem->text()!=QString(((Itdb_Track *)tmptracklst->data)->title))
        {
             tmptracklst=tmptracklst->next;
             continue;
         }
        //track titles are equal, make sure album and artist are also equal
        if(artistitem->text()!=QString(((Itdb_Track *)tmptracklst->data)->artist))
         {
             tmptracklst=tmptracklst->next;
             continue;
         }
        if(albumitem->text()!=QString(((Itdb_Track *)tmptracklst->data)->album))
         {
             tmptracklst=tmptracklst->next;
             continue;
         }
        break;
    }


    if(tmptracklst!=NULL)
        return (Itdb_Track *)tmptracklst->data;
    else
        return NULL;

}

void MainWindow::setMP(void)
{
    QFileDialog *open=new QFileDialog(this,Qt::Dialog);
    open->setWindowTitle("Select a path");
    open->setFileMode(QFileDialog::Directory);
    open->setOption(QFileDialog::ShowDirsOnly, true);
    QObject::connect(open,SIGNAL(fileSelected(const QString&)),&ipod,SLOT(SetMountPoint(const QString&)));
    QObject::connect(open,SIGNAL(accepted()),this,SLOT(reload()));
    open->show();

}

void MainWindow::addFile()
{
    QFileDialog *open=new QFileDialog(this,Qt::Dialog);
    open->setWindowTitle("Select an Audio file");
    open->setNameFilter("*.mp3 *.aac");
    open->show();
    connect(open, SIGNAL(fileSelected(const QString&) ),&ipod, SLOT(AddTrack(const QString&)));

}

void MainWindow::addFolder()
{
    QFileDialog *open=new QFileDialog(this,Qt::Dialog);
    open->setWindowTitle("Select a folder");
    open->setNameFilter("*.mp3 *.aac");
    open->setFileMode(QFileDialog::Directory);
    open->show();
    connect(open, SIGNAL(fileSelected(const QString&) ),&ipod, SLOT(AddFolder(const QString&)));

}

void MainWindow::createContextMenu()
{
    ui->tableWidget->addAction(actionProperties);
    ui->tableWidget->addAction(actionDelete);
    ui->tableWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
}


void MainWindow::createActions()
{
    connect(ui->actionAbout_Qt,SIGNAL(triggered()), qApp,SLOT(aboutQt()));
    connect(ui->actionReload,SIGNAL(triggered()), this,SLOT(reload()));
    connect(ui->actionAbout,SIGNAL(triggered()), this,SLOT(about()));
    connect(ui->actionConvert_and_Add,SIGNAL(triggered()), this,SLOT(actionVideoAdd()));
    connect(ui->actionSet_Mount_Point,SIGNAL(triggered()),this,SLOT(setMP()));
    connect(ui->actionAdd_File,SIGNAL(triggered()),this,SLOT(addFile()));
    connect(ui->actionAdd_Folder,SIGNAL(triggered()),this,SLOT(addFolder()));
    connect(ui->actionAdd_YouTube_Video,SIGNAL(triggered()),this,SLOT(addYoutube()));

    actionProperties=new QAction("Properties",ui->tableWidget);
    connect(actionProperties,SIGNAL(triggered()),this,SLOT(showProperties()));
    actionDelete=new QAction("Delete",ui->tableWidget);
    connect(actionDelete,SIGNAL(triggered()),this,SLOT(deleteTrack()));
}

void MainWindow::showProperties()
{
    Itdb_Track * thetrack=getTrack(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn());

    if(thetrack==NULL)
        return;
    if(itdb_track_has_thumbnails(thetrack))
    {
        GdkPixbuf* cover=(GdkPixbuf*)itdb_track_get_thumbnail(thetrack,128,128);
        gdk_pixbuf_save (cover, "tmpcover", "jpeg", NULL,
                 "quality", "100", NULL);

        trackproperties.AlbumArt->setPixmap(QPixmap("tmpcover"));
    }
    else
        trackproperties.AlbumArt->setPixmap(QPixmap(":/images/no-cover-art.jpg"));

    trackproperties.AlbumBox->setText(QString(thetrack->album));
    trackproperties.ArtistBox->setText(QString(thetrack->artist));
    trackproperties.TitleBox->setText(QString(thetrack->title));

    trackproperties.show();
}

void MainWindow::deleteTrack()
{
    QList<QTableWidgetItem *> selected = ui->tableWidget->selectedItems();
    QList<QTableWidgetItem *>::iterator item=selected.begin();
    while(item != selected.end())
    {

    Itdb_Track* thetrack=getTrack((*item)->row());

    if(thetrack==NULL)
        continue;

    if(ipod.removeTrack(thetrack))
       ui->tableWidget->removeRow((*item)->row());

    if(item != (selected.end()-1))
        item += ui->tableWidget->columnCount();
    else
        ++item;
     }

    this->statusBar()->showMessage("Track(s) deleted",5000);
}

void MainWindow::addYoutube()
{
    YoutubeDialog *D=new YoutubeDialog;
    D->show();
}

void MainWindow::createToolbars()
{
    musicToolbar= addToolBar(tr("&Music"));
    videoToolbar= addToolBar(tr("&Video"));
    fileToolbar= addToolBar(tr("&File"));
    fileToolbar->addAction(ui->actionReload);
    fileToolbar->addAction(ui->action_Quit);
    searchBox= new QLineEdit;
    QLabel *searchLabel=new QLabel("Search: ");
    searchToolbar= addToolBar(tr("&Search"));
    searchBox->setSizePolicy(QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred));
    searchToolbar->addWidget(searchLabel);
    searchToolbar->addWidget(searchBox);

    connect(searchBox,SIGNAL(textChanged(QString)),this,SLOT(searchTracks(QString)));
}

void MainWindow::searchTracks(QString key)
{

    if(!key.isEmpty())
    {
        QList<QTableWidgetItem *>searchlist = ui->tableWidget->findItems(key,Qt::MatchContains);
        QMap<int,int> rows;

        foreach(QTableWidgetItem *item,searchlist)          //get unique rows
           ++rows[item->row()];


       /* ui->tableWidget->setColumnCount(tableBackup->columnCount());
        QMap<int,int>::iterator it=rows.begin();
        for (int r=0,c=0;it != rows.end();it++,c=0,++r)
        {
            ui->tableWidget->setRowCount(r+1);
            while(c<tableBackup->columnCount())
            {
                QTableWidgetItem *tmpwidget=new QTableWidgetItem(*(tableBackup->item(it.key(),c)));
                ui->tableWidget->setItem(r,c,tmpwidget);
                c++;
            }
        }*/

     }

}




