#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char sat)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = sat;
		}
	}
}

void DisPlayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-----É¨À×ÓÎÏ·----\n");
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-----É¨À×ÓÎÏ·----\n");
}

void SetBoard(char mine[ROWS][COLS], int row, int col)
{
	int count = DiLei;
	while (count)
	{
		int x = rand()%row+1;
		int y = rand()%col+1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
int get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8*'0';
}


void FindBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	
	
	int x = 0;
	int y = 0;
	int n = 0;
	while (n != row * col - DiLei)
	{
		printf("ÇëÊäÈë×ø±ê£º>");
		//DisPlayBoard(show, ROW, COL);
		scanf("%d%d", &x, &y);
		
		//DisPlayBoard(mine, ROW, COL);
		scanf("%d%d", &x, &y);
		system("cls");
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (mine[x][y] == '1')
			{
				printf("ºÜÒÅº¶£¬Äã±»Õ¨ËÀÁË*_*\n");
				DisPlayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				system("cls");
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				DisPlayBoard(show, ROW, COL);
				n++;
			}
		}
		else
		{
			printf("×ø±êÊäÈë´íÎó£¬ÇëÖØÐÂÊäÈë£º>\n");
		}
	}
	if (n == row * col - DiLei)
	{
		printf("¹§Ï²Äã£¡É¨À×³É¹¦!");
	}
}