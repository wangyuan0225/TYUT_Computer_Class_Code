/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : 04.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : （1）编写程序，将字符串“文件写入正确”用二进制方式写入到文件data.dat中，并用
                           二进制方式将data.dat的一个文件打开，在屏幕上显示出来。
                      （2）定义一个学生类数组，输入数据，显示出来，使用I/O流把此数组的内容写入磁盘
                           文件，再显示出文件内容。
  * @Attention      : None
  * @Date           : 2023-10-19  21:25
  * @Version        : 1.0
  ****************************************************************************************
  */
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

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

    void show() const {
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

    void setClassNo(char c[]) const {
        strcpy((char *) classNo, c);
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

int main() {
    //****************************************内容一****************************************
    ofstream fout;
    fout.open("data.dat", ios::binary);
    if (fout.fail()) {
        cout << "cannot open file!" << endl;
        exit(1);
    }
    char s[] = "文件写入正确";
    int len = strlen(s);
    fout.write(s, len);
    fout.close();

    ifstream fin;
    char tmp[len];
    fin.open("data.dat", ios::binary);
    if (fin.fail()) {
        cout << "cannot open file!" << endl;
        exit(2);
    }
    fin.read(tmp, len);
    tmp[len] = '\0';
    cout << tmp << endl;
    fin.close();

    //****************************************内容二****************************************
    Student students[3];
    char name[11];
    char number[7];
    char sex[4];
    char id[20];
    char classNo[20];

    for (int i = 0; i < 3; ++i) {
        cout << "请输入学生" << i + 1 << "的信息：" << endl;
        cout << "姓名：";
        cin >> name;
        students[i].setName(name);
        cout << "学号：";
        cin >> number;
        students[i].setNumber(number);
        cout << "性别：";
        cin >> sex;
        students[i].setSex(sex);
        cout << "生日（年 月 日）：";
        int year, month, day;
        cin >> year >> month >> day;
        Date d = Date(year, month, day);
        students[i].setBirthday(d);
        cout << "身份证号：";
        cin >> id;
        students[i].setId(id);
        cout << "班级：";
        cin >> classNo;
        students[i].setClassNo(classNo);
    }

    fout.open("student.txt");
    if (fout.fail()) {
        cout << "cannot open file!" << endl;
        exit(1);
    }

    for (int i = 0; i < 3; ++i) {
        fout.write((char *) &students[i], sizeof(students[i]));
    }
    fout.close();

    fin.open("student.txt");
    if (fin.fail()) {
        cout << "cannot open file!" << endl;
        exit(2);
    }
    cout << "--------------------------------------" << endl;
    for (int i = 0; i < 3; ++i) {
        Student tmp_s;
        fin.read((char *) &tmp_s, sizeof(students[i]));
        cout << "第" << i + 1 << "个学生的信息：" << endl;
        tmp_s.show();
        cout << "--------------------------------------" << endl;
    }
    fin.close();
    return 0;
}
