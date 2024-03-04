#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    model=new QStandardItemModel(4, 4);

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int column = 0; column < model->columnCount(); ++column) {
            QStandardItem *item = new QStandardItem(QString("row %0, column %1").arg(row).arg(column));
            model->setItem(row, column, item);
        }
    }

    ui->tableView->setModel(model);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    for(int row=0; row<model->rowCount();++row)
    {
        for(int column=0; column<model->columnCount();++column){
            auto index=model->index(row,column,QModelIndex());
            auto data=model->data(index);

            qDebug() <<data.toString();
        }


    }

}

