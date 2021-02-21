#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Qt Window App");
    this->setMaximumSize(500, 500);
    this->setMinimumSize(300, 300);
    this->move(500, 500);
    this->setStyleSheet("background:red");
    this->setWindowIcon(QIcon(":/new/prefix1/resources/paintsystem-icon.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

