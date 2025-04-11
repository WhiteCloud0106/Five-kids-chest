typedef enum
{
    Black = 49,
    White = 48,
    None = 0
} Player;

Player checkHorizontal(char (*p)[5]);
Player checkVertical(char (*p)[19]);
Player checkDiagonal(char (*p)[19]);
Player checkBackDiagonal(char (*p)[19]);

Player check4Winner(char chessboard[19][19]);
