#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, d;
	cin >> n >> d;

	//创建QKVW
	vector<vector<int>> q(n, vector<int>(d));
	vector<vector<int>> k(n, vector<int>(d));
	vector<vector<int>> v(n, vector<int>(d));
	vector<int> w(n);


	//输入QKVW
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

	//创建answer
	vector<vector<long long>> answer(n, vector<long long>(n, 0));

	//计算Q*K^T
	int j = 0, a = 0, b = 0;
	for	(int i = 0; i < n; ++i) {
		for	(int r = 0; r < n; r++) {
            long long tmp = 0;
			for	(int c = 0; c < d; c++) {
				tmp += q[i][j] * k[r][c];
				j++;
			}
            tmp *= w[i];

			j = 0;
			b++;
		}
		a++;
		b = 0;
	}

	//创建answer1
	vector<vector<long long>> answer1(n, vector<long long>(d, 0));

	//计算answer * V，得到最终结果
	j = 0, a = 0, b = 0;
	for	(int i = 0; i < n; ++i) {
		for	(int c = 0; c < d; c++) {
			for	(int r = 0; r < n; r++) {
				answer1[a][b] += answer[i][j] * v[r][c];
				j++;
			}
			j = 0;
			b++;
		}
		a++;
		b = 0;
	}

	//测试开始
	for	(int i = 0; i < n; i++) {
		for	(int j = 0; j < d; ++j) {
			cout << answer1[i][j] << " ";
		}
		cout << endl;
	}
	//测试结束
	return 0;
}