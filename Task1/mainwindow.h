#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    static const char* hello_string;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // void on_radioButton_clicked();

    void on_rus_button_clicked();

    void on_eng_button_clicked();

    void on_ger_button_clicked();

    void updateDateText();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
