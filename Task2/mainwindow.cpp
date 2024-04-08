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

    QFile* file = new QFile(filename);
    QXmlStreamReader xml(file);


    //year =
    //month
    //day

    QDate date;
    date.setDate(yy, mm, dd);
    int day = date.dayOfWeek();
    QString weekDay = QDate::longDayName(day);

    QString weather = "weather";
    QString block = "block";

    while (!xml.atEnd() && !xml.hasError())
    {
        QXmlStreamReader::TokenType token = xml.readNext();
        if (token == QXmlStreamReader::StartDocument)
            continue;
        if (token == QXmlStreamReader::StartElement)
        {
            if (xml.name() == weather)
                continue;
            if (xml.name() == block)
                XMLConf.append(parseEtap(xml));

        }
    }

}
