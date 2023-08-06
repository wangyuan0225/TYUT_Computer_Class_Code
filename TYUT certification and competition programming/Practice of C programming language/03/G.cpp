/**
 * @BelongsProject: 03
 * @Author: yuan wang
 * @CreateTime: 2023-08-06  12:50
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>

using namespace std;

int count(int salary);

/**
 * @description: 发工资咯：)
 * @author: yuan wang
 * @date: 2023/08/06 12:50
 * @param: null
 * @return: null
 */
int main() {
    int n;
    while (cin >> n && n != 0) {
        int sum = 0;
        while (n--) {
            int salary;
            cin >> salary;
            sum += count(salary);
        }
        cout << sum << endl;
    }
    return 0;
}

int count(int salary) {
    int currency = 0;
    currency += salary / 100;
    salary %= 100;
    currency += salary / 50;
    salary %= 50;
    currency += salary / 10;
    salary %= 10;
    currency += salary / 5;
    salary %= 5;
    currency += salary / 2;
    salary %= 2;
    currency += salary;
    return currency;
}