#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H
#include "players.h"
template<typename T, typename F>
class Game {
public:
    Game(T pl1, F pl2);
    void play();

private:
    Field field;
    std::pair<T, F> players;
    bool current_user;
};

#endif //TIC_TAC_TOE_GAME_H
