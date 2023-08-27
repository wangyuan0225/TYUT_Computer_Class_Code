#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<int, greater<int>> st;
    while (1) {
        int num;
        cin >> num;
        st.insert(num);
        if (cin.get() == '\n') {
            break;
        }
    }
    multiset<int, greater<int>>::iterator it;
    for	(it = st.begin(); it != st.end(); ++it) {
        cout << *it << " ";
    }
    return 0;
}