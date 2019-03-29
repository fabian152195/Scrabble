#include "listamano.h"
#include <QDrag>
#include <QDebug>
#include <QMimeData>

ListaMano::ListaMano(QWidget *parent):QListWidget (parent)
{
    setDragEnabled(true);
    setViewMode(QListView::IconMode);
    setIconSize(QSize(53,33));
    setSpacing(5);
    setAcceptDrops(true);
    setDropIndicatorShown(true);
}

void ListaMano::startDrag(Qt::DropActions /*supportedActions*/){
    qDebug() << "Flag!";
    QListWidgetItem *item = currentItem(); // Se refiere al item actualmente higlighted

    // Se necesita primero codificar lo que se va a carrear en el drag
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    QPixmap pixmap = qvariant_cast<QPixmap>(item->data(Qt::UserRole));
    QPoint location = item->data(Qt::UserRole+1).toPoint();

    dataStream << pixmap << location << item->text() << " ";

    QDrag *drag = new QDrag(this);
    QPixmap img = qvariant_cast<QPixmap>(item->data(Qt::UserRole));
    QMimeData *mime = new QMimeData;
    mime->setData("image", itemData);
    drag->setMimeData(mime);  // Es necesariisimo
    drag->setPixmap(img);
    drag->exec();
    /*
    Recordar que el drag transporta datos
    que va a ser necesario pasar al tablero
    donde voy a hacer el drop.
    */
}

void ListaMano::addFicha(QPixmap pixmap, QPoint location,QChar lettre)
{
    QListWidgetItem *pieceItem = new QListWidgetItem(this);
    pieceItem->setText(lettre);
    // Necesario para el formateo en el drag
    pieceItem->setIcon(QIcon(pixmap));
    pieceItem->setData(Qt::UserRole, QVariant(pixmap));
    pieceItem->setData(Qt::UserRole+1, location);
  //  pieceItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);

    //main_m->append(lettre);

}
