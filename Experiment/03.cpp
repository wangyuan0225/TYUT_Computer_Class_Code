#include <iostream>
#include <cstring>

using namespace std;

class Animal {
public:
    int age;
};

class Dog : Animal {
public:
    void setAge(int n) {
        age = n;
    }

    void show() {
        cout << "狗的年龄：" << age << endl;
    }
};

class Vehicle {
protected:
    int maxSpeed;
    int weight;
public:
    Vehicle(int m = 100, int w = 50) : maxSpeed(m), weight(w) {}

    void run() {};

    void stop() {};
};

class Bicycle : virtual public Vehicle {
protected:
    int height;
public:
    Bicycle(int m = 100, int w = 50, int h = 20) : Vehicle(m, w), height(h) {}
};

class Motorcar : virtual public Vehicle {
protected:
    int seatNum;
public:
    Motorcar(int m = 100, int w = 50, int n = 4) : Vehicle(m, w), seatNum(n) {}
};

class Motorcycle : public Bicycle, public Motorcar {
public:
    Motorcycle(int m = 100, int w = 50, int h = 20, int n = 4) : Bicycle(m, w, h), Motorcar(m, w, n) {}

    void print() {
        cout << "最大速度：" << maxSpeed << endl;
        cout << "重量：" << weight << endl;
        cout << "高度：" << height << endl;
        cout << "座位数：" << seatNum << endl;
    }
};

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}

    //内联成员函数
    inline void show() const;
};

void Date::show() const {
    cout << year << "-" << month << "-" << day << endl;
}

class People {
protected:
    char name[11];
    char number[7];
    char sex[4];
    Date birthday;
    char id[20];
public:
    //组合类
    People(char n[11] = "", char nb[7] = "", char s[4] = "", Date b = Date(), char i[20] = "") : birthday(b) {
        strcpy(name, n);
        strcpy(number, nb);
        strcpy(sex, s);
        strcpy(id, i);
    }

    //拷贝构造函数
    People(const People &p) : birthday(p.birthday) {
        strcpy(name, p.name);
        strcpy(number, p.number);
        strcpy(sex, p.sex);
        strcpy(id, p.id);
    }

    ~People() {
    }

    void setName(char n[]) {
        strcpy(name, n);
    }

    void setNumber(char n[]) {
        strcpy(number, n);
    }

    void setSex(char s[]) {
        strcpy(sex, s);
    }

    void setBirthday(Date d) {
        birthday = d;
    }

    void setId(char i[]) {
        strcpy(id, i);
    }

    char *getName() const {
        return (char *) name;
    }

    char *getNumber() const {
        return (char *) number;
    }

    char *getSex() const {
        return (char *) sex;
    }

    Date getBirthday() const {
        return birthday;
    }

    char *getId() const {
        return (char *) id;
    }

    virtual void show() const {
        cout << "姓名：" << name << endl;
        cout << "编号：" << number << endl;
        cout << "性别：" << sex << endl;
        cout << "出生日期：";
        birthday.show();
        cout << "身份证号：" << id << endl;
    }
};

class Student : virtual public People {
protected:
    char classNo[20];
public:
    Student(char n[11] = "", char nb[7] = "", char s[4] = "", Date b = Date(), char i[20] = "", char c[20] = "")
            : People(n, nb, s, b, i) {
        strcpy(classNo, c);
    }

    void show() const {
        cout << "姓名：" << name << endl;
        cout << "编号：" << number << endl;
        cout << "性别：" << sex << endl;
        cout << "出生日期：";
        birthday.show();
        cout << "身份证号：" << id << endl;
        cout << "班号：" << classNo << endl;
    }
};

class Teacher : virtual public People {
protected:
    char principalShip[11];
    char department[21];
public:
    Teacher(char n[11] = "", char nb[7] = "", char s[4] = "", Date b = Date(), char i[20] = "", char p[11] = "",
            char d[21] = "") : People(n, nb, s, b, i) {
        strcpy(principalShip, p);
        strcpy(department, d);
    }

    void show() const {
        cout << "姓名：" << name << endl;
        cout << "编号：" << number << endl;
        cout << "性别：" << sex << endl;
        cout << "出生日期：";
        birthday.show();
        cout << "身份证号：" << id << endl;
        cout << "职务：" << principalShip << endl;
        cout << "部门：" << department << endl;
    }
};

class Graduate : public Student {
protected:
    char subject[21];
    Teacher adviser;
public:
    Graduate(char n[11] = "", char nb[7] = "", char s[4] = "", Date b = Date(), char i[20] = "", char c[20] = "",
             char su[21] = "", Teacher a = Teacher()) : People(n, nb, s, b, i), Student(n, nb, s, b, i, c),
                                                        adviser(a) {
        strcpy(subject, su);
    }

    void show() const {
        cout << "姓名：" << name << endl;
        cout << "编号：" << number << endl;
        cout << "性别：" << sex << endl;
        cout << "出生日期：";
        birthday.show();
        cout << "身份证号：" << id << endl;
        cout << "专业：" << subject << endl;
        cout << "--------------------------" << endl;
        cout << "导师：" << endl;
        adviser.show();
    }
};

class TA : public Graduate, public Teacher {
public:
    TA(char n[11] = "", char nb[7] = "", char s[4] = "", Date b = Date(), char i[20] = "", char c[20] = "",
       char su[21] = "", Teacher a = Teacher(), char p[11] = "", char d[21] = "") : People(n, nb, s, b, i),
                                                                                    Graduate(n, nb, s, b, i, c, su, a),
                                                                                    Teacher(n, nb, s, b, i, p, d) {
    }

    void show() const {
        cout << "姓名：" << name << endl;
        cout << "编号：" << number << endl;
        cout << "性别：" << sex << endl;
        cout << "出生日期：";
        birthday.show();
        cout << "身份证号：" << id << endl;
        cout << "专业：" << subject << endl;
        cout << "职务：" << principalShip << endl;
        cout << "部门：" << department << endl;
        cout << "--------------------------" << endl;
        cout << "导师：" << endl;
        adviser.show();
    }
};


int main() {
    //----------------内容一----------------
    Dog dog;
    dog.setAge(3);
    dog.show();
    cout << endl;
    //----------------内容二----------------
    Motorcycle motorcycle;
    motorcycle.print();
    motorcycle.run();
    motorcycle.stop();300
    cout << endl;
    //----------------内容三----------------
    Date date_tmp[10] = {{2004, 2,  25},
                         {2004, 3,  18},
                         {2005, 4,  16},
                         {2005, 5,  11},
                         {2005, 6,  6},
                         {2006, 7,  6},
                         {2006, 8,  3},
                         {2006, 9,  25},
                         {2006, 10, 29},
                         {2007, 12, 10}};
    Student s1("王渊", "202232", "男", date_tmp[0], "xxxxxx20040225xxxx", "计算机2201");
    Student s2("张三", "202266", "男", date_tmp[1], "xxxxxx20040318xxxx", "计算机2202");
    Teacher t1("李四", "199912", "女", date_tmp[2], "xxxxxx20050416xxxx", "教授", "计算机学院");
    Teacher t2("王五", "199726", "男", date_tmp[3], "xxxxxx20050511xxxx", "老师", "体育学院");
    Graduate g1("赵一", "201756", "女", date_tmp[4], "xxxxxx20050606xxxx", "计算机1701", "人工智能", t1);
    Graduate g2("钱二", "201710", "男", date_tmp[5], "xxxxxx20060706xxxx", "计算机1703", "大数据", t1);
    TA ta1("孙三", "201215", "男", date_tmp[6], "xxxxxx20060803xxxx", "计算机1202", "通信工程", t1, "助教",
           "大数据学院");
    TA ta2("周五", "201164", "女", date_tmp[7], "xxxxxx20060925xxxx", "计算机1101", "大数据", t1, "导师", "信计学院");
    cout << "学生一：" << endl;
    s1.show();
    cout << endl;
    cout << "学生二：" << endl;
    s2.show();
    cout << endl;
    cout << "教师一：" << endl;
    t1.show();
    cout << endl;
    cout << "教师二：" << endl;
    t2.show();
    cout << endl;
    cout << "研究生一：" << endl;
    g1.show();
    cout << endl;
    cout << "研究生二：" << endl;
    g2.show();
    cout << endl;
    cout << "助教博士生一：" << endl;
    ta1.show();
    cout << endl;
    cout << "助教博士生二：" << endl;
    ta2.show();
    return 0;
}