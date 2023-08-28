#include <bits/stdc++.h>
using namespace std;

struct Phone {
    int id;
    int price;//3
    int sold;//1
    int score;//2
};

struct Rule {
    bool operator()(const Phone &a, const Phone &b) const {
        if (a.sold == b.sold) {
            if (a.score == b.score) {
                return a.price < b.price;
            }
            return a.score > b.score;
        }
        return a.sold > b.sold;
    }
};

int main() {
    int m, k, n;
    cin >> m;
    while (m--) {
        cin >> k >> n;
        multiset<Phone, Rule> phones;
        while (n--) {
            Phone phone;
            cin >> phone.id >> phone.price >> phone.sold >> phone.score;
            if (phone.price <= k) {
                phones.insert(phone);
            }
        }
        multiset<Phone, Rule>::iterator i;
        for	(i = phones.begin(); i != phones.end(); ++i) {
            cout << (*i).id << endl;
        }
    }
    return 0;
}