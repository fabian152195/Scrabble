#ifndef LOBBY_H
#define LOBBY_H

#include <QDialog>
#include "game.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

namespace Ui {
class Lobby;
}

class Lobby : public QDialog
{
    Q_OBJECT

public:
    explicit Lobby(bool newLobby, int room_number, QWidget *parent = nullptr);
    ~Lobby();
    void addPlayer(QString name);
    void removePlayer(QString number);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    QString my_name;
    int c_players;
    QImage my_image;
    list<QHBoxLayout*> players;
    Ui::Lobby *ui;
    Game *game;
    void clearLayout(QLayout *layout);
};

#endif // LOBBY_H
