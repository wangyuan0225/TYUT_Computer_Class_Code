#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//A³ÔÌÇ¹û
int main()
{
	int T;
	scanf("%d", &T);
	int num[99];
	int count = 0;
	int k = 0;
	for (int i = 0; i < T; i++)
	{
		int n;
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
		{
			scanf("&d", &num[j]);
		}
		for (;; k++)
		{
			num[k]--;
			for (int l = 0; l < n; l++)
			{
				if (num[k] <= 0)
				{
					count++;
				}
			}
			if (k == n)
				k = 0;
			if (count == n - 1)
			{
				break;
			}
			
		}
		for (int l = 0; l < n; l++)
		{
			if (num[k] > 0)
			{
				if (num[k] > n - 1)
					printf("No\n");
				else
					printf("Yes\n");
			}
		}
	}
	return 0;
}