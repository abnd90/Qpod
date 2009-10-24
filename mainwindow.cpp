#include "mainwindow.h"
#include "ui_mainwindow.h"

Ipod ipod;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    //view=LIST;               //multiple views unimplemented
    ui->setupUi(this);
    setWindowTitle(tr("Qpod"));
    setWindowIcon(QIcon(":/images/ipod_icon.png"));

    connect(&ipod,SIGNAL(AddedTrack()), this,SLOT(reload()));
    ipod.DBchanged=false;        //initialising
    createActions();
    createContextMenu();

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
    initwin();
}

void MainWindow::about()   //SLOT about Qpod
{
    QMessageBox::about(this,"About Qpod",
                       "<h2>Qpod 0.1</h2>"
                       "<p>A Qt4 application which"
                       " manages your iPod collection."
                       "<p>Still an early alpha, so it may eat your iPod");
}

void MainWindow::initwin()
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
    if(/*view==LIST*/1)                   //multiple views unimplemented
    {
        //ui->stackedWidget->setCurrentIndex(0);
        ui->tableWidget->clearContents();
           Itdb_Track *tmp;
           GList *tmptracklst=ipod.tracks;
           int row=0,column=0;
           int rowcount=0;
           //ui->tableWidget->setRowCount(g_list_length(tmptracklst));

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

    /*if(view==ALBUM)
    {

        QSplitter splitter(Qt::Horizontal);

        QTableWidget *left=new QTableWidget;
        QTableWidget *right=new QTableWidget;
        QLabel *newl=new QLabel("whtf?");
        left->setRowCount(5);
        left->setColumnCount(5);
        left->setItem(0,0, &QTableWidgetItem("WTF?"));
        splitter.addWidget(left);
        splitter.addWidget(right);
        splitter.addWidget(newl);

        ui->stackedWidget->insertWidget(1,&splitter);
        
        ui->stackedWidget->setCurrentIndex(1);

    }*/
}

void MainWindow::action_video_select()   //SLOT
{
    QFileDialog *open=new QFileDialog(this,Qt::Dialog);
    open->setWindowTitle("Select a video file");
    open->setNameFilter("*.flv *.avi *.wmv *.m4v *.mp4");
    open->show();
    VideoDialog *V=new VideoDialog;
    connect(open, SIGNAL(fileSelected(const QString&) ),V, SLOT(open_video_dialog(const QString&)));
    connect(V, SIGNAL(Conv_Done(const QString&,Itdb_Mediatype)),&ipod, SLOT(Add_Video(const QString&,Itdb_Mediatype)));
}

Itdb_Track* MainWindow::GetTrack(int row,int col)
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

void MainWindow::SetMP(void)
{
    QFileDialog *open=new QFileDialog(this,Qt::Dialog);
    open->setWindowTitle("Select a path");
    open->setFileMode(QFileDialog::Directory);
    open->setOption(QFileDialog::ShowDirsOnly, true);
    QObject::connect(open,SIGNAL(fileSelected(const QString&)),&ipod,SLOT(SetMountPoint(const QString&)));
    QObject::connect(open,SIGNAL(accepted()),this,SLOT(reload()));
    open->show();

}

void MainWindow::AddTrack()
{
    QFileDialog *open=new QFileDialog(this,Qt::Dialog);
    open->setWindowTitle("Select an Audio file");
    open->setNameFilter("*.mp3 *.aac");
    open->show();
    connect(open, SIGNAL(fileSelected(const QString&) ),&ipod, SLOT(AddTrack(const QString&)));

}

void MainWindow::AddFolder()
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
    connect(ui->actionConvert_and_Add,SIGNAL(triggered()), this,SLOT(action_video_select()));
    connect(ui->actionSet_Mount_Point,SIGNAL(triggered()),this,SLOT(SetMP()));
    connect(ui->actionAdd_File,SIGNAL(triggered()),this,SLOT(AddTrack()));
    connect(ui->actionAdd_Folder,SIGNAL(triggered()),this,SLOT(AddFolder()));
    connect(ui->actionAdd_YouTube_Video,SIGNAL(triggered()),this,SLOT(addYoutube()));

    actionProperties=new QAction("Properties",ui->tableWidget);
    connect(actionProperties,SIGNAL(triggered()),this,SLOT(showProperties()));
    actionDelete=new QAction("Delete",ui->tableWidget);
    connect(actionDelete,SIGNAL(triggered()),this,SLOT(DeleteTrack()));
}

void MainWindow::showProperties()
{
    Itdb_Track * thetrack=GetTrack(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn());

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

void MainWindow::DeleteTrack()
{
    int row=ui->tableWidget->currentRow();
    int column=ui->tableWidget->currentColumn();
    Itdb_Track * thetrack=GetTrack(row,column);

    if(thetrack==NULL)
        return;

    if(ipod.removeTrack(thetrack))
        ui->tableWidget->removeRow(row);
    this->statusBar()->showMessage("Track deleted",5000);
}

void MainWindow::addYoutube()
{
    YoutubeDialog *D=new YoutubeDialog;
    D->show();
}




