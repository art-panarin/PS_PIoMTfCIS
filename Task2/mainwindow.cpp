#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QXmlDefaultHandler>
#include <QFile>
#include <QFileDialog>
#include <QXmlInputSource>
#include <QString>
#include <QDate>
#include <QXmlStreamReader>
#include <QListView>
#include <QStringListModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QStringList everything;

class XmlParser : public QXmlDefaultHandler {
private:
    QString m_strText;

public:
    bool startElement(const QString&,
                      const QString&,
                      const QString&,
                      const QXmlAttributes& attrs
                      )
    {
        for(int i = 0; i < attrs.count(); i++) {
            if(attrs.localName(i) == "number") {
                qDebug() << "Attr:" << attrs.value(i);
            }
        }
        return true;
    }

    bool characters(const QString& strText)
    {
        m_strText = strText;
        return true;
    }

    bool endElement(const QString&, const QString&, const QString& str)
    {
        everything << m_strText;
        return true;
    };
};

void MainWindow::on_dButton_clicked()
{
    XmlParser handler;
    QString path = QFileDialog::getOpenFileName(this,"Выбор файла", QDir::homePath());
    QFile file(path);
    QXmlInputSource   source(&file);
    QXmlSimpleReader  reader;

    reader.setContentHandler(&handler);
    reader.parse(source);

    QWidget* widget = new QWidget;
    widget->setWindowTitle("Сегодняшняя погода");
    widget->setMinimumHeight(300);
    widget->setMinimumWidth(600);

    QString dayName;
    QDate date = ui->dateEdit->date();
    int day = date.dayOfWeek();

    QStringList todayWeather;
    for (int i = (day-1)*182; i < day*182 +  1 ; ++i)
    {
        if (i < everything.size())
        {
            todayWeather.append(everything[i]);
        }
    }

    QStringListModel *model = new QStringListModel(todayWeather);
    QListView *view = new QListView(widget);
    view->setModel(model);
    widget -> show();
}
