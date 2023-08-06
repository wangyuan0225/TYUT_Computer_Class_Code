/**
 * @BelongsProject: 01
 * @Author: yuan wang
 * @CreateTime: 2023-07-16  21:38
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#include <cstring>

using namespace std;

/**
 * @description: 成绩转换
 * @author: yuan wang
 * @date: 2023/07/16 21:38
 * @param: null
 * @return: null
 */
int main() {
    int *score = new int[99];
    int i = 0;
    char *input = new char[9];
    for (; i < 99; ++i) {
        cin.getline(input, 9);
        if (strcmp(input, "\0") == 0) {
            break;
        }
        sscanf(input, "%d", &score[i]);
    }
    for (int j = 0; j < i; ++j) {
        if (score[j] >= 90 && score[j] <= 100) {
            cout << "A" << endl;
        } else if (score[j] >= 80 && score[j] <= 89) {
            cout << "B" << endl;
        } else if (score[j] >= 70 && score[j] <= 79) {
            cout << "C" << endl;
        } else if (score[j] >= 60 && score[j] <= 69) {
            cout << "D" << endl;
        } else if (score[j] >= 0 && score[j] <= 59) {
            cout << "E" << endl;
        } else {
            cout << "Score is error!" << endl;
        }
    }
    return 0;
}
