#include "queue.h"
#include "queue.cpp"

int main()
{
	int test_c = 1;
	int flag = 0;
	int data;

	while (test_c <= 10)
	{
		Queue<int> queue;

		scanf("%d", &test_c);
		for (int i = 0; i < 8; i++)
		{
			scanf("%d", &data);
			queue.enqueue(data);
		}
		while (!flag)
		{
			for (int i = 1; i <= 5; i++)
			{
				int deq = queue.dequeue() - i;
				if (deq <= 0)
				{
					deq = 0;
					flag = 1;
				}
				queue.enqueue(deq);
				if (flag)
					break;
			}
		}
		printf("#%d ", test_c);
		while (queue.size())
			printf("%d ", queue.dequeue());
		printf("\n");
		test_c++;
		flag = 0;
	}
	return (0);
}