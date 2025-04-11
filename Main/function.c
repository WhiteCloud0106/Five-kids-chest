#include <stdio.h>
#include <stdlib.h>
#include "function.h"

Player check4Winner(char chessboard[19][19])
{
    Player winner;
    for (int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            if(j<=14)
            {
                char temp[5];
                for (int k=0;k<5;k++)
                {
                    temp[k] = chessboard[i][j+k];
                }
                winner = checkHorizontal(&temp);
                if(winner != None)
                    return winner;
            }
            if(i<=14)
            {
                winner = checkVertical((char (*)[19]) &chessboard[i][j]);
                if(winner != None) return winner;
            }
        }
    }
    return None;
}

Player checkHorizontal(char (*p)[5])
{
    int b=0, w=0;
    for(int i=0;i<5;i++)
    {
        if((*p)[i]==Black)
            b++;
        else if((*p)[i]==White)
            w++;
    }
    if(b==5)
        return Black;
    else if(w==5)
        return White;
    else
        return None;
}

Player checkVertical(char (*p)[19])
{
    int b=0, w=0;
    for(int i=0;i<5;i++)
    {
        if(*p[i] == Black)
            b++;
        else if(*p[i] == White)
            w++;
    }
    if(b==5)
        return Black;
    else if(w==5)
        return White;
    else
        return None; 
}