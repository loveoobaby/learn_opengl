#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("move window");
    this->setWindowFlag(Qt::FramelessWindowHint);
    btnClose = new QPushButton(this);
    btnClose->setText("close");
    connect(btnClose, SIGNAL(clicked()), this, SLOT(close()));

}

void MainWindow::mousePressEvent(QMouseEvent *e) {
    last = e->globalPos();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e) {
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e) {
    int dx = e->globalX() - last.x();
    int dy = e->globalY() - last.y();
    last = e->globalPos();
    move(x()+dx, y()+dy);
}

MainWindow::~MainWindow()
{
    delete ui;
}

