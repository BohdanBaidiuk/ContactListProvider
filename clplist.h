#ifndef TODOLIST_H
#define TODOLIST_H

#include <QObject>
#include <QVector>
#include <QQuickView>


struct CLPItem{
   QString imege;
   QString description;
   int phoneNumber;
   bool done;
};

class CLPList : public QObject
{
    Q_OBJECT
public:
    explicit CLPList(QObject *parent = nullptr);

    QVector<CLPItem>items()const;
    QVector<CLPItem>& items_ref();
    bool setItemAt(int index,const CLPItem&item);
    bool isFavorite();
    QString getFiltrContact();

signals:


    void preShowFavorite();

    void preOnTurnFavorite();
    void filtrOnContact();
public slots:

    void clickedCheckBox(bool state);
    void clickedListWiewCheckBox(bool state,int index);
    void contactFiltr(QString text);

private:
    QVector<CLPItem>mItem;
    QVector<CLPItem>Filtr;
    bool showFavoriteContact{false};
    QString FiltrText{};
};

#endif // TODOLIST_H
