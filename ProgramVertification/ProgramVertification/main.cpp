#include <stdio.h>

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int flag = 1;

void initialize(char buf1[20][20], char buf2[20][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			buf1[i][j] = -1;
			buf2[i][j] = -1;
		}
	}
}

int judge_chr(char c, int *dir, int *mem)
{
	if ('0' <= c && c <= '9')
		*mem = c - '0';
	else if (c == '<')
		*dir = 2;
	else if (c == '>')
		*dir = 3;
	else if (c == '^')
		*dir = 0;
	else if (c == 'v')
		*dir = 1;
	else if (c == '_')
	{
		if (mem == 0)
			*dir = 3;
		else
			*dir = 2;
	}
	else if (c == '|')
	{
		if (mem == 0)
			*dir = 1;
		else
			*dir = 0;
	}
	else if (c == '?')
		return (1);
	else if (c == '@')
		return (2);
	else if (c == '+')
		*mem += 1;
	else if (c == '-')
		*mem -= 1;
}

void dfs(char map[20][20], int *mem, int *dir)
{

}

int main()
{
	int test_c;
	int row, col;
	int mem, dir;
	char map[20][20];
	char buf_dir[20][20];
	char buf_mem[20][20];

	scanf("%d", &test_c);
	for (int test_n = 0; test_n <= test_c; test_n++)
	{
		int temp_y = 0;
		int temp_x = -1;

		mem = 0;
		dir = 3;
		flag = 1;
		initialize(buf_dir, buf_mem);
		scanf("%d %d\n", &row, &col);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				scanf(" %c ", &map[i][j]);
		}
		
		//this part to function, and brute-force
		//two maps -> one map to last direction, one map to memory
		//if two are same with current -> false
		while (flag)
		{
			int temp;

			if (temp_y + dy[dir] < 0)
				temp_y = row;
			else if (temp_y + dy[dir] >= row)
				temp_y = -1;
			if (temp_x + dx[dir] < 0)
				temp_x = col;
			else if (temp_x + dx[dir] >= col)
				temp_x = -1;
			temp_y = temp_y + dy[dir];
			temp_x = temp_x + dx[dir];
			if ((temp = judge_chr(map[temp_y][temp_x], &dir, &mem)) == 2)
				break;
			//else if
		}
	}
}