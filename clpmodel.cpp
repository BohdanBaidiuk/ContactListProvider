#include "clpmodel.h"
#include "clplist.h"
#include <algorithm>

CLPModel::CLPModel(QObject *parent)
    : QAbstractListModel(parent)
    ,mList(nullptr)
{
}

int CLPModel::rowCount(const QModelIndex &parent)const
{

    if (parent.isValid()||!mList)
        return 0;

    size_t count=mList->items().size();
    if (mList->isFavorite()){
        count = 0;
        for(int i=0;i<mList->items().size();++i){
            if(mList->items().at(i).done){
                ++count;
            }
        }
    }

    return count;
}

QVariant CLPModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()||!mList)
        return QVariant();

    const CLPItem item=mList->items().at(index.row());

    switch (role) {
    case ImageRole:
        return QVariant(item.imege);
    case DescriptionRole:
        return QVariant(item.description);
    case IndexRole:
        return QVariant(item.phoneNumber);
    case DoneRole:
        return QVariant(item.done);
    }
    return QVariant();
}


Qt::ItemFlags CLPModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> CLPModel::roleNames() const
{
    QHash<int, QByteArray>name;
    name[ImageRole]="image";
    name[DescriptionRole]="description";
    name[IndexRole]="phoneNumber";
    name[DoneRole]="done";
    return name;
}

CLPList *CLPModel::list() const
{
    return mList;
}





void CLPModel::ResetModel() {
        beginResetModel();

        endResetModel();
}

void CLPModel::setList(CLPList *list)
{
    beginResetModel();
    if(mList){
        mList->disconnect(this);
    }
    mList = list;
    if(mList){

        connect(mList,&CLPList::preShowFavorite,this,[=](){
               ResetModel();
        });
        connect(mList,&CLPList::preOnTurnFavorite,this,[=](){
               ResetModel();
        });
        connect(mList,&CLPList::filtrOnContact,this,[=](){
               ResetModel();
        });


    }
    endResetModel();
}

