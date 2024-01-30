/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : PTA
  * @File           : count.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2023-11-08  19:37
  * @Version        : 1.0
  ****************************************************************************************
  */


#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main() {
    std::vector<int> numbers(10);
    for (int i = 1; i <= 10; i++) {
        numbers[i - 1] = i;
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(numbers.begin(), numbers.end(), g);

    for (const auto& num : numbers) {
        std::cout << num << std::endl;
    }

    return 0;
}
