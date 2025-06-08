#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "function.h"

Pattern fits[] = 
{
        //我方下一步獲勝
        {".SSSS.", 100000, 0, 0},  // 我方活四
        {".SSS.S", 100000, 4, 1},  // 我方洞四
        {".SS.SS", 100000, 3, 1},  // 我方洞四
        {".S.SSS", 100000, 2, 1},  // 我方洞四
        {".SSSSO", 100000, 0, 0},  // 我方死四

        //對方下一步獲勝
        {".OOOO.", 10000, 0, 0},  // 對方活四
        {".OOO.O", 10000, 4, 1},  // 對方活四
        {".OO.OO", 10000, 3, 1},  // 對方活四
        {".O.OOO", 10000, 2, 1},  // 對方活四
        {".OOOOS", 10000, 0, 0},  // 對方死四

        //我方三子
        {".SSS.", 2000, 0, 0},    // 我方活三
        {".SSSO", 1500, 0, 0},    // 我方死三
        {".S.SS.", 2500, 2, 1},   // 我方洞三
        {".SS.S.", 2500, 3, 1},   // 我方洞三
        {".S.SSO", 1000, 2, 1},   // 我方洞三
        {".SS.SO", 1000, 3, 1},   // 我方洞三

        //對方三子
        {".OOO.", 1000, 0, 0},    // 對方活三
        {".OOOS", 900, 0, 0},     // 對方死三
        {".O.OO.",1500, 2, 1},     // 對方洞三
        {".OO.O.", 1500, 3, 1},    // 對方洞三
        {".O.OOS", 800, 2, 1},    // 對方洞三
        {".OO.OS", 800, 3, 1},    // 對方洞三

        //其他
        {".SS.", 200, 0, 0},       // 我方活二
        {".OO.", 100, 0, 0},       // 對方活二
        {".S.", 10, 0, 0},         // 我方單子
        {NULL, 0, 0, 0}            // 結束標記
};

void checkBoard(char chessboard[19][19], Player player)
{
    char letters[19]="ABCDEFGHIJKLMNOPQRS";
    int scoreboard[19][19]={0};
    char chess[7];
    Weight result={0, 0, 0};
    for (int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            if(chessboard[i][j]=='.')
            {
                scoreboard[i][j] += 1;
                if(j<=14)
                {
                    if(j<=13)
                    {
                        for (int k=0;k<6;k++)
                        {
                            chess[k] = chessboard[i][j+k*1];
                        }
                    }
                    else
                    {
                        for (int k=0;k<5;k++)
                        {
                            chess[k] = chessboard[i][j+k*1];
                        }
                        chess[5] = '#';
                    }
                    chess[6] = '\0';
                    result = checkLine(chess, i, j, player);
                    scoreboard[i][j] += result.weight;
                    if(result.offset!=0)
                    {
                        scoreboard[i][j+result.offset] += result.offsetweight;
                        result.offset = 0;
                    }
                }
                if(i<=14)
                {
                    if(i<=13)
                    {
                        for (int k=0;k<6;k++)
                        {
                            chess[k] = chessboard[i+k*1][j];
                        }
                    }
                    else
                    {
                        for (int k=0;k<5;k++)
                        {
                            chess[k] = chessboard[i+k*1][j];
                        }
                        chess[5] = '#';
                    }
                    chess[6] = '\0';
                    result = checkLine(chess, i, j, player);
                    scoreboard[i][j] += result.weight;
                    if(result.offset!=0)
                    {
                        scoreboard[i+result.offset][j] += result.offsetweight;
                        result.offset = 0;
                    }
                }
                if(j>=4)
                {
                    if(j>=5)
                    {
                        for (int k=0;k<6;k++)
                        {
                            chess[k] = chessboard[i][j+k*-1];
                        }
                    }
                    else
                    {
                        for (int k=0;k<5;k++)
                        {
                            chess[k] = chessboard[i][j+k*-1];
                        }
                        chess[5] = '#';
                    }
                    chess[6] = '\0';
                    result = checkLine(chess, i, j, player);
                    scoreboard[i][j] += result.weight;
                    if(result.offset!=0)
                    {
                        scoreboard[i][j-result.offset] += result.offsetweight;
                        result.offset = 0;
                    }
                }
                if(i>=4)
                {
                    if(i>=5)
                    {
                        for (int k=0;k<6;k++)
                        {
                            chess[k] = chessboard[i+k*-1][j];
                        }
                    }
                    else
                    {
                        for (int k=0;k<5;k++)
                        {
                            chess[k] = chessboard[i+k*-1][j];
                        }
                        chess[5] = '#';
                    }
                    chess[6] = '\0';
                    result = checkLine(chess, i, j, player);
                    scoreboard[i][j] += result.weight;
                    if(result.offset!=0)
                    {
                        scoreboard[i-result.offset][j] += result.offsetweight;
                        result.offset = 0;
                    }
                }
                if(i<=14&&j<=14)
                {
                    if(i<=13&&j<=13)
                    {
                        for (int k=0;k<6;k++)
                        {
                            chess[k] = chessboard[i+k*1][j+k*1];
                        }
                    }
                    else
                    {
                        for (int k=0;k<5;k++)
                        {
                            chess[k] = chessboard[i+k*1][j+k*1];
                        }
                        chess[5] = '#';
                    }
                    chess[6] = '\0';
                    result = checkLine(chess, i, j, player);
                    scoreboard[i][j] += result.weight;
                    if(result.offset!=0)
                    {
                        scoreboard[i+result.offset][j+result.offset] += result.offsetweight;
                        result.offset = 0;
                    }
                }
                if(i>=4&&j<=14)
                {
                    if(i>=5&&j<=13)
                    {
                        for (int k=0;k<6;k++)
                        {
                            chess[k] = chessboard[i+k*-1][j+k*1];
                        }
                    }
                    else
                    {
                        for (int k=0;k<5;k++)
                        {
                            chess[k] = chessboard[i+k*-1][j+k*1];
                        }
                        chess[5] = '#';
                    }
                    chess[6] = '\0';
                    result = checkLine(chess, i, j, player);
                    scoreboard[i][j] += result.weight;
                    if(result.offset!=0)
                    {
                        scoreboard[i-result.offset][j+result.offset] += result.offsetweight;
                        result.offset = 0;
                    }
                }
                if(i<=14&&j>=4)
                {
                    if(i<=13&&j>=5)
                    {
                        for (int k=0;k<6;k++)
                        {
                            chess[k] = chessboard[i+k*1][j+k*-1];
                        }
                    }
                    else
                    {
                        for (int k=0;k<5;k++)
                        {
                            chess[k] = chessboard[i+k*1][j+k*-1];
                        }
                        chess[5] = '#';
                    }
                    chess[6] = '\0';
                    result = checkLine(chess, i, j, player);
                    scoreboard[i][j] += result.weight;
                    if(result.offset!=0)
                    {
                        scoreboard[i+result.offset][j-result.offset] += result.offsetweight;
                        result.offset = 0;
                    }
                }
                if(i>=4&&j>=4)
                {
                    if(i>=5&&j>=5)
                    {
                        for (int k=0;k<6;k++)
                        {
                            chess[k] = chessboard[i+k*-1][j+k*-1];
                        }
                    }
                    else
                    {
                        for (int k=0;k<5;k++)
                        {
                            chess[k] = chessboard[i+k*1][j+k*-1];
                        }
                        chess[5] = '#';
                    }
                    chess[6] = '\0';
                    result = checkLine(chess, i, j, player);
                    scoreboard[i][j] += result.weight;
                    if(result.offset!=0)
                    {
                        scoreboard[i-result.offset][j-result.offset] += result.offsetweight;
                        result.offset = 0;
                    }
                }
            }
            else
            {
                scoreboard[i][j] = 0;
            }
        }
    }

    int max=0, maxi=10, maxj=10;
    //printf("\n");
    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            if(scoreboard[j][i]>max)
            {
                max = scoreboard[j][i];
                maxi = i;
                maxj = j;
                
            }
            //printf("%6d|", scoreboard[i][j]);
        }
        //printf("\n");
    }
    printf("%c, %d\n", letters[maxi], maxj+1);
}

Weight checkLine(char chess[7], int x, int y, Player player)
{
    char finale[7];
    if(player==Black)
    {
        for(int i=0;i<6;i++)
        {
            if(chess[i]=='1') finale[i] = 'S';
            else if(chess[i]=='0'||chess[i]=='#') finale[i] = 'O';
            else finale[i] = chess[i];
        }
    }
    if(player==White)
    {
        for(int i=0;i<6;i++)
        {
            if(chess[i]=='0') finale[i] = 'S';
            else if(chess[i]=='1'||chess[i]=='#') finale[i] = 'O';
            else finale[i] = chess[i];
        }
    }
    finale[6] = '\0';

    Weight result={0, 0, 0};
    for(int c=0;fits[c].pattern!=NULL;c++)
    {
        int len=strlen(fits[c].pattern);
        if(strncmp(finale, fits[c].pattern, len)==0) 
        {   
            result.weight += fits[c].weight;
            if(fits[c].hole==1)
            {
                result.weight -= fits[c].weight;
                result.offset = fits[c].offset;
                result.offsetweight = fits[c].weight;
            }
        }

    }

    return result;
}
