#include "custommodel.h"

CustomModel::CustomModel(QObject *parent)
    : QAbstractItemModel(parent)
{
}

int CustomModel::rowCount(const QModelIndex &parent) const
{
    return 1000000; // Set the total number of rows
}

int CustomModel::columnCount(const QModelIndex &parent) const
{
    return 3; // Set the number of columns
}

QVariant CustomModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
        return QString("Row %1, Col %2").arg(index.row() + 1).arg(index.column() + 1);

    return QVariant();
}

QModelIndex CustomModel::index(int row, int column, const QModelIndex &parent) const
{
    if (row >= 0 && row < rowCount() && column >= 0 && column < columnCount())
        return createIndex(row, column);

    return QModelIndex();
}

QModelIndex CustomModel::parent(const QModelIndex &child) const
{
    return QModelIndex(); // This model is not hierarchical
}
