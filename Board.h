#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
public:
    Board();
    bool setSize(int n);
    int size() const { return n_; }
    bool place(int row, int col, char letter);
    char at(int row, int col) const;

private:
    int n_;
    std::vector<std::vector<char>> grid_;
};

#endif
