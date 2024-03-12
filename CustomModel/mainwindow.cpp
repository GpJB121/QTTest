#include "mainwindow.h"
#include "custommodel.h"
#include <QTableView>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QTableView *tableView = new QTableView(this);
    CustomModel *model = new CustomModel(this);
    tableView->setModel(model);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(tableView);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);

    setCentralWidget(centralWidget);
}
