/**
*@BelongsProject: GeneralExercise-Demo02
*@Author: yuan wang
*@CreateTime: 2023-02-01  19:49
*@Description: TODO
*@Version: 1.0
*/


//#include <stdio.h>
//
//// 计算阶乘
//long long factorial(int n) {
//    long long fact = 1;
//    for(int i = 1; i <= n; i++) {
//        fact *= i;
//    }
//    return fact;
//}
//
//// 计算5的p次方
//long long powerOf5(int p) {
//    long long power = 1;
//    for(int i = 1; i <= p; i++) {
//        power *= 5;
//    }
//    return power;
//}
//
//int main() {
//    // 设置m和n的最大值
//    int max_m_n = 1000000;
//    // 设置p的最大值
//    int max_p = 1000000;
//
//    for(int m = 1; m <= max_m_n; m++) {
//        for(int n = 1; n <= max_m_n; n++) {
//            for(int p = 1; p <= max_p; p++) {
//                if(factorial(m) + factorial(n) == powerOf5(p)) {
//                    printf("Found solution: m = %d, n = %d, p = %d\n", m, n, p);
//                    return 0;
//                }
//            }
//        }
//    }
//
//    printf("No solution found within the given range.\n");
//    return 0;
//}





//#include <stdio.h>
//#include "string.h"
//
//
//int main() {
//    char a[4] = "0123";
//    printf("%s", a);
//}

//int main() {
//    int a = 10, *p = NULL;
//    p = &a;
//    printf("%x\n", p);
//    printf("%lu\n", p);
//    printf("%u\n", p);
//    printf("%lx\n", p);
//    return 0;
//}


//int main() {
//    printf("1\n");
//    int old[7] = {0};
//    int new[7] = {0};
//    for (int i = 1; i < 6; ++i) {
//        for (int j = 0; j < i; ++j) {
//            new[j] = old[j - 1] + old [j];
//        }
//        for (int j = 0; new[j] != 0; ++j) {
//            printf("%d", new[j]);
//        }
//    }
//}


//int main() {
//    for (int i = 1; i < 10; ++i) {
//        for (int j = 1; j <= i; ++j) {
//            printf("%d * %d = %d ", j, i, j * i);
//        }
//        printf("\n");
//    }
//    return 0;
//}


//int main() {
//    char arr[10];
//    scanf("%s", arr);
//    for (int i = 0; i < strlen(arr); ++i) {
//        if ('a' <= arr[i] && arr[i] <= 'z') {
//            arr[i] -= 32;
//        }
//    }
//    printf("%s", arr);
//    return 0;
//}


//int main(){
//    float a;
//    double b;
//    a = 123456.789e4;
//    b = 123456.789e4;
//    printf("a=%f\nb=%lf\n", a, b);
//    return 0;
//}

//int main() {
//    double a = 5.5;
//    double b = 2.5;
//    printf("%f\n", (int) a + b / b);
//    float c = 314159.265;
//    printf("%ff", c);
//    return 0;
//}

//struct s{
//    int x;
//    int y;
//}
//struct s x,y;


/*
 * @description: 练习册P89 T7
 * @author: yuan wang
 * @date: 2023/2/12 10:00
 * @param: null
 * @return: null
 */
//int main() {
//    FILE *fp;
//    int i, k = 0, n = 0;
//    fp = fopen("d1.dat", "w");
//    for (i = 1; i < 4; i++)
//        fprintf(fp, "%d", i);
//    fclose(fp);
//    fp = fopen("d1.dat", "r");
//    fscanf(fp, "%d%d", &k, &n);
//    printf("%d, %d\n", k, n);
//    fclose(fp);
//    return 0;
//}



//判断输入字符个数
//int main()
//{
//	char c;
//	int i;
//	for (i = 0; (c = getchar()) != '\n'; i++);
//	printf("%d",i);
//	return 0;
//}

/*
 * @description:
 * @author: yuan wang
 * @date: 2023/02/01 19:49
 * @param: null
 * @return: null
 */
//int main()
//{
//    int n = 0;
//    printf("input a string:");
//    while (getchar() != '\n'){
//        n++;
//    }
//    printf("%d\n", n);
//    return 0;
//}



