/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : PTA
  * @File           : test1.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2023-11-07  00:20
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

unsigned long long matrix[4] = {1, 1, 1, 0};

unsigned long long *multiply_matrix(unsigned long long matrix1[4], unsigned long long matrix2[4]) {
    unsigned long long *result = new unsigned long long[4];
    result[0] = (matrix1[0] * matrix2[0] + matrix1[1] * matrix2[2]) % 998244353;
    result[1] = (matrix1[0] * matrix2[1] + matrix1[1] * matrix2[3]) % 998244353;
    result[2] = (matrix1[2] * matrix2[0] + matrix1[3] * matrix2[2]) % 998244353;
    result[3] = (matrix1[2] * matrix2[1] + matrix1[3] * matrix2[3]) % 998244353;
    return result;
}

unsigned long long* matrix_pow(unsigned long long matrix1[4], unsigned long long n) {
    if (n == 1) {
        return matrix1;
    } else if (n % 2 == 0) {
        unsigned long long* halfMatrix = matrix_pow(matrix1, n / 2);
        return multiply_matrix(halfMatrix, halfMatrix);
    } else {
        unsigned long long* halfMatrix = matrix_pow(matrix1, n / 2);
        return multiply_matrix(multiply_matrix(halfMatrix, halfMatrix), matrix);
    }
}

int main() {
    unsigned long long n;
    cin >> n;

    unsigned long long* result = matrix_pow(matrix, n);
    cout << result[2] % 998244353 << endl;  // 输出矩阵中斐波那契数列的第n项，确保取模
    return 0;
}
