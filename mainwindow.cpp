#include "mainwindow.h"
#include "ui_mainwindow.h"



Ipod ipod;
TransferQueue* queue;
MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Qpod"));
    setWindowIcon(QIcon(":/images/ipod_icon.png"));

    connect(&ipod,SIGNAL(AddedTrack()), this,SLOT(initTable()));
    propertyDialog=new PropertiesDialog();

    queue=new TransferQueue;
    ui->frame->layout()->addWidget(queue);
    queue->hide();
    ui->menu_Queue->setEnabled(0);

    createActions();
    createContextMenu();
    createToolbars();
    reload();

//    yt=new Youtube();
}

MainWindow::~MainWindow()
{
    if(ipod.DBchanged)
        ipod.DBwrite();

    delete ui;
}

void MainWindow::reload()
{
    ipod.builddb();
    initTable();
}

void MainWindow::about()
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
        ui->treeWidget->clear();
        ui->treeWidget->setEnabled(0);
        ui->ipodimg->setPixmap(QPixmap(":/images/ipod_unmount.png"));
        ui->progressBar->setValue(0);
        ui->menuMovies->setEnabled(0);
        ui->menu_Music->setEnabled(0);
        searchBox->setEnabled(0);
        return;
    }

    ui->treeWidget->setEnabled(1);
    ui->progressBar->setValue(ipod.usedspaceperc());
    ui->label->setText("iPod Mounted");
    ui->ipodimg->setPixmap(QPixmap(":/images/ipod_mount.png"));

    if(ipod.SupportsVideo())
        ui->menuMovies->setEnabled(1);

    ui->menu_Music->setEnabled(1);
    searchBox->setEnabled(1);
    /*populate the table with tracks*/

    ui->treeWidget->clear();
    Itdb_Track *tmp;
    GList *tmptracklst=ipod.tracks;

    while(tmptracklst!=NULL)
    {
        tmp=(Itdb_Track*)tmptracklst->data;
        QTreeWidgetItem* tmpItem = new QTreeWidgetItem(QStringList() << tmp->title << tmp->artist << tmp->album);
        appendTree(tmpItem);
//        QString new1=tmp->ipod_path;
//        new1.replace(':','/');
//        new1="/media/ABHINANDH'S"+new1;
//        std::cerr<<new1.toStdString();
//        TagLib::MPEG::File::File mp3file(new1.toLatin1());
//        TagLib::ID3v2::FrameList l = mp3file.ID3v2Tag()->frameListMap()[ "APIC" ];
//        if(!l.isEmpty())
//        {
//            TagLib::ID3v2::AttachedPictureFrame* pf = (TagLib::ID3v2::AttachedPictureFrame*)l.front();
//            itdb_track_set_thumbnails_from_data(tmp,(guchar*)pf->picture().data(),pf->picture().size());
//        }
//
        tmptracklst=tmptracklst->next;
    }
    //           ui->treeWidget->header()->setResizeMode(QHeaderView::ResizeToContents);
}

void MainWindow::actionVideoAdd()
{
    QString filename=QFileDialog::getOpenFileName(this,"Select a video file","/","Videos (*.flv *.avi *.wmv *.m4v *.mp4)");

    if(!filename.isNull())
        new VideoDialog(filename);

}

Itdb_Track* MainWindow::getTrack(QTreeWidgetItem* item)
{
    QString titleitem=item->data(0,0).toString();
    QString artistitem=item->data(1,0).toString();
    QString albumitem=item->data(2,0).toString();
    GList *tmptracklst=ipod.tracks;

    while(tmptracklst!=NULL)
    {
        if(titleitem!=QString(((Itdb_Track *)tmptracklst->data)->title))
        {
            tmptracklst=tmptracklst->next;
            continue;
        }
        //track titles are equal, make sure album and artist are also equal
        if(artistitem!=QString(((Itdb_Track *)tmptracklst->data)->artist))
        {
            tmptracklst=tmptracklst->next;
            continue;
        }
        if(albumitem!=QString(((Itdb_Track *)tmptracklst->data)->album))
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
    ui->treeWidget->addAction(actionProperties);
    ui->treeWidget->addAction(actionDelete);
    ui->treeWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
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

    actionProperties=new QAction("Properties",ui->treeWidget);
    connect(actionProperties,SIGNAL(triggered()),this,SLOT(showProperties()));
    actionDelete=new QAction("Delete",ui->treeWidget);
    connect(actionDelete,SIGNAL(triggered()),this,SLOT(deleteTrack()));
    connect(propertyDialog,SIGNAL(modified()),this,SLOT(initTable()));
    connect(queue,SIGNAL(transferred(QTreeWidgetItem*))
            ,this,SLOT(appendTree(QTreeWidgetItem*)));

    connect(ui->actionTransfer,SIGNAL(triggered()),queue,SLOT(process()));
    connect(ui->actionClear,SIGNAL(triggered()),queue,SLOT(makeEmpty()));
    connect(queue,SIGNAL(empty(bool)),ui->menu_Queue,SLOT(setDisabled(bool)));
}

void MainWindow::showProperties()
{
    Itdb_Track * thetrack=getTrack(ui->treeWidget->currentItem());
    if(thetrack==NULL)
        return;
    propertyDialog->display(thetrack);
}

void MainWindow::deleteTrack()
{
    QList<QTreeWidgetItem *> selected = ui->treeWidget->selectedItems();
    QList<QTreeWidgetItem *>::iterator item=selected.begin();

    while(item != selected.end())
    {

        Itdb_Track* thetrack=getTrack(*item);

        if(thetrack==NULL)
            continue;

        ipod.removeTrack(thetrack);
        ++item;
    }
    initTable();
    this->statusBar()->showMessage("Track(s) deleted",5000);
}

void MainWindow::addYoutube()
{
    //YoutubeDialog *D=new YoutubeDialog;
    //D->show();
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

    connect(searchBox,SIGNAL(returnPressed()),this,SLOT(searchTracks()));
    connect(searchBox,SIGNAL(textChanged(QString)),this,SLOT(searchDone(QString)));

}

void MainWindow::searchTracks()       //inefficient, takes too long - TODO
{
    QString key=searchBox->text();
    if(!key.isEmpty())
    {
        initTable();
        QList<QTreeWidgetItem *>searchlist = ui->treeWidget->findItems(key,Qt::MatchContains,0);
        searchlist += ui->treeWidget->findItems(key,Qt::MatchContains,1);
        searchlist += ui->treeWidget->findItems(key,Qt::MatchContains,2);
        QSet<QTreeWidgetItem *>uniqlist=searchlist.toSet(); //remove duplicates

        QList<QTreeWidgetItem *> copy;
        QSet<QTreeWidgetItem *>::iterator it=uniqlist.begin();
        while(it!=uniqlist.end())
        {
            QTreeWidgetItem* tmp=new QTreeWidgetItem(**it);
            copy.push_back(tmp);
            it++;
        }

        ui->treeWidget->clear();
        ui->treeWidget->addTopLevelItems(copy);

    }

}

void MainWindow::searchDone(QString ser)
{
    if(ser.isEmpty())
        initTable();
}

void MainWindow::appendTree(QTreeWidgetItem* item)
{
    ui->treeWidget->addTopLevelItem(item);
}

