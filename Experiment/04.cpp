/**
  ****************************************************************************************
  * Copyright ? TaiYuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : 04.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : ��1����д���򣬽��ַ������ļ�д����ȷ���ö����Ʒ�ʽд�뵽�ļ�data.dat�У�����
                           �����Ʒ�ʽ��data.dat��һ���ļ��򿪣�����Ļ����ʾ������
                      ��2������һ��ѧ�������飬�������ݣ���ʾ������ʹ��I/O���Ѵ����������д�����
                           �ļ�������ʾ���ļ����ݡ�
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

    //������Ա����
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
    //�����
    People(char n[11] = "", char nb[7] = "", char s[4] = "", Date b = Date(), char i[20] = "") : birthday(b) {
        strcpy(name, n);
        strcpy(number, nb);
        strcpy(sex, s);
        strcpy(id, i);
    }

    //�������캯��
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
        cout << "������" << name << endl;
        cout << "��ţ�" << number << endl;
        cout << "�Ա�" << sex << endl;
        cout << "�������ڣ�";
        birthday.show();
        cout << "���֤�ţ�" << id << endl;
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
        cout << "������" << name << endl;
        cout << "��ţ�" << number << endl;
        cout << "�Ա�" << sex << endl;
        cout << "�������ڣ�";
        birthday.show();
        cout << "���֤�ţ�" << id << endl;
        cout << "��ţ�" << classNo << endl;
    }
};

int main() {
    //****************************************����һ****************************************
    ofstream fout;
    fout.open("data.dat", ios::binary);
    if (fout.fail()) {
        cout << "cannot open file!" << endl;
        exit(1);
    }
    char s[] = "�ļ�д����ȷ";
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

    //****************************************���ݶ�****************************************
    Student students[3];
    char name[11];
    char number[7];
    char sex[4];
    char id[20];
    char classNo[20];

    for (int i = 0; i < 3; ++i) {
        cout << "������ѧ��" << i + 1 << "����Ϣ��" << endl;
        cout << "������";
        cin >> name;
        students[i].setName(name);
        cout << "ѧ�ţ�";
        cin >> number;
        students[i].setNumber(number);
        cout << "�Ա�";
        cin >> sex;
        students[i].setSex(sex);
        cout << "���գ��� �� �գ���";
        int year, month, day;
        cin >> year >> month >> day;
        Date d = Date(year, month, day);
        students[i].setBirthday(d);
        cout << "���֤�ţ�";
        cin >> id;
        students[i].setId(id);
        cout << "�༶��";
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
        //fin.seekg(i * sizeof(students), ios::beg);
        fin.read((char *) &tmp_s, sizeof(students[i]));
        cout << "��" << i + 1 << "��ѧ������Ϣ��" << endl;
        tmp_s.show();
        cout << "--------------------------------------" << endl;
    }
    fin.close();
    return 0;
}
