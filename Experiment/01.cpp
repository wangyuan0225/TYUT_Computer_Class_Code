#include <iostream>

using namespace std;

enum CPU_Rank {
    P1 = 1, P2, P3, P4, P5, P6, P7
};

//-----------------内容1------------------
class CPU {
private:
    CPU_Rank rank;
    int frequency;
    double voltage;
public:
    CPU(CPU_Rank r = P1, int f = 0, double v = 0) {
        rank = r;
        frequency = f;
        voltage = v;
        cout << "构造了一个CPU!" << endl;
    }

    //析构函数
    ~CPU() {
        cout << "析构了一个CPU!" << endl;
    }

    void run() {
        cout << "CPU开始运行!" << endl;
    }

    void stop() {
        cout << "CPU停止运行!" << endl;
    }
};

//-----------------内容2------------------
class RAM {
};

class CDROM {
};

class Computer {
private:
    CPU cpu;
    RAM ram;
    CDROM cdrom;
public:
    Computer(CPU c = CPU(), RAM r = RAM(), CDROM cd = CDROM()) {
        cpu = c;
        ram = r;
        cdrom = cd;
        cout << "构造了一台电脑!" << endl;
    }

    ~Computer() {
        cout << "析构了一台电脑!" << endl;
    }

    void run() {
        cpu.run();
    }

    void stop() {
        cpu.stop();
    }
};

//-----------------内容3------------------
class Date {
private:
    int year;
    int month;
    int day;
public:
    Date() {
        year = 0;
        month = 0;
        day = 0;
    }

    Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
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
    People() {
        number = 0;
        sex = "";
        birthday = Date();
        id = "";
    }

    //组合类
    People(int n, string s, Date b, string i) : birthday(b) {
        number = n;
        sex = s;
        birthday = b;
        id = i;
    }

    //拷贝构造函数
    People(const People &p) {
        number = p.number;
        sex = p.sex;
        birthday = p.birthday;
        id = p.id;
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

int main() {
    //CPU
    CPU cpu(P6, 300, 2.8);
    cpu.run();
    cpu.stop();

    //Computer
    Computer computer(cpu, RAM(), CDROM());
    computer.run();
    computer.stop();

    //People
    int number, year, month, day;
    string sex, id;
    cout << "请输入编号:";
    cin >> number;
    cout << "请输入性别:";
    cin >> sex;
    cout << "请输入出生日期，以空格分隔:";
    cin >> year >> month >> day;
    cout << "请输入身份证号:";
    cin >> id;

    Date birthday(year, month, day);
    People people;
    people.setNumber(number);
    people.setSex(sex);
    people.setBirthday(birthday);
    people.setId(id);

    cout << "编号：" << people.getNumber() << endl;
    cout << "性别：" << people.getSex() << endl;
    Date date = people.getBirthday();
    date.show();
    cout << "身份证号：" << people.getId() << endl;

    //使用拷贝构造函数
    People people1(people);
    cout << "编号：" << people1.getNumber() << endl;
    cout << "性别：" << people1.getSex() << endl;
    Date date1 = people1.getBirthday();
    date1.show();
    cout << "身份证号：" << people1.getId() << endl;
    return 0;
}