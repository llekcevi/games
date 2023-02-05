#ifndef tictactoe_class_h
#define tictactoe_class_h
class TicTacToe
{
private:
    bool win;
    bool humans_turn;
    char board[3][3];
    short int turns;
    char empty;

public:
    TicTacToe();
    int run();
    ~TicTacToe(){};

private:
    void initializeBoard();
    void playGame();
    void endGame();
    void showBoard();
    void inputMove();
    void inputHuman();  
    void inputComputer();
    bool checkWinner();
    bool checkRow();
    bool checkColumn();
    bool checkDiagonalUp();
    bool checkDiagonalDown();
};
#endif