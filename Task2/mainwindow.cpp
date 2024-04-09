#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QDate>
#include <QFile>
#include <QXmlStreamReader>
#include <QListView>
#include <QStringListModel>



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

    QWidget* widget = new QWidget;
    widget->setWindowTitle("Сегодняшняя погода");
    widget->setMinimumHeight(150);
    widget->setMinimumWidth(300);

    QString dayName;
    QDate date = ui->dateEdit->date();
    int day = date.dayOfWeek();

    if (day == 1)
        dayName = "Понедельник";
    if (day == 2)
        dayName = "Вторник";
    if (day == 3)
        dayName = "Среда";
    if (day == 4)
        dayName = "Четверг";
    if (day == 5)
        dayName = "Пятница";
    if (day == 6)
        dayName = "Суббота";
    if (day == 7)
        dayName = "Воскресенье";

    QString path = QFileDialog::getOpenFileName(this,"Выбор файла", QDir::homePath());

    QFile* file = new QFile(path);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file";
    }

    /* Вызываем диалог выбора файла для чтения */
    QXmlStreamReader xml(file);


    QString weather = "weather";
    QString block = "block";
    QString bl = "bl";
    QString text = "text";

    QStringList todayWeather;

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
                continue;
            if ((xml.name() == text) or (xml.name() == bl))
            {
                QString st = xml.readElementText();
                todayWeather.append(st);
            }
        }
    }
    QStringListModel *model = new QStringListModel(todayWeather);
    // for(int loop1 = 0; loop1 < todayWeather.size(); loop1++) {
    //     qDebug() << "DEBUG  message " << todayWeather.size() << ", says: " << todayWeather.at(loop1);
    // }

    QListView *view = new QListView(widget);
    view->setModel(model);
    widget -> show();

}
