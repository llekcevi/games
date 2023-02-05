#include "tictactoe.h"
#include <iostream>
// PUBLIC
// - constructor
TicTacToe::TicTacToe()
{

    win = false;
    humans_turn = true;
    turns = 0;
    empty = '_';
    initializeBoard();
}
// - runs the game
int TicTacToe::run()
{
    srand(time(NULL));

    playGame();

    endGame();

    return 0;
}
// PRIVATE
// - main game loop
void TicTacToe::playGame()
{
    while (!win && turns < 9)
    {
        showBoard();
        inputMove();
        win = checkWinner();
        humans_turn = !humans_turn;
        turns = turns + 1;
    }
}
// - outputs result of the game at the end
void TicTacToe::endGame()
{
    showBoard();
    std::cout << std::endl;
    std::cout << "Game over" << std::endl;
    std::cout << std::endl;
    if (turns == 8)
    {
        std::cout << "Draw" << std::endl;
    }
    else
    {
        std::cout << (turns % 2 == 0 ? "Computer wins" : "Human wins") << std::endl;
    }
}
// - draws the board
void TicTacToe::showBoard()
{
    system("clear");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
// - input functions
void TicTacToe::inputMove()
{
    humans_turn ? inputHuman() : inputComputer();
}

void TicTacToe::inputHuman()
{
    while (true)
    {
        int position;
        std::cout << std::endl;
        std::cout << "Choose your position" << std::endl;
        std::cin >> position;
        if (board[(position - 1) / 3][(position - 1) % 3] == empty)
        {
            board[(position - 1) / 3][(position - 1) % 3] = 'X';
            break;
        }
        else
        {
            std::cout << "position taken" << std::endl;
        }
    }
}

void TicTacToe::inputComputer()
{
    while (true)
    {
        int computer_choice = rand() % 10;

        if (board[(computer_choice - 1) / 3][(computer_choice - 1) % 3] == empty)
        {
            board[(computer_choice - 1) / 3][(computer_choice - 1) % 3] = '0';
            break;
        }
    }
}
// check win functions
bool TicTacToe::checkWinner()
{
    return checkColumn() || checkRow() || checkDiagonalDown() || checkDiagonalUp();
}

bool TicTacToe::checkDiagonalDown()
{
    if (board[0][0] == board[1][1] &&
        board[0][0] == board[2][2] &&
        board[0][0] != empty)
    {
        return true;
    }
    return false;
}

bool TicTacToe::checkDiagonalUp()
{
    if (board[2][0] == board[1][1] &&
        board[2][0] == board[0][1] &&
        board[2][0] != empty)
    {
        return true;
    }
    return false;
}

bool TicTacToe::checkColumn()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[0][i] == board[2][i] && board[0][i] != empty)
        {
            return true;
        }
        else
            continue;
    }
    return false;
}

bool TicTacToe::checkRow()
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == board[i][1]) &&
            (board[i][0] == board[i][2]) && (board[i][0] != empty))
        {
            return true;
        }
        else
            continue;
    }
    return false;
}

void TicTacToe::initializeBoard()
{
    for (int i = 0; i < 3; i++)
    {
        memset(board[i], empty, 3);
    }
}
