#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QStandardItemModel>
#include <QColumnView>
#include <QFile>
#include <QXmlStreamReader>
#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <QFileDialog>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QString path = QFileDialog::getOpenFileName(this,"Выбор файла", QDir::homePath());

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    }

    QXmlStreamReader xmlReader(&file);


    while (!xmlReader.atEnd() && !xmlReader.hasError())
    {
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        if (token == QXmlStreamReader::StartElement)
        {
            qDebug() << "Element: " << xmlReader.name().toString();
            if (xmlReader.isStartElement())
            {
                QXmlStreamAttributes attributes = xmlReader.attributes();
                foreach (QXmlStreamAttribute attribute, attributes)
                {
                    qDebug() << "  Attribute: " << attribute.name().toString() << " = " << attribute.value().toString();
                }
            }
        }
        else if (token == QXmlStreamReader::Characters && !xmlReader.isWhitespace())
        {
            qDebug() << "  Value: " << xmlReader.text().toString();
        }
    }



    QStandardItemModel model;

    QStandardItem *rootItem = model.invisibleRootItem();
    for (int i = 0; i < 3; ++i) {
        QStandardItem *item = new QStandardItem(QString("Column %1").arg(i + 1));
        for (int j = 0; j < 5; ++j) {
            item->appendRow(new QStandardItem(QString("Item %1").arg(j + 1)));
        }
        rootItem->appendRow(item);
    }

    QColumnView columnView;
    columnView.setModel(&model);

    columnView.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

