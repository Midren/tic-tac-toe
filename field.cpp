#include "field.h"
#include <iostream>
#include <ncurses.h>

Field::Field() : field(std::vector<std::vector<char> >(3, std::vector<char>(3, ' '))) {}

Field::Field(const std::vector<std::vector<char> > &fld) : field(fld) {}

void Field::print(int mod) const {
    if (mod == 0) {
        std::cout << "  a b c";
        for (size_t i = 0; i < field.size(); ++i) {
            std::cout << "\n" << i + 1 << " ";
            for (size_t j = 0; j < field[i].size(); ++j) {
                std::cout << field[i][j] << "|";
            }
            std::cout << "\b\n" << "  -----";
        }
        std::cout << "\b\b\b\b\b" << "     \n";
    } else if (mod == 1) {
        clear();
        int ymax, xmax;
        getmaxx(stdscr);
        getmaxyx(stdscr, ymax, xmax);
        WINDOW *menuwin = newwin(7, 7, (ymax - 7) / 2, (xmax - 7) / 2);
        refresh();
        wrefresh(menuwin);
        box(menuwin, 0, 0);
        for (size_t i = 0; i < 3; i++) {
            for (size_t j = 0; j < 3; j++) {
                mvwprintw(menuwin, i * 2 + 1, j * 2 + 1, "%c", field[i][j]);
                if (j != 2) mvwprintw(menuwin, i * 2 + 1, (j + 1) * 2, "|");
            }
            if (i != 2) mvwprintw(menuwin, (i + 1) * 2, 1, "-----");
        }
        wrefresh(menuwin);
    }
}

char Field::is_winner() const {
    bool diag_left = true, diag_right = true;
    for (size_t i = 0; i < field.size(); ++i) {
        bool win_line = true, win_column = true;
        for (size_t j = 1; j < field[i].size(); ++j) {
            if (field[i][j] != field[i][j - 1] || field[i][j] == space_sign)
                win_line = false;
            if (field[j][i] != field[j - 1][i] || field[j][i] == space_sign)
                win_column = false;
        }
        if (win_line) {
            return field[i][0];
        }
        if (win_column) {
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
    for (size_t i = 0; i < field.size(); ++i)
        for (size_t j = 0; j < field.size(); ++j)
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

const std::vector<std::vector<char> > &Field::get_field() const {
    return field;
}

const bool Field::is_blank(int x, int y) const {
    return field[x][y] == space_sign;
}
