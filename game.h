#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H
#include "players.h"

class Game {
public:
    Game(Player* pl1, Player* pl2, int mod);
    std::pair<bool, bool> play();

private:
    Field field;
    std::pair<Player*, Player*> players;
    bool current_user;
    int mod;
};

#endif //TIC_TAC_TOE_GAME_H
