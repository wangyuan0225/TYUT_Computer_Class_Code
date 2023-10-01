#include <iostream>

using namespace std;
int result[9];

class Employee {
private:
    string name;
    string streetAddress;
    string city;
    string postalCode;
public:
    Employee(string n = "无名氏", string s = "徐家棚街道", string c = "武汉", string p = "420106") {
        name = n;
        streetAddress = s;
        city = c;
        postalCode = p;
    }
    void change_name(string n);
    void display();
};
class Date {
private:
    int year;
    int month;
    int day;
public:
    Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {
    }

    //内联成员函数
    inline void show() const;
};

void Date::show() const {
    cout << year << "-" << month << "-" << day << endl;
}

class People {
private:
    int number;
    string sex;
    Date birthday;
    string id;
public:
    //组合类
    People(int n = 0, string s = "", Date b = Date(), string i = "") : number(n), sex(s), birthday(b), id(i) {
    }

    //拷贝构造函数
    People(const People &p) : number(p.number), sex(p.sex), birthday(p.birthday), id(p.id) {
    }

    ~People() {
    }

    void setNumber(int n) {
        number = n;
    }

    void setSex(string s) {
        sex = s;
    }

    void setBirthday(Date d) {
        birthday = d;
    }

    void setId(string i) {
        id = i;
    }

    int getNumber() const {
        return number;
    }

    string getSex() const {
        return sex;
    }

    Date getBirthday() const {
        return birthday;
    }

    string getId() const {
        return id;
    }
};

void matrixTranspose(int *matrix);

int main() {
    //----------------内容1----------------
    int matrix[9];
    cout << "请输入3*3矩阵：" << endl;
    for (int i = 0; i < 9; ++i) {
        cin >> matrix[i];
    }
    matrixTranspose(matrix);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << result[i * 3 + j] << " ";
        }
        cout << endl;
    }

    //----------------内容2----------------
    Employee e;
    string name;
    cout << "请输入你想改的名字:";
    cin >> name;
    e.change_name(name);
    e.display();

    //----------------内容3----------------
    People p[2];
    int number, year, month, day;
    string sex, id;
    for (int i = 0; i < 2; ++i) {
        cout << "请输入第" << i + 1 << "个人的编号:";
        cin >> number;
        cout << "请输入第" << i + 1 << "个人的性别:";
        cin >> sex;
        cout << "请输入第" << i + 1 << "个人的出生日期，以空格分隔:";
        cin >> year >> month >> day;
        cout << "请输入第" << i + 1 << "个人的身份证号:";
        cin >> id;
        Date birthday(year, month, day);
        p[i].setNumber(number);
        p[i].setSex(sex);
        p[i].setBirthday(birthday);
        p[i].setId(id);
    }

    cout << "-----------------------------------" << endl;
    for (int i = 0; i < 2; ++i) {
        cout << "第" << i + 1 << "个人的编号：" << p[i].getNumber() << endl;
        cout << "第" << i + 1 << "个人的性别：" << p[i].getSex() << endl;
        cout << "第" << i + 1 << "个人的出生日期：";
        Date date = p[i].getBirthday();
        date.show();
        cout << "第" << i + 1 << "个人的身份证号：" << p[i].getId() << endl;
        cout << "-----------------------------------" << endl;
    }
    return 0;
}

void Employee::change_name(string n) {
    name = n;
}

void Employee::display() {
    cout << "姓名:" << name << endl;
    cout << "街道地址:" << streetAddress << endl;
    cout << "城市:" << city << endl;
    cout << "邮编:" << postalCode << endl;
}

void matrixTranspose(int *matrix) {
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i * 3 + j] = matrix[j * 3 + i];
            k++;
        }
    }
}