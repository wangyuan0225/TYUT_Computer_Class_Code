#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int group, i, j, k;
	int m, n;
	int temp;
	int statistic[99] = { 0 };
	int result[99] = { 0 };
	scanf("%d", &group);
	for (i = 0; i < group; i++)
	{
		scanf("%d%d", &n, &m);
		for (j = 0; j < n; j++)
		{
			scanf("%d", &statistic[j]);
		}
		for (j = m - 2; j >= 0; j--)
		{
			for (k = 0; k <= j; k++)
			{
				if (statistic[j] > statistic[j + 1])
				{
					temp = statistic[j + 1];
					statistic[j + 1] = statistic[j];
					statistic[j] = temp;
				}
			}
		}
		result[i] = statistic[0];
	}
	printf("\n");
	for (i = 0; i < group; i++)
	{
		printf("%d\n", (100-result[i])*(100 - result[i]));
	}
	return 0;
}