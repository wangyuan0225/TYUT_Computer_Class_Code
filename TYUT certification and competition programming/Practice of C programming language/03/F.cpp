/**
 * @BelongsProject: 03
 * @Author: yuan wang
 * @CreateTime: 2023-08-06  12:20
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

struct Rule {
    bool operator()(const int a1, const int a2) const {
        return abs(a1) > abs(a2);
    }
};

/**
 * @description:
 * @author: yuan wang
 * @date: 2023/08/06 12:20
 * @param: null
 * @return: null
 */
int main() {
    int n;
    while (cin >> n && n != 0) {
        multiset<int, Rule> st;
        int num;
        while (n--) {
            cin >> num;
            st.insert(num);
        }
        multiset<int, Rule>::iterator it;
        for (it = st.begin(); it != st.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}
