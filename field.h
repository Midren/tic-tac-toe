#ifndef TIC_TAC_TOE_FIELD_H
#define TIC_TAC_TOE_FIELD_H
#include <vector>
#include <ncurses.h>

constexpr char player_1_sign = 'X';
constexpr char player_2_sign = 'O';
constexpr char space_sign = ' ';

class Field {
public:
    Field();

    Field(const std::vector<std::vector<char> >&);

    void print(int) const;

    char is_winner() const;

    bool is_full() const;

    bool make_step(std::pair<int, int> st, bool current_user);

    const std::vector<std::vector<char> > & get_field() const;

    const bool is_blank(int, int) const;

private:
    std::vector<std::vector<char> > field;

};
#endif //TIC_TAC_TOE_FIELD_H
