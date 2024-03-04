#include "widget.h"
#include "./ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_AddItemButton_clicked()
{

    ui->listWidget->addItem("Helow world");
}


void Widget::on_ListItemButton_clicked()
{
//    qDebug()<<"Count is"<<ui->listWidget->count();

    for(size_t i{}; i<ui->listWidget->count(); ++i)
    {
        auto item_Ptr=ui->listWidget->item(i);
        QVariant data= item_Ptr->data(Qt::DisplayRole);
        qDebug() << data.toString();
    }
}

