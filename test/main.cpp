#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QDateEdit>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Пример ввода даты в виде трех переменных");

    QVBoxLayout *layout = new QVBoxLayout(&mainWindow);

    QDateEdit *dateEdit = new QDateEdit(QDate::currentDate(), &mainWindow);
    dateEdit->setDisplayFormat("dd/MM/yyyy"); // Установка формата отображения даты
    layout->addWidget(dateEdit);

    QPushButton *button = new QPushButton("Получить дату", &mainWindow);
    layout->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, [dateEdit]{
        QDate date = dateEdit->date();
        int day = date.day();
        int month = date.month();
        int year = date.year();
        qDebug() << "День: " << day << ", Месяц: " << month << ", Год: " << year;
    });

    mainWindow.show();

    return app.exec();
}
