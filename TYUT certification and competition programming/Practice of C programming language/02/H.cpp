/**
 * @BelongsProject: 02
 * @Author: yuan wang
 * @CreateTime: 2023-07-18  08:53
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>

using namespace std;

/**
 * @description: 青年歌手大奖赛_评委会打分
 * @author: yuan wang
 * @date: 2023/07/18 08:53
 * @param: null
 * @return: null
 */
int main() {
    int n = 0;
    while (cin >> n) {
        float *score = new float[n];
        for (int i = 0; i < n; ++i) {
            cin >> score[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (score[j] > score[j + 1]) {
                    float tmp = score[j];
                    score[j] = score[j + 1];
                    score[j + 1] = tmp;
                }
            }
        }
        float average = 0;
        for (int i = 1; i < n - 1; ++i) {
            average += score[i];
        }
        printf("%.2f\n", average / (n - 2));
    }
    return 0;
}
