#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *tiempo = new QTimer(this);
    connect(this, SIGNAL(clicked()), this, SLOT(close()));
    connect(tiempo, SIGNAL(timeout()), this, SLOT(sendDatagram()));
    tiempo->start(2*1000);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_sendButton_clicked(){
//    udpSocket.writeDatagram(buffer.data(),QHostAddress("192.168.1.133", 7000); //TODO: Quitar
    sendDatagram();
}

void MainWindow::sendDatagram(){
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    //out.setVersion(QDataStream::Qt_5_7); //TODO: Quitar
    out << ui->mensaje->toPlainText();
    udpSocket.writeDatagram(datagram, QHostAddress("192.168.1.126"), 5824);

}
