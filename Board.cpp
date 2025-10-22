#include "Board.h"
#include <stdexcept>

Board::Board() : n_(3), grid_(3, std::vector<char>(3, ' ')) {}

bool Board::setSize(int n) {
    if (n <= 2) return false;
    n_ = n;
    grid_ = std::vector<std::vector<char>>(n, std::vector<char>(n, ' '));
    return true;
}

bool Board::place(int row, int col, char letter) {
    if (row < 0 || col < 0 || row >= n_ || col >= n_) return false;
    if (grid_[row][col] != ' ') return false;
    if (letter != 'S' && letter != 'O') return false;
    grid_[row][col] = letter;
    return true;
}

char Board::at(int row, int col) const {
    if (row < 0 || col < 0 || row >= n_ || col >= n_) return '?';
    return grid_[row][col];
}
