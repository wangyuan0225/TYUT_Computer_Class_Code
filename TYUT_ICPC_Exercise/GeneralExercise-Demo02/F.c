/**
*@BelongsProject: GeneralExercise-Demo02
*@Author: yuan wang
*@CreateTime: 2023-02-04  08:34
*@Description: TODO
*@Version: 1.0
*/

#include <stdio.h>
#include <math.h>

/*
 * @description: �޽�����
 * С��ʾ������֮�����+����������֮�ʹ��ڵ�����
 * �ܽ᣺�����Ҳ��Ҫ�ܶ����ѧ���ף�����������ģ������ǻ��
 * @author: yuan wang
 * @date: 2023/02/04 08:34
 * @param: null
 * @return: null
 */
int main() {
    int t;
    int a, b, c, d;

    float result[1024];

    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        result[i] = sqrt((a - c) * (a - c) + (b - d)*(b - d));
    }
    for (int i = 0; i < t; ++i) {
        printf("%.1lf\n", result[i]);
    }
    return 0;
}
