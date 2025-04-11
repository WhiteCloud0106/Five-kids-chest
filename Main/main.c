#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    //皆為參賽指引程式碼
    char chessboard[19][19];
    char letters[19]="ABCDEFGHIJKLMNOPQRS"; 
    int row=0, col=0;
    int quit=0;
    srand((unsigned long int)&row);

    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            scanf(" %c", &chessboard[i][j]);
        }
    }

    if(strcmp(argv[1],"Black")==0)
    {
        // 要下黑子
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
    else 
    {
        // 要下白子
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
}