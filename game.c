#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("ɨ����Ϸ\n");
	printf("****************************************\n");
	printf("************   1.��ʼ   ****************\n");
	printf("************   0.����   ****************\n");
	printf("****************************************\n");
	printf("��ѡ��>��");
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//��ʼ������
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	system("cls");
	//��ӡ����
	DisPlayBoard(show, ROW, COL); 

	//������
	SetBoard(mine, ROW, COL);
	//DisPlayBoard(mine, ROW, COL);

	//�Ų���
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
			printf("����\n");
			break;
		}
		default:
		{
			printf("ѡ���������������\n");
			break;
		}
		}
	} while (input);
	return 0;
}