#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    model = new QStringListModel(this);


    QStringList list;

    list <<"Cow"<<"Buffalo"<<"OXX"<<"Sheep"<<"Goat";

    model->setStringList(list);


    ui->listView->setModel(model);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    //Rendering with High level API
    //QStringList list=model->stringList();
    //qDebug() <<list;

    //Rendering with low level Implementation using QAbstractItemModel API
    for(size_t i{}; i<model->rowCount(QModelIndex()); ++i)
    {
        auto index=model->index(i, 0, QModelIndex());
        //auto data=index.data();
        auto data= model->data(index);
        qDebug() << data.toString();
    }
}

