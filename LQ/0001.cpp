/**
****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : LQ
  * @File           : 0001.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : 方程整数解
  * @Attention      : 枚举思想
  * @Date           : 2024-01-21  21:41
  * @Version        : 1.0
  ****************************************************************************************
  */
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int max = sqrt(1000);
	for (int i = 1; i < max; ++i) {
		for (int j = 1; j < max; ++j) {
			for (int k = 1; k < max; ++k) {
				if (i * i + j * j + k * k == 1000 && i != 6) {
					cout << i << " " << j << " " << k << endl;
					break;
				}
			}
		}
	}
	return 0;
}
