#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("扫雷游戏\n");
	printf("****************************************\n");
	printf("************   1.开始   ****************\n");
	printf("************   0.结束   ****************\n");
	printf("****************************************\n");
	printf("请选择>：");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	system("cls");
	//打印棋盘
	DisPlayBoard(show, ROW, COL); 

	//设置雷
	SetBoard(mine, ROW, COL);
	//DisPlayBoard(mine, ROW, COL);

	//排查雷
	FindBoard(mine, show, ROW, COL);
}


int main()
{	
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			game();
			break;
		}
		case 0:
		{
			printf("结束\n");
			break;
		}
		default:
		{
			printf("选择错误，请重新输入\n");
			break;
		}
		}
	} while (input);
	return 0;
}