typedef enum
{
    Black = 49,
    White = 48,
    None = 0
} Player;

typedef struct
{
    const char *pattern;
    int weight;
    int offset;
    int hole;
} Pattern;

typedef struct
{
    int weight;
    int offset;
    int offsetweight;
} Weight;


void checkBoard();
Weight checkLine();
extern int scoreboard[19][19];
