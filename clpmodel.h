#ifndef TODOMODEL_H
#define TODOMODEL_H

#include <QAbstractListModel>


class CLPList;


class CLPModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(CLPList *list READ list WRITE setList)

public:
    explicit CLPModel(QObject *parent = nullptr);

    enum{
        ImageRole,
        DescriptionRole,
        IndexRole,
        DoneRole=Qt::UserRole
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int,QByteArray>roleNames()const override;
    CLPList *list() const;
    void setList(CLPList *list);

    void ResetModel();
private:
    CLPList *mList;

};

#endif // TODOMODEL_H
