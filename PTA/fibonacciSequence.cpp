/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : PTA
  * @File           : fibonacciSequence.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 已知斐波那契数列 Fn 求解该数列的第n项，结果对998244353取模。
  * @Attention      : 矩阵快速幂，unsigned long long的最大值：1844674407370955161（1.8e18）
  * @Date           : 2023-11-05  14:52
  * @Version        : 2.0 针对取模进行了优化，新增矩阵乘法中的取模
  ****************************************************************************************
  */

#include <iostream>

using namespace std;

unsigned long long matrix[4] = {1, 1, 1, 0};

/**
 * 进行矩阵乘法
 * @param matrix1 矩阵1
 * @param matrix2 矩阵2
 * @return result 两个矩阵相乘后的矩阵
 */
unsigned long long* multiply_matrix(unsigned long long matrix1[4], unsigned long long matrix2[4]) {
    unsigned long long* result = new unsigned long long[4];
    result[0] = (matrix1[0] * matrix2[0] + matrix1[1] * matrix2[2]) % 998244353;
    result[1] = (matrix1[0] * matrix2[1] + matrix1[1] * matrix2[3]) % 998244353;
    result[2] = (matrix1[2] * matrix2[0] + matrix1[3] * matrix2[2]) % 998244353;
    result[3] = (matrix1[2] * matrix2[1] + matrix1[3] * matrix2[3]) % 998244353;
    return result;
}

/**
 * 进行矩阵幂乘，模仿数的幂乘进行二分归并
 * @param matrix1 待乘矩阵
 * @param n 指数
 * @return 分奇偶情况返回两部分的乘积
 */
unsigned long long* matrix_pow(unsigned long long matrix1[4], unsigned long long n) {
    if (n == 1) {
        return matrix;
    }
    unsigned long long* halfMatrix = matrix_pow(matrix1, n / 2);
    if (n % 2 == 0) {
        return multiply_matrix(halfMatrix, halfMatrix);
    }
    return multiply_matrix(multiply_matrix(halfMatrix, halfMatrix), matrix);
}

int main() {
    unsigned long long n;
    cin >> n;
    unsigned long long* result = matrix_pow(matrix, n);
    cout << result[1] % 998244353 << endl;
    return 0;
}
