#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "function.h"

int main(int argc, char *argv[])
{
    //皆為參賽指引程式碼
    char chessboard[19][19];
    char letters[19]="ABCDEFGHIJKLMNOPQRS";
    Player winner;
    int row=0, col=0;
    int quit=0;
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
/*
    //忽略這段
    winner = check4Winner(chessboard);
    if(winner==Black)
        printf("Black win!\n");
    else if(winner==White)
        printf("White win!\n");
    else
        printf("Quack! Quack!\n");
*/
    //起始子
    if(strcmp(argv[1],"Black")==0 && b==0 && w==0)
    {
        printf("J, 10");
        exit(0);
    }
    
    //亂數落子
    srand((time(NULL)));
    while(!quit)
    {
        row = rand()%19;
        col = rand()%19;
        if(chessboard[row][col] == '.')
        {
            printf("%c, %d\n", letters[col], row+1);
            quit = 1;
        }
    }
}