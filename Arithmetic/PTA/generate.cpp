/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : PTA
  * @File           : generate.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2023-11-08  20:19
  * @Version        : 1.0
  ****************************************************************************************
  */


#include <iostream>
#include <random>
#include <string>

// 生成随机密码
std::string generateStrongPassword(int length) {
    std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_-+=<>?";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, charset.size() - 1);

    std::string password;
    for (int i = 0; i < length; i++) {
        password += charset[dist(gen)];
    }

    return password;
}

int main() {
    int passwordLength = 12; // 设置密码长度
    std::string strongPassword = generateStrongPassword(passwordLength);

    std::cout << "生成的强密码是: " << strongPassword << std::endl;

    return 0;
}
