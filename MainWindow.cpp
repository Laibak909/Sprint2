#include "MainWindow.h"
#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    auto *layout = new QVBoxLayout(centralWidget);
    turnLabel = new QLabel("Current turn: Blue", this);

    auto *btnS = new QPushButton("S", this);
    auto *btnO = new QPushButton("O", this);
    auto *btnNew = new QPushButton("New Game", this);

    grid = new QGridLayout();
    layout->addWidget(turnLabel);
    layout->addWidget(btnS);
    layout->addWidget(btnO);
    layout->addWidget(btnNew);
    layout->addLayout(grid);

    connect(btnNew, &QPushButton::clicked, this, &MainWindow::startNewGame);
    connect(btnS, &QPushButton::clicked, this, &MainWindow::setLetterS);
    connect(btnO, &QPushButton::clicked, this, &MainWindow::setLetterO);

    boardSize = 3;
    controller.setBoardSize(boardSize);
    updateBoard();
}

void MainWindow::setLetterS() { controller.setSelectedLetter('S'); }
void MainWindow::setLetterO() { controller.setSelectedLetter('O'); }

void MainWindow::startNewGame() {
    controller.setBoardSize(boardSize);
    controller.newGame();
    updateBoard();
}

void MainWindow::updateBoard() {
    QLayoutItem *child;
    while ((child = grid->takeAt(0)) != nullptr)
        delete child->widget();

    cells.clear();
    for (int r = 0; r < boardSize; ++r) {
        for (int c = 0; c < boardSize; ++c) {
            auto *btn = new QPushButton(" ", this);
            grid->addWidget(btn, r, c);
            cells.push_back(btn);
            connect(btn, &QPushButton::clicked, this, &MainWindow::cellClicked);
        }
    }
}

void MainWindow::cellClicked() {
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    int index = cells.indexOf(btn);
    int row = index / boardSize;
    int col = index % boardSize;

    if (controller.placeAt(row, col)) {
        btn->setText("S"); // placeholder display
        QString turnText = (controller.currentPlayer() == Player::Blue) ? "Current turn: Blue" : "Current turn: Red";
        turnLabel->setText(turnText);
    } else {
        QMessageBox::information(this, "Invalid", "Cell already filled!");
    }
}
