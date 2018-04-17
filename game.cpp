#include "game.h"

Game::Game(Player* pl1, Player* pl2) : field(Field()), players(std::make_pair(pl1, pl2)), current_user(0) {}

void Game::play() {
    while (true) {
        field.print();
        std::pair<int, int> st = !current_user ? players.first->get_step(field, current_user) : players.second->get_step(field,
                                                                                                                 current_user);
        field.make_step(st, current_user);
        current_user = !current_user;
        char win = field.is_winner();
        if(win != 0) {
            field.print();
            std::cout << std::endl << "Congratulations to Player №" << !current_user + 1 << std::endl;
            break;
        }
        if(field.is_full()) {
            field.print();
            std::cout << std::endl << "Oh! It's draw" << std::endl;
            break;
        }
    }
}

