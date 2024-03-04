#include "widget.h"
#include "./ui_widget.h"
#include "QDebug"

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

void Widget::on_SubmitpushButton_clicked()
{
    qDebug() << "Last Name:" <<ui->LastNamelineEdit->text();
    qDebug() << "FirstName:" <<ui->FirstNamelineEdit->text();
    qDebug() << "Mesage:" <<ui->MessagetextEdit->toPlainText();

}

