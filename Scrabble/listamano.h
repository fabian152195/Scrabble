#ifndef LISTAMANO_H
#define LISTAMANO_H

#include <QWidget>
#include <QListWidget>

class ListaMano: public QListWidget
{
    Q_OBJECT
public:
    explicit ListaMano(QWidget *parent=nullptr);
    void addFicha(QPixmap pixmap, QPoint, QChar letra);
protected:
    void startDrag(Qt::DropActions supportedActions) Q_DECL_OVERRIDE;
};

#endif // LISTAMANO_H
