#include "mainwindow.h"

#include <QApplication>
#include <QStandardItemModel>
#include <QColumnView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

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


    MainWindow w;
    w.show();
    return a.exec();
}
