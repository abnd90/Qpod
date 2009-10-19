#include "mainwindow.h"
#include "ui_mainwindow.h"



Ipod ipod;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    view=LIST;
    ui->setupUi(this);
    setWindowTitle(tr("Qpod"));
    setWindowIcon(QIcon(":/images/ipod_icon.png"));
    connect(ui->actionAbout_Qt,SIGNAL(triggered()), qApp,SLOT(aboutQt()));
    connect(ui->actionReload,SIGNAL(triggered()), this,SLOT(reload()));
    connect(ui->actionAbout,SIGNAL(triggered()), this,SLOT(about()));
    connect(ui->actionConvert_and_Add,SIGNAL(triggered()), this,SLOT(action_video_select()));
    connect(ui->actionSet_Mount_Point,SIGNAL(triggered()),this,SLOT(SetMP()));
    connect(ui->actionAdd_File,SIGNAL(triggered()),this,SLOT(AddTrack()));
    connect(&ipod,SIGNAL(AddedTrack()), this,SLOT(reload()));
    connect(ui->actionAdd_Folder,SIGNAL(triggered()),this,SLOT(AddFolder()));

    reload();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reload()   //SLOT
{
    ipod.builddb();
    initwin();
}


void MainWindow::action_video_select()   //SLOT
{
    QFileDialog *open=new QFileDialog(this,Qt::Dialog);
    open->setWindowTitle("Select a video file");
    open->setNameFilter("*.flv *.avi *.wmv *.m4v");
    open->show();
    VideoDialog *V=new VideoDialog;
    connect(open, SIGNAL(fileSelected(const QString&) ),V, SLOT(open_video_dialog(const QString&)));
    connect(V, SIGNAL(Conv_Done(const QString&)),this, SLOT(Add_Video(const QString&)));
}


void MainWindow::about()   //SLOT about Qpod
{
    QMessageBox::about(this,"About Qpod",
                       "<h2>Qpod -1</h2>"
                       "<p>A Qt4 application which aims"
                       " to manage your iPod collection"
                       " but does nothing at the moment :)");
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
    if(view==LIST)
    {
        //ui->stackedWidget->setCurrentIndex(0);
        ui->tableWidget->clearContents();
           Itdb_Track *tmp;
           GList *tmptracklst=ipod.tracks;
           int row=0,column=0;
           ui->tableWidget->setRowCount(g_list_length(tmptracklst));

           while(tmptracklst!=NULL)
           {
                 tmp=(Itdb_Track*)tmptracklst->data;
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

void MainWindow::Add_Video(const QString& fp)
{
    ipod.Add_Video(fp);
    system(QString("rm "+fp).toLatin1()); //remove the tmp video
    reload();
    this->statusBar()->showMessage("Video added successfully",5000);
}

/*void MainWindow::RefreshDetails(int row,int col)
{
    Itdb_Track *curr;
    curr=GetTrack(row,col);
    //ui->trackdetails->setText(curr->title);
    if(itdb_track_has_thumbnails(curr))
    {
        GdkPixbuf* cover=(GdkPixbuf*)itdb_track_get_thumbnail(curr,128,128);
        gdk_pixbuf_save (cover, "tmpcover", "jpeg", NULL,
                 "quality", "100", NULL);

       // ui->coverart->setPixmap(QPixmap("tmpcover"));
    }
}*/

Itdb_Track* MainWindow::GetTrack(int row,int col)
{
    GList *tmptracklst=ipod.tracks;
    for(int i=0;i<row;i++)
        tmptracklst=tmptracklst->next;

    return (Itdb_Track *)tmptracklst->data;
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
