#include "field.h"
#include <iostream>

Field::Field() : field(std::vector<std::vector<char> >(3, std::vector<char>(3, ' '))) {}

Field::Field(const std::vector<std::vector<char> >& fld) : field(fld) {}

void Field::print() const {
    std::cout << "  a b c";
    for (int i = 0; i < field.size(); ++i) {
        std::cout << "\n" << i + 1 << " ";
        for (int j = 0; j < field[i].size(); ++j) {
            std::cout << field[i][j] << "|";
        }
        std::cout << "\b\n" << "  -----";
    }
    std::cout << "\b\b\b\b\b" << "     \n";
}

char Field::is_winner() const{
    bool diag_left = true, diag_right = true;
    for (int i = 0; i < field.size(); ++i) {
        bool win_line = true, win_column = true;
        for (int j = 1; j < field[i].size(); ++j) {
            if (field[i][j] != field[i][j - 1] || field[i][j] == space_sign)
                win_line = false;
            if (field[j][i] != field[j - 1][i] || field[j][i] == space_sign)
                win_column = false;
        }
        if(win_line){
            return field[i][0];
        }
        if(win_column){
            return field[0][i];
        }
        if (i == 0) continue;
        if (field[i][i] != field[i - 1][i - 1])
            diag_left = false;
        if (field[i][field.size() - i - 1] != field[i - 1][field.size() - i])
            diag_right = false;

    }
    if (field[1][1] != space_sign)
        if (diag_left || diag_right) return field[1][1];
    return 0;
}

bool Field::is_full() const {
    for (int i = 0; i < field.size(); ++i)
        for (int j = 0; j < field.size(); ++j)
            if (field[i][j] == space_sign) return false;
    return true;
}

bool Field::make_step(std::pair<int, int> st, bool current_user) {
    if (field[st.first][st.second] != space_sign) {
        return false;
    }
    field[st.first][st.second] = current_user ? player_2_sign : player_1_sign;
    return true;
}

const std::vector<std::vector<char> > & Field::get_field() const {
    return field;
}
