/**
 * @BelongsProject: Bailian05C_Character_and_String_C
 * @Author: yuan wang
 * @CreateTime: 2023-07-29  09:12
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#include <cstring>

using namespace std;

int xLength(const char y[][101], int n);
bool isSubstring(const char* mainStr, const char* subStr);
void reverseStr(const char* src, char* dest);

/**
 * @description: 子串
 * @author: yuan wang
 * @date: 2023/07/29 09:12
 * @param: null
 * @return: null
 */
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        char y[n][101];
        for (int i = 0; i < n; ++i) {
            cin >> y[i];
        }
        cout << xLength(y, n) << endl;
    }

    return 0;
}

int xLength(const char y[][101], int n) {
    // Step 1: Find the shortest string
    int minLen = 101;
    int minIdx = 0;
    for (int i = 0; i < n; i++) {
        int len = strlen(y[i]);
        if (len < minLen) {
            minLen = len;
            minIdx = i;
        }
    }

    // Temporary buffers
    char sub[101], revSub[101];

    // Step 2 and 3: Generate all possible substrings and check them
    for (int len = minLen; len > 0; len--) {
        for (int i = 0; i <= minLen - len; i++) {
            strncpy(sub, &y[minIdx][i], len);
            sub[len] = '\0';
            reverseStr(sub, revSub);

            bool valid = true;
            for (int j = 0; j < n; j++) {
                if (!isSubstring(y[j], sub) && !isSubstring(y[j], revSub)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                return len;
            }
        }
    }

    // Step 4: Return 0 if no such substring is found
    return 0;
}

bool isSubstring(const char* mainStr, const char* subStr) {
    int mainLen = strlen(mainStr);
    int subLen = strlen(subStr);
    for (int i = 0; i <= mainLen - subLen; i++) {
        bool match = true;
        for (int j = 0; j < subLen; j++) {
            if (mainStr[i + j] != subStr[j]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
}

void reverseStr(const char* src, char* dest) {
    int len = strlen(src);
    for (int i = 0; i < len; i++) {
        dest[i] = src[len - 1 - i];
    }
    dest[len] = '\0';
}
