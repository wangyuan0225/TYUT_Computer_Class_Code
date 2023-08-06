/**
 * @BelongsProject: 03
 * @Author: yuan wang
 * @CreateTime: 2023-08-06  17:54
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#define N_MAX 50
#define M_MAX 5

using namespace std;

/**
 * @description: 求平均成绩
 * @author: yuan wang
 * @date: 2023/08/06 17:54
 * @param: null
 * @return: null
 */
int main() {
    int n, m;
    while (cin >> n) {
        cin >> m;
        double *avg = new double[m];
        double score[N_MAX][M_MAX] = {0};
        int num = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> score[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            double sum = 0;
            for (int j = 0; j < m; ++j) {
                sum += score[i][j];
            }
            printf("%.2f ", sum / m);
        }
        cout << endl;
        for (int i = 0; i < m; ++i) {
            double sum = 0;
            for (int j = 0; j < n; ++j) {
                sum += score[j][i];
            }
            avg[i] = sum / n;
            printf("%.2f ", avg[i]);
        }
        cout << endl;

        for (int i = 0; i < n; ++i) {
            bool chase = true;
            for (int j = 0; j < m; ++j) {
                if (score[i][j] < avg[j]) {
                    chase = false;
                    break;
                }
            }
            if (chase) {
                num++;
            }
        }
        cout << num << endl;
    }
    return 0;
}
