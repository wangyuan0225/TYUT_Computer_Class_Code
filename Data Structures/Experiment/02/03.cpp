/**
  ****************************************************************************************
  * Copyright ? Taiyuan University of Technology. Ltd. 1902-2024. All rights reserved.
  * @BelongsProject : 02
  * @File           : 03.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2024/6/22 15:29
  * @Version        : 1.0
  ****************************************************************************************
  */

#include <iostream>
#include "../../SqQueue.hpp"

using namespace std;

int main() {
    int choose, flag = 0;
    int num;//�����и���
    QElemType v, t;
    SqQueue Q;
    cout << "1.ѭ�����еĳ�ʼ��" << endl;
    cout << "2.��ȡ���г���" << endl;
    cout << "3.�����" << endl;
    cout << "4.������" << endl;
    cout << "5.��������" << endl;
    cout << "0.�˳�" << endl;
    choose = -1;
    while (choose != 0) {
        cout << "������ѡ��0-5��";
        cin >> choose;
        switch (choose) {
            case 1:
                if (InitQueue(Q)) {
                    flag = 1;
                    cout << "��ʼ���ɹ���" << endl;
                } else {
                    cout << "��ʼ��ʧ�ܣ�" << endl;
                }
                break;
            case 2:
                cout << "���г���Ϊ�� " << (QueueLength(Q)) << endl;
                break;
            case 3:
                //�������ɳ�ʼ��
                if (flag) {
                    cout << "���������Ԫ�ظ���:" << endl;
                    cin >> num;
                    cout << "�������������Ԫ��" << endl;
                    for (int i = 0; i < num; i++) {
                        cin >> v;
                        EnQueue(Q, v);
                        cout << v << "  ";
                    }
                    cout << endl;
                    cout << "Ԫ����ӳɹ�!" << endl;
                } else {
                    cout << "����δ���������������룡" << endl;
                }
                break;
            case 4:
                DeQueue(Q, t);
                cout << "Ԫ�� " << t << " �ѳ��������" << endl;
                break;
            case 5:
                cout << "�����е�Ԫ��Ϊ��";
                QueueTraverse(Q);
                break;
        }
    }
    system("pause");
    return 0;
}
