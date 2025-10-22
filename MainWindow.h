#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include "GameController.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
private slots:
    void startNewGame();
    void cellClicked();
    void setLetterS();
    void setLetterO();
private:
    QWidget *centralWidget;
    QGridLayout *grid;
    QLabel *turnLabel;
    GameController controller;
    QVector<QPushButton*> cells;
    int boardSize;
    void updateBoard();
};

#endif
