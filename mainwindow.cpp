#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenu *editmenu = ui->menuBar->addMenu("编辑(&E)");
    QAction *action_open = editmenu->addAction(QIcon(":/images/favicon(2).png"),"打开文件(&O)");
    action_open->setShortcut(QKeySequence("Ctrl+O"));

    QActionGroup *group = new QActionGroup(this);
    QAction *action_l = group->addAction("left(&L)");
    action_l->setCheckable(true);
    QAction *action_r = group->addAction("right(&R)");
    action_r->setCheckable(true);
    QAction *action_c = group->addAction("center(&C)");
    action_c->setCheckable(true);
    QList<QAction*> list;
    list<<action_l<<action_c<<action_r;
    action_l->setChecked(true);
    editmenu->addSeparator();
    editmenu->addActions(list);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addActions(list);
    ui->mainToolBar->addSeparator();

    this->resize(500,300);

    QToolButton *toolbutton = new QToolButton(this);
    toolbutton->setText("颜色");
    QMenu *colormenu = new QMenu(this);
    colormenu->addAction("red");
    colormenu->addAction("green");
    colormenu->addAction("blue");
    toolbutton->setMenu(colormenu);
    toolbutton->setPopupMode(QToolButton::InstantPopup);
    ui->mainToolBar->addWidget(toolbutton);
    QSpinBox *spinbox = new QSpinBox;

    ui->mainToolBar->addWidget(spinbox);

    ui->dockWidget->setFloating(true);
    ui->dockWidget->resize(500,40);
    ui->dockWidget->hide();

    ui->statusBar->showMessage("欢迎使用多文本编辑器",2000);
    QLabel *permanent = new QLabel;
    permanent->setFrameStyle(QFrame::Plain|QFrame::Sunken);
    permanent->setText("Made By Welsey");
    ui->statusBar->addPermanentWidget(permanent);

    myaction *action = new myaction;
    ui->mainToolBar->addAction(action);
//    qDebug()<<editmenu;
    connect(action,SIGNAL(get_text(QString)),this,SLOT(setText(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_New_triggered()
{
    QTextEdit *textedit = new QTextEdit;
    QMdiSubWindow *child = ui->mdiArea->addSubWindow(textedit);
    child->setWindowTitle("多文档编辑子窗口");
    child->show();
}

void MainWindow::on_actionShow_triggered()
{
    ui->dockWidget->show();
}


void MainWindow::setText(const QString &string)
{
    ui->textEdit->append(string);
}
