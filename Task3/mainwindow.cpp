#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QSerialPort serial;
//    serial.setPortName("COM3");
//    if (!serial.open(QIODevice::ReadWrite)) {
//        qDebug() << "Failed to open port COM1";
//    }

//    serial.setBaudRate(QSerialPort::Baud9600);
//    serial.setDataBits(QSerialPort::Data8);
//    serial.setParity(QSerialPort::NoParity);
//    serial.setStopBits(QSerialPort::OneStop);
//    serial.setFlowControl(QSerialPort::NoFlowControl);

//    const QByteArray sendData("Hello, Serial Port!");
//    serial.write(sendData);

//    if (serial.waitForBytesWritten(100))
//        qDebug() << "Data written";

//    if (serial.waitForReadyRead(3000)) {
//        QByteArray readData = serial.readAll();
//        while (serial.waitForReadyRead(10))
//            readData.append(serial.readAll());

//        qDebug() << "Read data:" << readData;
//    }

//    serial.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSerialPort serial;
    serial.setPortName("COM3");
    if (!serial.open(QIODevice::ReadWrite)) {
        qDebug() << "Failed to open port COM1";
    }

    serial.setBaudRate(QSerialPort::Baud9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    const QByteArray sendData("Hello, Serial Port!");
    serial.write(sendData);

    if (serial.waitForBytesWritten(100))
        ui->label3->setText("Data written");

    if (serial.waitForReadyRead(3000)) {
        QByteArray readData = serial.readAll();
        while (serial.waitForReadyRead(10))
            readData.append(serial.readAll());
        QString str = "Read data: " + readData;
        ui->label->setText(str);
    }

    serial.close();
}
