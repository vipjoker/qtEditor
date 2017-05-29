#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //connect(ui->actionCircle,SIGNAL(toggled(bool)),ui->openGLWidget,SLOT(drawCircle()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Box2dDialog b;

    b.exec();
qDebug() << "works";
}
