#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_dButton_clicked()
{
    /* Вызываем диалог выбора файла для чтения */
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open Xml"), ".",
                                                    tr("Xml files (*.xml)"));
}
