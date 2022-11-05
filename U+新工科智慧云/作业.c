#include <stdio.h>


//ÅĞ¶ÏÊäÈë×Ö·û¸öÊı
//int main()
//{
//	char c;
//	int i;
//	for (i = 0; (c = getchar()) != '\n'; i++);
//	printf("%d",i);
//	return 0;
//}

int mian()
{
	int n = 0;
	printf("input a string:");
	while (getchar() != '\n')
	{
		n++;
	}
	printf("%d\n", n);
	return 0;
}