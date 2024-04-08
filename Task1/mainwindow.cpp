#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTranslator>
#include <QDebug>
#include <QLocale>
#include <QDateTime>

const char* MainWindow::hello_string = QT_TR_NOOP("Hello, world");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDateText()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString formattedDateTime = QLocale().toString(currentDateTime, QLocale::ShortFormat);
    ui->textEdit->setText(formattedDateTime);
}

void MainWindow::on_rus_button_clicked()
{
    QTranslator trans;
    bool res = trans.load("Task1_ru_Ru.qm");
    qDebug() << res;
    qApp ->installTranslator(&trans);
    ui -> retranslateUi(this);
    ui->label_1->setText(tr(hello_string));
    ui->label_2->setText(QLocale(QLocale::Russian).nativeCountryName());

    QLocale::setDefault(QLocale(QLocale::Russian));
    updateDateText();
}

void MainWindow::on_eng_button_clicked()
{
    QTranslator trans;
    bool res = trans.load("Task1_en_En.qm");
    qDebug() << res;
    qApp ->installTranslator(&trans);

    ui -> retranslateUi(this);
    ui->label_1->setText(tr(hello_string));
    ui->label_2->setText(QLocale(QLocale::English).nativeCountryName());

    QLocale::setDefault(QLocale(QLocale::English));
    updateDateText();
}

void MainWindow::on_ger_button_clicked()
{
    QTranslator trans;
    bool res = trans.load("Task1_de_De.qm");
    qDebug() << res;
    qApp ->installTranslator(&trans);
    ui -> retranslateUi(this);
    ui->label_1->setText(tr(hello_string));
    ui->label_2->setText(QLocale(QLocale::German).nativeCountryName());

    QLocale::setDefault(QLocale(QLocale::German));
    updateDateText();
}
