#include <gtest/gtest.h>
#include "Board.h"
#include "GameController.h"

TEST(BoardTest, AcceptsValidSize) {
    Board b;
    EXPECT_TRUE(b.setSize(8));
    EXPECT_EQ(b.size(), 8);
}

TEST(BoardTest, RejectsTooSmallSize) {
    Board b;
    EXPECT_FALSE(b.setSize(2));
    EXPECT_EQ(b.size(), 3);
}

TEST(BoardTest, PreventsOverwrite) {
    Board b;
    b.setSize(3);
    EXPECT_TRUE(b.place(0, 0, 'S'));
    EXPECT_FALSE(b.place(0, 0, 'O'));
    EXPECT_EQ(b.at(0, 0), 'S');
}

TEST(GameControllerTest, AlternatesTurnAfterMove) {
    GameController g;
    g.setBoardSize(3);
    g.newGame();
    g.setSelectedLetter('S');
    EXPECT_TRUE(g.placeAt(0, 0));
    EXPECT_NE(g.currentPlayer(), Player::Blue);
}
