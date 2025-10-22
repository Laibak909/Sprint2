#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Board.h"
#include "Player.h"
#include "GameMode.h"

class GameController {
public:
    GameController();
    void setBoardSize(int n);
    void setMode(GameMode mode);
    void newGame();
    bool placeAt(int row, int col);
    Player currentPlayer() const { return current_; }
    void setSelectedLetter(char letter);

private:
    Board board_;
    Player current_;
    GameMode mode_;
    char selectedLetter_;
    void switchTurn();
};

#endif
