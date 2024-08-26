/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 02
  * @File           : 01.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/6/22 11:05
  * @Version        : 1.0
  ****************************************************************************************
  */

//01.cpp
#include <iostream>
#include "../../SqStack.hpp"

using namespace std;

int main() {
    int choose, flag = 0;
    int num;//��ջ����
    SElemType v, t;
    SqStack S;
    cout << "1.��ʼ��ջ" << endl;
    cout << "2.˳��ջ��ջ" << endl;
    cout << "3.˳��ջ��ջ" << endl;
    cout << "4.ȡ˳��ջ��ջ��Ԫ��" << endl;
    cout << "5.����˳��ջ" << endl;
    cout << "0.�˳�" << endl;
    choose = -1;
    while (choose != 0) {
        cout << "������ѡ��0-5��";
        cin >> choose;
        switch (choose) {
            case 1: {
                if (InitStack(S)) {
                    flag = 1;
                    cout << "��ʼ���ɹ���" << endl;
                } else {
                    cout << "��ʼ��ʧ�ܣ�" << endl;
                }
            }
                break;
            case 2: {
                //�������ɳ�ʼ��
                if (flag) {
                    cout << "�������ջԪ�ظ���:" << endl;
                    cin >> num;
                    cout << "�����������ջԪ��" << endl;
                    for (int i = 0; i < num; i++) {
                        cin >> v;
                        Push(S, v);
                        cout << v << "  ";
                    }
                    cout << endl;
                    cout << "Ԫ����ջ�ɹ�!" << endl;
                } else {
                    cout << "ջδ���������������룡" << endl;
                }
            }
                break;
            case 3: {
                cout << "���γ�ջԪ��Ϊ��";
                while (Pop(S, t)) {
                    flag = -1;
                    cout << t << " ";
                }
                cout << endl;
            }
                break;
            case 4: {
                if (flag != -1 && flag != 0) {
                    cout << "ջ��Ԫ��Ϊ��" << GetTop(S) << endl;
                } else {
                    cout << "δ��ʼ����Ԫ������ɳ�ջ��ջ����Ԫ�أ�" << endl;
                }
            }
                break;
            case 5: {
                if (flag != -1 && flag != 0) {
                    cout << "ջ��Ԫ��Ϊ��";
                    StackTraverse(S);
                } else {
                    cout << "δ��ʼ����Ԫ������ɳ�ջ��ջ����Ԫ�أ�" << endl;
                }
            }
                break;
        }
    }
    system("pause");
    return 0;
}
