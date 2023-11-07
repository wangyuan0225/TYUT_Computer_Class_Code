/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : PTA
  * @File           : test.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2023-11-06  21:07
  * @Version        : 1.0
  ****************************************************************************************
  */
#include <iostream>

const unsigned long long MOD = 998244353;

class Matrix {
public:
    unsigned long long a, b, c, d;

    Matrix() : a(1), b(1), c(1), d(0) {}

    Matrix(unsigned long long a, unsigned long long b, unsigned long long c, unsigned long long d)
            : a(a), b(b), c(c), d(d) {}

    Matrix operator*(const Matrix& other) const {
        unsigned long long new_a = (a * other.a + b * other.c) % MOD;
        unsigned long long new_b = (a * other.b + b * other.d) % MOD;
        unsigned long long new_c = (c * other.a + d * other.c) % MOD;
        unsigned long long new_d = (c * other.b + d * other.d) % MOD;

        return Matrix(new_a, new_b, new_c, new_d);
    }
};

Matrix matrix_pow(Matrix M, unsigned long long n) {
    Matrix result;
    while (n > 0) {
        if (n % 2 == 1) {
            result = result * M;
        }
        M = M * M;
        n /= 2;
    }
    return result;
}

unsigned long long fibonacci(unsigned long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    Matrix base_matrix;
    Matrix result_matrix = matrix_pow(base_matrix, n - 1);

    return result_matrix.a;
}

int main() {
    unsigned long long n;
    std::cout << "请输入要求解的斐波那契数列的项数n：";
    std::cin >> n;

    unsigned long long result = fibonacci(n) % MOD;
    std::cout << "第 " << n << " 项的斐波那契数是：" << result << std::endl;

    return 0;
}
