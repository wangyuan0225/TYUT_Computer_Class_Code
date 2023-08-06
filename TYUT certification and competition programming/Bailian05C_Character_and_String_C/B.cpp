/**
 * @BelongsProject: .
 * @Author: yuan wang
 * @CreateTime: 2023-07-25  17:29
 * @Description: TODO:修改了一些bug
 * @Version: 5.0
 */

#include <iostream>

using namespace std;

string upper(string &arr);

/**
 * @description: 字符串判等
 * @author: yuan wang
 * @date: 2023/07/25 17:29
 * @param: null
 * @return: null
 */
int main() {
    string arr1, arr2;
    getline(cin, arr1);
    getline(cin, arr2);
    bool equal = true;

    int space1 = 0, space2 = 0;

    upper(arr1);
    upper(arr2);

    int i = 0, j = 0;

    while (i < arr1.size()) {
        while (j < arr2.size()) {
            if (arr2[j] == ' ') {
                j++;
                space2++;
            }
            if (i < arr1.size()) {
                if (arr1[i] == ' ') {
                    i++;
                    space1++;
                }
                if (arr1[i] != ' ' && arr2[j] != ' ') {
                    if (arr1[i] != arr2[j]) {
                        equal = false;
                        break;
                    }
                    i++;
                    j++;
                }
            } else {
                j++;
            }
        }

        if (i < arr1.size()) {
            if (arr1[i] != ' ') {
                equal = false;
            } else {
                space1++;
            }
            i++;
        }

        if (!equal) {
            break;
        }
    }

    if (arr2[arr2.size() - 1] == ' ' && arr2[arr2.size() - 2] == ' ') {
        space2++;
    }
    if ((arr1.size() - space1) != (arr2.size() - space2)) {
        equal = false;
    }

    if (equal) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

string upper(string &arr) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] >= 'a' && arr[i] <= 'z') {
            arr[i] -= 32;
        }
    }
    return arr;
}