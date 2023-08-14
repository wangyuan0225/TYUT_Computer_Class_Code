/**
 * @BelongsProject: 04
 * @Author: yuan wang
 * @CreateTime: 2023-08-14  15:04
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
using namespace std;

/**
 * @description: C 语言合法标识符
 * @author: yuan wang
 * @date: 2023/08/14 15:04
 * @param: null
 * @return: null
 */
int main() {
    int n, c;
    cin >> n;
    cin.get();
    while (n--) {
        c = cin.get();
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == '_')) {
            do {
                c = cin.get();
                if ((c >= '0' && c <='9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == '_')) {
                } else if (c == '\n') {
                    cout << "yes" << endl;
                    break;
                } else {
                    cout << "no" << endl;
                    char line[50];
                    cin.getline(line, sizeof(line));
                    break;
                }

            } while (1);
        } else {
            cout << "no" << endl;
            char line[50];
            cin.getline(line, sizeof(line));
        }
    }
    return 0;
}
