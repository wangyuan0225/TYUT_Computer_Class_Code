/**
 * @BelongsProject: 03
 * @Author: yuan wang
 * @CreateTime: 2023-08-06  11:24
 * @Description: TODO
 * @Version: 1.0
 */

#include <iostream>
#include <set>

using namespace std;

/**
 * @description: 数列有序！
 * @author: yuan wang
 * @date: 2023/08/06 11:24
 * @param: null
 * @return: null
 */
int main() {
    int n;
    while (cin >> n) {
        multiset<int> st;
        int m;
        cin >> m;
        if (n == 0 && m == 0) {
            return 0;
        }
        while (n--) {
            int i;
            cin >> i;
            st.insert(i);
        }
        st.insert(m);
        multiset<int>::iterator iterator;
        for (iterator = st.begin(); iterator != st.end() ; ++iterator) {
            cout << *iterator << " ";
        }
        cout << endl;
    }
    return 0;
}
