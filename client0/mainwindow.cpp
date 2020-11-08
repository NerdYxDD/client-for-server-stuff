#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);      //новый сокет от QTcpSocket

    connect(socket,SIGNAL(readyRead()),this,SLOT(sockReady())); //соединяем через две связи с сокетом и слотом

    connect(socket,SIGNAL(disconnected()),this,SLOT(sockDisc()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() //добавление кнопки для подключения
{
    socket->connectToHost("PUT PC ADRESS HERE", PUT PORT HERE); //попытка с помощью сокета соединиться с хостом (в скобках вводится адрес пк и порт, заданный пользователем)
}

void MainWindow::sockDisc()
{
    socket->deleteLater(); //перекладка на приложение удаления сокета
}

void MainWindow::sockReady()
{
    if (socket->waitForConnected(PUT MILISECONDS HERE)) //готовность сокета на чтение и ожидание в скобках на опр. время (в милисекундах)
    {
        socket->waitForReadyRead(PUT MILISECONDS HERE);
        Data = socket->readAll();
        qDebug()<<Data;         //посмотрим, что передал нам сервер
    }
}
