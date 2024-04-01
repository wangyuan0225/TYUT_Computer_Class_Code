/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 04
  * @File           : power.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : ʹ���ݷ���AģΪ��������ֵ������Ӧ����������
  * @Attention      : None
  * @Date           : 2024/3/21 10:46
  * @Version        : 1.0
  *                   2.0 ��ӱ�Ҫע�ͣ��Ż�����ܹ������ó�����ʾ��
  ****************************************************************************************
  */

#include <iostream>
#include <algorithm>

using namespace std;

const int n = 3;

int main() {
    double a[n + 1][n + 1] = {
            0, 0, 0, 0,
            0, 2, 3, 5,
            0, 10, 3, 4,
            0, 3, 6, 1
    };

    double x[n + 1] = {0, 1, 1, 1};
    double y[n + 1], m;
    while(true) {
        double sum = 0;
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                sum += a[i][j] * x[j];
            }
            y[i] = sum;
            sum = 0;
        }
        m = *max_element(y + 1, y + n);

        double tmp[n + 1];
        for (int i = 1; i < n + 1; ++i) {
            tmp[i] = x[i];
        }

        for (int i = 1; i < n + 1; ++i) {
            x[i] = y[i] / m;
        }

        // ����������������
        for (int i = 1; i < n + 1; ++i) {
            tmp[i] -= x[i];
            tmp[i] = abs(tmp[i]);
        }
        if (*max_element(tmp + 1, tmp + n + 1) < 0.0000005) {
            break;
        }
    }

    cout << "��������ֵ��" << m << endl << "��Ӧ������������(";
    for (int i = 1; i < n; ++i) {
        cout << x[i]  << ", ";
    }
    cout << x[n] << ")" << endl;
    return 0;
}
