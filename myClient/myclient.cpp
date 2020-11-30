#include "myClient.h"
#include "ui_myclient.h"

myClient::myClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::myClient)
{
    ui->setupUi(this);

    /*соединение через две связи с сокетом и слотом*/
    socket = new QTcpSocket(this);
    connect(socket,SIGNAL(readyRead()),this,SLOT(socketReady()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(socketDisconnect()));
}

myClient::~myClient()
{
    delete ui;
}

/*попытка с помощью сокета соединиться с хостом*/
void myClient::onPushButtonClicked()
{
    socket->connectToHost("PUT PC ADRESS HERE", PUT PORT HERE);
}

/*перекладка на приложение удаления сокета*/
void myClient::socketDisconnect()
{
    socket->deleteLater();
}

/*готовность сокета на чтение и ожидание в скобках на опр. время (в милисекундах) и просмотр передачи сервером*/
void myClient::socketReady()
{
    if (socket->waitForConnected(PUT MILISECONDS HERE))
    {
        socket->waitForReadyRead(PUT MILISECONDS HERE);
        data = socket->readAll();
        qDebug()<<data;
    }
}
