#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H
#include "players.h"

class Game {
public:
    Game(Player* pl1, Player* pl2);
    void play();

private:
    Field field;
    std::pair<Player*, Player*> players;
    bool current_user;
};

#endif //TIC_TAC_TOE_GAME_H
