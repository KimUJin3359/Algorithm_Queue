#include <stdio.h>

void initiailize(char map[20][20], int temp[20][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			map[i][j] = 0;

		}
	}
}

int main()
{
	char map[20][20];
	int last_v[20][20];
	int test_c = 1;
	int rep;
	int row, col;
	int dcol[4] = { 0, 0, -1, 1 };
	int drow[4] = { -1, 1, 0, 0 };
	int now_r = 0, now_c = 0;

	scanf("%d", &rep);
	while (test_c <= rep)
	{
		int dir = 3;
		int mem = 0;

		initiailize(map, last_v);
		scanf("%d %d", &row, &col);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				scanf(" %c ", &map[row][col]);
		}
		while (true)
		{
			if (map[now_r][now_c] == '<')
				dir = 2;
			else if (map[now_r][now_c] == '>')
				dir = 3;
			else if (map[now_r][now_c] == '^')
				dir = 0;
			else if (map[now_r][now_c] == 'v')
				dir = 1;
			else if (map[now_r][now_c] == '_')
			{
				if (mem == 0)
					dir = 3;
				else
					dir = 2;
			}
			else if (map[now_r][now_c] == '|')
			{
				if (mem == 0)
					dir = 1;
				else
					dir = 0;
			}
			else if ()
		}
	}
}