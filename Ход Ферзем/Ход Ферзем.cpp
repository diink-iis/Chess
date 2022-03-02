#include <iostream>
using namespace std;

int board[8][8]; // Доска; 1 - ферзь

int chk(int c, int r)  // Проверка, что можно ставить в клетку [r][c] 
{                      // проверка - только слева!
	for (int i = 0; i < c; ++i)
	{
		// Проверка горизонтали
		if (board[i][r]) return 0;
		// Проверка диагонали
		if (r - c + i >= 0) if (board[i][r - c + i]) return 0;
		if (r + c - i < 8) if (board[i][r + c - i]) return 0;
	}
	return 1;
}

// Сама рекурсивная функция
int vert(int i) // Установка i-й вертикали
{
	if (i == 8) return 1;  // Ура, расставили
	for (int j = 0; j < 8; ++j)  // Ищем место по ввертикали
		if (chk(i, j))           // Если можно - 
		{
			board[i][j] = 1;    // ставим
			if (vert(i + 1)) return 1; // получилось!
			board[i][j] = 0;    // не получилось - убираем ферзя
		}
	return 0;
}

int main(int argc, char* argv[])
{
	vert(0);
	// ... и сам вывод ...
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
			cout << (board[i][j] ? '*' : '.');
		cout << endl;
	}
}