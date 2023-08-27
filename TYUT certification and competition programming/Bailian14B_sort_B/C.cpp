#include <bits/stdc++.h>
using namespace std;

struct student {
    string number;
    int month;
    int day;
    int month_day;
    int count;
    int id;
};

struct Rule {
    bool operator()(const student &a, const student &b) const {
        if (a.month_day == b.month_day) {
            return a.id < b.id;
        }
        return a.month_day < b.month_day;
    }
};

int main() {
    int n;
    cin >> n;
    multiset<student, Rule> students;
    for	(int i = 0; i < n; ++i) {
        student st;
        cin >> st.number >> st.month >> st.day;
        st.month_day = st.month * 31 + st.day;
        st.count = 0;
        st.id = i;
        students.insert(st);
    }

    multiset<student, Rule>::iterator jt;
    multiset<student, Rule>::iterator it = students.end();
    ++it;

//	//测试
//	for	(jt = students.begin(); jt != students.end(); ++jt) {
//		cout << (*jt).number << " " << (*jt).month << " " << (*jt).day << endl;
//	}

    for	(jt = students.begin(); jt != it; ++jt) {
        int tmp = (*jt).month_day;
        if ((*(++jt)).month_day == tmp) {
            --jt;
            cout << (*jt).month << " " << (*jt).day << " ";
            while ((*jt).month_day == tmp) {
                cout << (*jt).number << " ";
                ++jt;
            }
            cout << endl;
        }
        --jt;

    }


    return 0;
}