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
    int num;//进队列个数
    QElemType v, t;
    SqQueue Q;
    cout << "1.循环队列的初始化" << endl;
    cout << "2.获取队列长度" << endl;
    cout << "3.入队列" << endl;
    cout << "4.出队列" << endl;
    cout << "5.遍历队列" << endl;
    cout << "0.退出" << endl;
    choose = -1;
    while (choose != 0) {
        cout << "请输入选项0-5：";
        cin >> choose;
        switch (choose) {
            case 1:
                if (InitQueue(Q)) {
                    flag = 1;
                    cout << "初始化成功！" << endl;
                } else {
                    cout << "初始化失败！" << endl;
                }
                break;
            case 2:
                cout << "队列长度为： " << (QueueLength(Q)) << endl;
                break;
            case 3:
                //如果已完成初始化
                if (flag) {
                    cout << "请输入入队元素个数:" << endl;
                    cin >> num;
                    cout << "请依次输入入队元素" << endl;
                    for (int i = 0; i < num; i++) {
                        cin >> v;
                        EnQueue(Q, v);
                        cout << v << "  ";
                    }
                    cout << endl;
                    cout << "元素入队成功!" << endl;
                } else {
                    cout << "队列未创建，请重新输入！" << endl;
                }
                break;
            case 4:
                DeQueue(Q, t);
                cout << "元素 " << t << " 已出队列完成" << endl;
                break;
            case 5:
                cout << "队列中的元素为：";
                QueueTraverse(Q);
                break;
        }
    }
    system("pause");
    return 0;
}
