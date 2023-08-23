#include <iostream>
using namespace std;

int main() {
    int n = 2;
    char (*arr)[8][8] = new char[n][8][8];
    cin >> arr[0][0];
    cin >> arr[1][0];
    cin >> arr[0][1];
    cout << arr[0][0];
    cout << arr[1][0];
}