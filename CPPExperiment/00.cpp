#include <iostream>
#include <cmath>

using namespace std;


int MAX1(int a, int b);

int MAX1(int a, int b, int c);

double MAX1(double a, double b);

double MAX1(double a, double b, double c);

int main() {
    //---------------内容1---------------
    int n = 1, sum = 0;
    //do-while循环
    do {
        sum += n;
        n++;
    } while (n <= 10);
    cout << sum << endl;
    //for 语句改写
    sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += i;
    }
    cout << sum << endl;

    //---------------内容3---------------
    string str;
    cout << "请输入图形名称:";
    cin >> str;
    if (str == "圆形") {// 原！
        double r;
        cout << "请输入圆的半径:";
        cin >> r;
        cout << "圆的面积为:" << 3.14 * r * r << endl;
    } else if (str == "长方形") {
        double a, b;
        cout << "请输入长方形的长和宽:";
        cin >> a >> b;
        cout << "长方形的面积为:" << a * b << endl;
    } else if (str == "正方形") {
        double a;
        cout << "请输入正方形的边长:";
        cin >> a;
        cout << "正方形的面积为:" << a * a << endl;
    } else {
        cout << "输入错误!" << endl;
    }

    return 0;
}

//---------------内容2---------------
int MAX1(int a, int b) {
    return a > b ? a : b;
}

int MAX1(int a, int b, int c) {
    return MAX1(MAX1(a, b), c);
}

double MAX1(double a, double b) {
    return a > b ? a : b;
}

double MAX1(double a, double b, double c) {
    return MAX1(MAX1(a, b), c);
}