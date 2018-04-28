#ifndef TIC_TAC_TOE_PLAYERS_H
#define TIC_TAC_TOE_PLAYERS_H
#include <iostream>
#include <random>
#include <map>
#include "field.h"

class Player {
public:
    Player();
    virtual std::pair<int, int> get_step(const Field&, bool);
};

class HumanPlayerClassical : public Player {
public:
    std::pair<int, int> get_step(const Field& fld, bool current_player) override;
};

class HumanPlayerNcurses : public Player {
public:
    std::pair<int, int> get_step(const Field &fld, bool current_player) override;
};

class LowSkillBotPlayer : public Player {
public:
    std::pair<int, int> get_step(const Field& fl, bool) override;
};

class HighSkillBotPlayer : public Player {
public:
    std::pair<int, int> get_step(const Field& fl, bool current_player) override;
};

int win_rate(const Field&, bool, bool, int);
#endif //TIC_TAC_TOE_PLAYERS_H
