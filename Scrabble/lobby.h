#ifndef LOBBY_H
#define LOBBY_H

#include <QDialog>
#include "game.h"

namespace Ui {
class Lobby;
}

class Lobby : public QDialog
{
    Q_OBJECT

public:
    explicit Lobby(QWidget *parent = nullptr);
    ~Lobby();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Lobby *ui;
    Game *game;

};

#endif // LOBBY_H
