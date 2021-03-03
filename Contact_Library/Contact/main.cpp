#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int len;
int max_v = -1;
int start_p;
bool map[101][101];
bool visited[101];
int solve[100] = { 0, };

void fill_map(int cnt)
{
	if (cnt > max_v)
		max_v = cnt;
	while (q.size())
	{
		for (int i = 1; i < 101; i++)
		{
			if (map[q.front()][i] == true && visited[i] == false)
			{
				solve[i] = cnt;
				visited[i] = true;
			}
		}
		q.pop();
	}
	for (int i = 1; i < 101; i++)
	{
		if (solve[i] == cnt)
			q.push(i);
	}
	fill_map(cnt + 1);
}

int main()
{
	for (int N = 1; N <= 10; N++)
	{
		int from, to;

		max_v = -1;
		cin >> len >> start_p;
		for (int i = 1; i < 101; i++)
		{
			for (int j = 1; j < 101; j++)
				map[i][j] = false;
			visited[i] = false;
			solve[i] = 987654321;
		}
		for (int i = 0; i < (len / 2); i++)
		{
			cin >> from >> to;
			map[from][to] = true;
		}
		q.push(start_p);
		fill_map(start_p);
		for (int i = 100; i >= 1; i--)
		{
			if (solve[i] == max_v)
			{
				cout << "#" << N << " " << i << endl;
				break;
			}
		}
	}
}