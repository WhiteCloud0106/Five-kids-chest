#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

int main(int argc, char *argv[])
{
    char chessboard[19][19];
    char letters[19]="ABCDEFGHIJKLMNOPQRS";
    Player player;
    int b=0, w=0;

    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            scanf(" %c", &chessboard[i][j]);
            if(chessboard[i][j]=='1')
                b++;
            else if(chessboard[i][j]=='0')
                w++;
        }
    }

    if(strcmp(argv[1], "Black")==0) player=Black;
    else player=White;

    //起始子
    if(strcmp(argv[1],"Black")==0 && b==0 && w==0)
    {
        printf("J, 10");
        exit(0);
    }

    //落子
    checkBoard(chessboard, player);
}