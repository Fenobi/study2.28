#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DiLei 10
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

void InitBoard(char board[ROWS][COLS], int rows, int cols, char sat);

void DisPlayBoard(char board[ROWS][COLS], int row, int col);

void SetBoard(char board[ROWS][COLS], int row, int col);

void FindBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);