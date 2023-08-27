#include <bits/stdc++.h>
using namespace std;

struct student {
    int id;
    string number;
    int grade;
};

struct Rule {
    bool operator()(const student &a, const student &b) {
        if (a.grade == b.grade) {
            return a.id < b.id;
        }
        return a.grade > b.grade;
    }
};

int main() {
    int n;
    cin >> n;
    multiset<student, Rule> students;

    for	(int i = 0; i < n; ++i) {
        student st;
        cin >> st.number >> st.grade;
        st.id = i;
        students.insert(st);
    }

    multiset<student, Rule>::iterator i;
    for	(i = students.begin(); i != students.end(); ++i) {
        cout << (*i).number << endl;
    }
    return 0;
}