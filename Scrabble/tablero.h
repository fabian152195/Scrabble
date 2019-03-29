#ifndef TABLERO_H
#define TABLERO_H

#include <QObject>
#include <QWidget>


class Tablero : public QWidget
{
    Q_OBJECT

public:
    explicit Tablero(QWidget *parent=nullptr);
protected:
    void dragEnterEvent(QDragEnterEvent *event) Q_DECL_OVERRIDE;
    void dragLeaveEvent(QDragLeaveEvent *event) Q_DECL_OVERRIDE;
    void dragMoveEvent(QDragMoveEvent *event) Q_DECL_OVERRIDE;
    void dropEvent(QDropEvent *event) Q_DECL_OVERRIDE;
};

#endif // TABLERO_H
