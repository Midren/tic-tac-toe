#ifndef TIC_TAC_TOE_FIELD_H
#define TIC_TAC_TOE_FIELD_H
#include <vector>

class Field {
public:
    Field();

    Field(const std::vector<std::vector<char> >&);

    void print() const;

    char is_winner() const;

    bool is_full() const;

    bool make_step(std::pair<int, int> st, bool current_user);

    const std::vector<std::vector<char> > & get_field() const;
private:
    std::vector<std::vector<char> > field;

};
#endif //TIC_TAC_TOE_FIELD_H
