#include "GameController.h"

GameController::GameController()
    : current_(Player::Blue), mode_(GameMode::Simple), selectedLetter_('S') {}

void GameController::setBoardSize(int n) {
    board_.setSize(n);
}

void GameController::setMode(GameMode mode) {
    mode_ = mode;
}

void GameController::newGame() {
    board_.setSize(board_.size());
    current_ = Player::Blue;
}

void GameController::setSelectedLetter(char letter) {
    if (letter == 'S' || letter == 'O')
        selectedLetter_ = letter;
}

bool GameController::placeAt(int row, int col) {
    bool placed = board_.place(row, col, selectedLetter_);
    if (placed) switchTurn();
    return placed;
}

void GameController::switchTurn() {
    current_ = (current_ == Player::Blue) ? Player::Red : Player::Blue;
}
