#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket> //работа с сокетами
#include <QMessageBox> //для показа сообщений пользователю
#include <QDebug> //для проверок

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTcpSocket* socket; //переменная сокет для передачи информации
    QByteArray Data; //разместим сюда всё то, что лежит в сокете

public slots:       //публичные методы
    void sockReady(); //готовность к чтению данных от сервера
    void sockDisc(); //отключение

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
