#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class myClient; }
QT_END_NAMESPACE

class myClient : public QMainWindow
{
    Q_OBJECT

public:
    myClient(QWidget *parent = nullptr);
    ~myClient();

    QTcpSocket* socket;
    QByteArray data;

public:
    void socketReady();
    void socketDisconnect();

private slots:
    void onPushButtonClicked();

private:
    Ui::myClient *ui;
};
#endif // MYCLIENT_H
