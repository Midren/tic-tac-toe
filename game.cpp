#include "game.h"

template class Game<HumanPlayer, HumanPlayer>;
template class Game<LowSkillBotPlayer, LowSkillBotPlayer>;
template class Game<HighSkillBotPlayer, HighSkillBotPlayer>;

template class Game<HumanPlayer, LowSkillBotPlayer>;
template class Game<LowSkillBotPlayer, HumanPlayer>;

template class Game<HumanPlayer, HighSkillBotPlayer>;
template class Game<HighSkillBotPlayer, HumanPlayer>;

template class Game<LowSkillBotPlayer, HighSkillBotPlayer>;
template class Game<HighSkillBotPlayer, LowSkillBotPlayer>;

template<typename T, typename F>
Game<T, F>::Game(T pl1, F pl2) : field(Field()), players(std::make_pair(pl1, pl2)), current_user(0) {}

template<typename T, typename F>
void Game<T, F>::play() {
    while (true) {
        field.print();
        std::pair<int, int> st = current_user ? players.first.get_step(field, current_user) : players.second.get_step(field,
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

