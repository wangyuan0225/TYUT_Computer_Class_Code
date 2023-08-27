#include <bits/stdc++.h>
using namespace std;

#define MAX 1025

int main() {
    char str[MAX];
    cin.getline(str, MAX);
    int len = strlen(str);
    sort(str, str + len);
    for	(int i = 0; i < len; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            cout << str[i];
        }
        if (str[i] > 'z') {
            break;
        }
    }
    return 0;
}

