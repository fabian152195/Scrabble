#ifndef TABLERO_H
#define TABLERO_H

#include <QObject>
#include <QWidget>
#include <list>
#include "ficha.h"

using namespace std;

class Tablero : public QWidget
{
    Q_OBJECT

public:
    explicit Tablero(QWidget *parent=nullptr);
    static list<Ficha> toDraw;
    static list<Ficha> toErase;
protected:
    bool disponibles[15][15];
    void dragEnterEvent(QDragEnterEvent *event) Q_DECL_OVERRIDE;
    void dragLeaveEvent(QDragLeaveEvent *event) Q_DECL_OVERRIDE;
    void dragMoveEvent(QDragMoveEvent *event) Q_DECL_OVERRIDE;
    void dropEvent(QDropEvent *event) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif // TABLERO_H
