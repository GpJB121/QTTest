#ifndef CUSTOMMODEL_H
#define CUSTOMMODEL_H

#include <QAbstractItemModel>

class CustomModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    CustomModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &child) const override;
};

#endif // CUSTOMMODEL_H
