#include "queue.h"
#include "queue.cpp"

data content;
bool map[101][101] = { false, };
bool visited[101] = { false, };

int main()
{
	Queue<data> queue;

	int flag = 1;
	int test_c = 1;
	int start_p;
	int rep;
	int from, to;

	while (test_c <= 10)
	{
		int max_dis = -1;
		int max_val = -1;

		scanf("%d", &rep);
		scanf("%d", &start_p);
		for (int i = 0; i < (rep / 2); i++)
		{
			scanf("%d %d", &from, &to);
			map[from][to] = true;
		}
		content.data = start_p;
		content.dis = 0;
		content.par = 0;
		visited[start_p] = true;
		queue.enqueue(content);
		while (queue.size() && flag)
		{
			flag = 0;
			data temp = queue.dequeue();
			if (temp.dis > max_dis)
			{
				max_dis = temp.dis;
				max_val = temp.data;
			}
			else if (temp.dis == max_dis)
			{
				if (temp.data > max_val)
					max_val = temp.data;
			}
			for (int i = 0; i < 101; i++)
			{
				if (map[temp.data][i] == true && !visited[i])
				{
					data res;
					res.par = temp.data;
					res.data = i;
					res.dis = temp.dis + 1;
					queue.enqueue(res);
					visited[i] = true;
				}
			}
			for (int i = 0; i < 101; i++)
			{
				if (visited[i] == true)
					flag = 1;
			}
		}
		printf("#%d %d\n", test_c, max_val);
		test_c++;
	}
}