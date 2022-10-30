#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//A复习时间
//int main()
//{
//	int group, i, j, k;
//	int m, n;
//	int temp;
//	int statistic[99] = { 0 };
//	int result[99] = { 0 };
//	scanf("%d", &group);
//	for (i = 0; i < group; i++)
//	{
//		scanf("%d%d", &n, &m);
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d", &statistic[j]);
//		}
//		for (j = m - 2; j >= 0; j--)
//		{
//			for (k = 0; k <= j; k++)
//			{
//				if (statistic[j] > statistic[j + 1])
//				{
//					temp = statistic[j + 1];
//					statistic[j + 1] = statistic[j];
//					statistic[j] = temp;
//				}
//			}
//		}
//		result[i] = statistic[0];
//	}
//	printf("\n");
//	for (i = 0; i < group; i++)
//	{
//		printf("%d\n", (100 - result[i]) * (100 - result[i]));
//	}
//	return 0;
//}



//B分数矩阵
//int main()
//{
//	int arr[99];
//	int* p = arr;
//	int len = 0;
//	for (;; p++)
//	{
//		scanf("%d", p);
//		if (*p == 0)
//		{
//			break;
//		}
//		len++;
//	}
//	//scanf("%d", arr);
//	float all[99];
//	for (int q = 0; q < len; q++)
//	{
//		
//		int j = arr[q] - 1;
//		all[q] = 0;
//		for (int i = 2; i <= arr[q]; i++, j--)
//		{
//			all[q] += 1.00 / i * 2 * j;
//		}
//		all[q] += arr[q];
//	}
//	for (int q = 0; q < len; q++)
//	{
//		printf("%.2f\n", all[q]);
//	}
//	return 0;
//}



//C猜数字（看不懂题目，跳）




//D两军交锋
//int main()
//{
//	int T;
//	scanf("%d", &T);
//	float w[4];
//	float* p = w;
//	float result[99];
//	for (int i = 0; i < T; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			scanf("%f", &w[j]);
//		}
//		//for (int j = 0; j < 4; j++)
//		//{
//		//	printf("%.3f \n", w[j]);
//		//}
//		result[i] = w[3] / (w[0] + w[1]) * w[2];
//	}
//	for (int i = 0; i < T; i++)
//	{
//		printf("%.3f ", result[i]);
//	}
//	return 0;
//}




//E做一个正气的杭电人
//int main()
//{
//	int T;
//	scanf("%d", &T);
//	int num [9] ;
//	for (int i = 0; i < T; i++)
//	{
//		scanf("%d", &num[i]);
//
//	}
//	for (int i = 0; i < num[i]; i++)
//	{
//		for (int j = 0; j < 3*num[i]; j++)
//		{
//			for (int p = 0; p < num[i]; p++)
//			{
//				printf("HDU");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}



//F竹青遍野
//#include <math.h>
//int main()
//{
//	int t, p = 0;
//	int num[99];
//	int result[99];
//	scanf("%d", &t);
//	for (int i = 0; i < t; i++)
//	{
//		scanf("%d", &num[i]);
//		for (int a = 0;; a++)
//		{
//			int all = 0;
//			all += pow(a, 3);
//			if (num[i] >= all && num[i] <= all + pow(a + 1, 3))
//			{
//				result[i] = a;
//				break;
//			}
//		}
//	}
//	for (int i = 0; i < t; i++)
//	{
//		printf("%d\n", result[i] + 1);
//	}
//	return 0;
//}




//G菜鸟先飞
//int main()
//{
//	int T;
//	scanf("%d", &T);
//	int time[99];
//	int result[99];
//	for (int i = 0; i < T; i++)
//	{
//		scanf("%d", &time[i]);
//		result[i] = time[i];
//		for (int j = 0; j < time[i]; j++)
//		{
//			result[i] += 2 * j;
//		}
//	}
//	for (int i = 0; i < T; i++)
//	{
//		printf("%d\n", result[i]);
//	}
//	return 0;
//}




//H奇偶位互换
//int  main()
//{
//	int C;
//	scanf("%d", &C);
//	char arr[99][99];
//	for (int i = 0; i < C; i++)
//	{
//		scanf("%s", arr[i]);
//		for (int j = 0; j < strlen(arr[i]); j += 2)
//		{
//			char tmp;
//			tmp = arr[i][j + 1];
//			arr[i][j + 1] = arr[i][j];
//			arr[i][j] = tmp;
//		}
//	}
//	for (int i = 0; i < C; i++)
//	{
//		printf("%s\n", arr[i]);
//	}
//	return 0;
//}

