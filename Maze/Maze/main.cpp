#include "queue.h"
#include "queue.cpp"

int main()
{
	int test_c = 1;
	char map[16][16];
	int py[4] = { -1, 1, 0, 0 };
	int px[4] = { 0, 0, -1, 1 };

	while (test_c <= 10)
	{
		Queue<int> queue;
		int flag = 0;
		scanf("%d", &test_c);
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 16; j++)
			{
				scanf(" %c ", &map[i][j]);
				if (map[i][j] == '2')
				{
					queue.enqueue(i);
					queue.enqueue(j);
					map[i][j] = 1;
				}
			}
		}
		while (queue.size() && !flag)
		{
			int temp_r = queue.dequeue();
			int temp_c = queue.dequeue();
			for (int i = 0; i < 4; i++)
			{
				if (temp_r + py[i] >= 0 && temp_r + py[i] <= 15 && temp_c + px[i] >= 0 && temp_c + px[i] <= 15 && map[temp_r + py[i]][temp_c + px[i]] != '1')
				{
					if (map[temp_r + py[i]][temp_c + px[i]] == '3')
						flag = 1;
					queue.enqueue(temp_r + py[i]);
					queue.enqueue(temp_c + px[i]);
					map[temp_r + py[i]][temp_c + px[i]] = '1';
				}
			}
		}
		if (flag == 1)
			printf("#%d 1\n", test_c);
		else
			printf("#%d 0\n", test_c);
		queue.free();
		test_c++;
	}
}