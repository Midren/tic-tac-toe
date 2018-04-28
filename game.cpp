#include "game.h"

Game::Game(Player *pl1, Player *pl2, int mod) : field(Field()), players(std::make_pair(pl1, pl2)), current_user(0), mod(mod) {}

std::pair<bool, bool> Game::play() {
    while (true) {
        field.print(mod);
        std::pair<int, int> st = !current_user ? players.first->get_step(field, current_user)
                                               : players.second->get_step(field,
                                                                          current_user);
        field.make_step(st, current_user);
        current_user = !current_user;
        char win = field.is_winner();
        if (win != 0) {
            field.print(mod);
            return std::make_pair(true, !current_user);
        }
        if (field.is_full()) {
            field.print(mod);
            return std::make_pair(false, current_user);
        }
    }
}


