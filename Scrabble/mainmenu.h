#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include "lobby.h"
#include "game.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:

    void on_btn_create_clicked();

private:
    Ui::MainMenu *ui;
    Lobby *lobby;
    Game *shortcut;
};

#endif // MAINMENU_H