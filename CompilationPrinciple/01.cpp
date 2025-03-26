/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : OS
  * @File           : 01.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/12/19 14:08
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <bits/stdc++.h>

using namespace std;
const int N = 100;
char ch[N];    //�������ķ��Ŵ�
int cnt;

void unsigned_number();    //ʶ���޷����������
int float_number(int b);

int _E(int b);

void print(int hh, int tt);

int main() {
    cnt = 0;
    for (;;) {  //�����ַ���
        cin >> ch[cnt];
        if (ch[cnt] == ';') break;    //�ַ�����;����
        cnt++;
    }
    unsigned_number();    //ʶ���޷����������
    return 0;
}

void unsigned_number() {
    bool isfirst = true;
    int hh, tt;    //hh��ʾʶ�𵽵��޷���ʵ���ĵ�һ������tt�������һ����
    for (int i = 0; i <= cnt; i++) {
        if (isfirst) {    //ʶ���޷������ĵ�һ����
            if (isdigit(ch[i])) {
                isfirst = false;
                hh = i;    //���ʶ�𵽵��޷������ĵ�һ����
            } else continue;
        } else {
            if (isdigit(ch[i])) continue;
            else if (ch[i] == '.') {
                //����������������򸡵����Ŀ�ѧ������ʾ
                tt = float_number(i);
                cout << "�޷���ʵ����";
                print(hh, tt);
                isfirst = true;
                i = tt;
            } else if (ch[i] == 'E') {
                //��������������Ŀ�ѧ������ʾ
                tt = _E(i);
                cout << "�޷���ʵ����";
                print(hh, tt);
                isfirst = true;
                i = tt;
            } else {
                //�������
                tt = i;
                cout << "�޷���������";
                print(hh, tt);
                isfirst = true;
            }
        }
    }
}

void print(int hh, int tt) {
    for (int j = hh; j < tt; j++)
        cout << ch[j];
    cout << endl;
}

int float_number(int i) {
    //����flag���ж��ǲ���С������һ���ַ�
    bool flag = true;
    int t;
    for (int j = i + 1; j <= cnt; j++) {
        if (flag) {
            flag = false;
            //С����'.'���һ���ַ���������������򷵻�'.'���±�
            if (isdigit(ch[j])) continue;
            else {
                t = i;
                return t;
            }
        } else {
            if (isdigit(ch[j])) continue;
                //����'E',ͨ�����ú���_E()���õ�Ҫ���ص��±�
            else if (ch[j] == 'E') {
                t = _E(j);
                return t;
            } else {
                t = j;
                return t;
            }
        }
    }
}

int _E(int i) {
    //����flag���ж��ǲ���'E'��ĵ�һ���ַ�������flag2���ж��ǲ���'E'��ĵڶ����ַ�
    //ͨ����������־���ж��ַ�E֮���ַ��ĺϷ���
    bool flag = true;
    bool flag2 = true;
    int t;
    for (int j = i + 1; j < cnt; j++) {
        if (flag) {
            flag = false;
            //�ַ�'E'֮����'+'��'-'����� ���򷵻��ַ�'E'���±�
            if (ch[j] == '+' || ch[j] == '-') continue;
            else {
                t = i;
                return t;
            }
        } else {
            if (flag2) {
                flag2 = false;
                //���'E'����ĵڶ����ַ�����������������򷵻�'E'���±�
                if (isdigit(ch[j])) continue;
                else {
                    t = i;
                    return t;
                }
            } else {
                if (isdigit(ch[j])) continue;
                else {
                    t = j;
                    return t;
                }
            }
        }
    }
}
