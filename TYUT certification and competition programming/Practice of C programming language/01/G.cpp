/**
 * @BelongsProject: 01
 * @Author: yuan wang
 * @CreateTime: 2023-07-16  21:48
 * @Description: TODO:重置了二月天数为28天
 * @Version: 3.0
 */

#include <iostream>

using namespace std;

int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/**
 * @description: 第几天？
 * @author: yuan wang
 * @date: 2023/07/16 21:48
 * @param: null
 * @return: null
 */
int main() {
    int year, month, day;
    while (scanf("%d/%d/%d", &year, &month, &day) != EOF) {
        int sum = 0;
        month_day[1] = 28;
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            month_day[1] = 29;
        }
        for (int k = 0; k < month - 1; ++k) {
            sum += month_day[k];
        }
        sum += day;
        cout << sum << endl;
    }
}
