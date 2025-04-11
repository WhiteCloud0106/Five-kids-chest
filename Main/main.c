#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main ()
{
    //皆為參賽指引程式碼
    char chessboard[19][19];
    
    for(int i=0; i<19; i++)
    {
        for(int j=0; j<19; j++)
        {
            scanf(" %c", &chessboard[i][j]);
        }
    }

    char letters[19]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S'}; 
    int row=0, col=0;

    srand((unsigned long int)&row);
    row = rand()%19;
    col = rand()%19;
    printf("%c, %d\n", letters[col], row+1);
}