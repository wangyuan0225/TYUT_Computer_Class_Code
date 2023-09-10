#include <iostream>

void generateCombinations(int n) {
    for (int i = 0; i < (1 << n); i++) {
        std::cout << "组合 " << i << ": ";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                std::cout << "选 ";
            } else {
                std::cout << "不选 ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "请输入物品数量n：";
    std::cin >> n;

    generateCombinations(n);

    return 0;
}
