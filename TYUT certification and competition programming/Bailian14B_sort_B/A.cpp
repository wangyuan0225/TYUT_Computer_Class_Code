#include <bits/stdc++.h>
using namespace std;

struct inc {
    bool operator()(const string &a, const string &b) const {
        return a < b;
    }
};

struct Dec {
    bool operator()(const string &a, const string &b) const {
        return a > b;
    }
};

struct ncinc {
    bool operator()(const string &a, const string &b) const {
        string a1 = (string) a;
        string b1 = (string) b;
        for	(int i = 0; i < a.size(); ++i) {
            if (a1[i] >= 'a' && a1[i] <= 'z') {
                a1[i] -= 'a' - 'A';
            }
        }
        for	(int i = 0; i < b.size(); ++i) {
            if (b1[i] >= 'a' && b1[i] <= 'z') {
                b1[i] -= 'a' - 'A';
            }
        }

        return a1 < b1;
    }
};

struct ncdec {
    bool operator()(const string &a, const string &b) const {
        string a1 = (string) a;
        string b1 = (string) b;
        for	(int i = 0; i < a.size(); ++i) {
            if (a1[i] >= 'a' && a1[i] <= 'z') {
                a1[i] -= 'a' - 'A';
            }
        }
        for	(int i = 0; i < b.size(); ++i) {
            if (b1[i] >= 'a' && b1[i] <= 'z') {
                b1[i] -= 'a' - 'A';
            }
        }

        return a1 > b1;
    }
};

int main() {
    string problem;
    cin >> problem;
    cin.get();

    int n;
    cin >> n;
    cin.get();

    if	(problem[0] == 'i') {
        multiset<string, inc> st;
        for	(int i = 0; i < n; ++i) {
            string tmp;
            getline(cin, tmp);
            st.insert(tmp);
        }
        multiset<string, inc>::iterator i;
        for	(i = st.begin(); i != st.end(); ++i) {
            cout << *i << endl;
        }
    }

    if	(problem[0] == 'd') {
        multiset<string, Dec> st;
        for	(int i = 0; i < n; ++i) {
            string tmp;
            getline(cin, tmp);
            st.insert(tmp);
        }
        multiset<string, Dec>::iterator i;
        for	(i = st.begin(); i != st.end(); ++i) {
            cout << *i << endl;
        }
    }

    if	(problem[0] == 'n') {
        if (problem[2] == 'i') {
            multiset<string, ncinc> st;
            for	(int i = 0; i < n; ++i) {
                string tmp;
                getline(cin, tmp);
                st.insert(tmp);
            }
            multiset<string, ncinc>::iterator i;
            for	(i = st.begin(); i != st.end(); ++i) {
                cout << *i << endl;
            }
        }
        if (problem[2] == 'd') {
            multiset<string, ncdec> st;
            for	(int i = 0; i < n; ++i) {
                string tmp;
                getline(cin, tmp);
                st.insert(tmp);
            }
            multiset<string, ncdec>::iterator i;
            for	(i = st.begin(); i != st.end(); ++i) {
                cout << *i << endl;
            }
        }
    }
    return 0;
}

