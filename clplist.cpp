#include "clplist.h"
#include <algorithm>


CLPList::CLPList(QObject *parent) : QObject(parent)
{
    mItem.append({QStringLiteral("Image/avatar1.jpg"),QStringLiteral("Ava Max"),971112233,false});
    mItem.append({QStringLiteral("Image/avatar2.jpg"),QStringLiteral("Endry Ask"),733332156,true});
    mItem.append({QStringLiteral("Image/avatar3.jpg"),QStringLiteral("Dan Fill"),98774598,false});
    mItem.append({QStringLiteral("Image/avatar4.jpg"),QStringLiteral("Sant Dall"),45441256,true});
    mItem.append({QStringLiteral("Image/avatar5.jpg"),QStringLiteral("Karl Los"),32177841,true});
    mItem.append({QStringLiteral("Image/avatar6.jpg"),QStringLiteral("Ina Rast"),69502569,true});
    mItem.append({QStringLiteral("Image/avatar4.jpg"),QStringLiteral("Wiliam Coolr"),45544587,true});
    mItem.append({QStringLiteral("Image/avatar5.jpg"),QStringLiteral("Dmitriy Fgal"),56698621,false});
    mItem.append({QStringLiteral("Image/avatar6.jpg"),QStringLiteral("Sonic Bill"),87241258,false});
    mItem.append({QStringLiteral("Image/avatar1.jpg"),QStringLiteral("Den Paster"),98769852,false});
    mItem.append({QStringLiteral("Image/avatar3.jpg"),QStringLiteral("Nick Mista"),22100014,false});
    mItem.append({QStringLiteral("Image/avatar6.jpg"),QStringLiteral("Onel Bax"),32303214,true});
    mItem.append({QStringLiteral("Image/avatar2.jpg"),QStringLiteral("Ina Vaster"),78789665,false});
    mItem.append({QStringLiteral("Image/avatar4.jpg"),QStringLiteral("Pitto Ambros"),91014445,false});

    std::sort(mItem.begin(),mItem.end(),[](const CLPItem&lhs, const CLPItem&rhs){
            return std::lexicographical_compare(lhs.description.begin(),lhs.description.end(),
                                                rhs.description.begin(),rhs.description.end());
        });
}

QVector<CLPItem> CLPList::items() const
{
    return FiltrText!=""?Filtr: mItem;
}

QVector<CLPItem>& CLPList::items_ref()
{
    return FiltrText!=""? Filtr: mItem;
}

bool CLPList::setItemAt(int index, const CLPItem &item)
{
    if(index<0||index>=mItem.size())
        return false;

     const CLPItem& oldItem=mItem.at(index);
     if(item.description==oldItem.description)
         return false;

     mItem[index]=item;
     return true;
}

bool CLPList::isFavorite()
{
    return showFavoriteContact;
}


QString CLPList::getFiltrContact()
{
    return FiltrText;
}


void CLPList::clickedCheckBox(bool state)
{

    showFavoriteContact=state;

    if(showFavoriteContact){
        std::stable_partition(items_ref().begin(),items_ref().end(),[](const CLPItem&lhs){
            return lhs.done;
        });
    }
    else{
        contactFiltr(FiltrText);
        std::sort(items_ref().begin(),items_ref().end(),[](const CLPItem&lhs, const CLPItem&rhs){
                return std::lexicographical_compare(lhs.description.begin(),lhs.description.end(),
                                                    rhs.description.begin(),rhs.description.end());
            });
    }
    emit preShowFavorite();
}

void CLPList::clickedListWiewCheckBox(bool state,int index)
{
    if (FiltrText != "") {
      auto&elem = Filtr[index];
      elem.done = state;
      auto it = std::find_if(mItem.begin(), mItem.end(), [&elem](const CLPItem&lhs){
          return lhs.description == elem.description;
      });
      if (it != mItem.end()) {
          it->done = state;
      }
    } else {
      mItem[index].done=state;
    }
    if(showFavoriteContact==true){
        std::stable_partition(items_ref().begin(),items_ref().end(),[](const CLPItem&lhs){
            return lhs.done;
        });
    }
    emit preOnTurnFavorite();
}

void CLPList::contactFiltr(QString text)
{
    Filtr.clear();
    FiltrText=text;
    if (FiltrText != "") {
        std::copy_if(mItem.begin(),mItem.end(),std::back_inserter(Filtr),[this](const CLPItem&lhs){
            bool is_contains = lhs.description.contains(FiltrText);
            if (is_contains) {
                if (showFavoriteContact)
                  return lhs.done;
                else
                  return true;
            }
            return false;
        });
    }
    emit filtrOnContact();
}


