#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    //����QKVW
    vector<vector<int>> q(n, vector<int>(d));
    vector<vector<int>> k(n, vector<int>(d));
    vector<vector<int>> v(n, vector<int>(d));
    vector<int> w(n);


    //����QKVW
    for	(int i = 0; i < n; ++i) {
        for	(int j = 0; j < d; ++j) {
            cin >> q[i][j];
        }
    }
    for	(int i = 0; i < n; ++i) {
        for	(int j = 0; j < d; ++j) {
            cin >> k[i][j];
        }
    }
    for	(int i = 0; i < n; ++i) {
        for	(int j = 0; j < d; ++j) {
            cin >> v[i][j];
        }
    }
    for	(int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    //����answer
    vector<vector<long long>> answer(n, vector<long long>(d, 0));

    //����
    for	(int i = 0; i < n; ++i) {
        for	(int r = 0; r < n; r++) {
            long long tmp = 0;
            for	(int c = 0; c < d; c++) {
                tmp += q[i][c] * k[r][c];
            }
            tmp *= w[i];
            for	(int c = 0; c < d; c++) {
                answer[i][c] += tmp * v[r][c];
            }
        }
    }

    //���Կ�ʼ
    for	(int i = 0; i < n; i++) {
        for	(int j = 0; j < d; ++j) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    //���Խ���
    return 0;
}