/**
  ****************************************************************************************
  * Copyright © Taiyuan University of Technology. Ltd. 1902-2023. All rights reserved.
  * @BelongsProject : Experiment
  * @File           : test_static&count.cpp
  * @Author         : yuan wang (wy0225)
  * @Brief          : None
  * @Attention      : None
  * @Date           : 2023-11-04  22:52
  * @Version        : 1.0
  ****************************************************************************************
  */
#include <iostream>
using namespace std;

class Test {

public:
    static const int c = 0;
    int d;
    const int b;
    static int a;
    Test(int i);
    static int a_();
    int b_() const;
    int d_();
};

const int c = 1;

Test::Test(int i): b(i) {

}

int Test::a_() {
    a = 1;
    return a;
}

int Test::b_() const {
    a = 2;
    a_();
    return b;
}

int Test::d_() {
    d = 1;
    return d;
}

int Test::a = 0;

int main() {
    Test t(1);
    Test::a = t.b;
    t.b_();
    cout << Test::c << endl;
    t.c;
    static Test t2(2);
    t2.a;
    t2.b;
    t2.c;
    t2.d;
    t2.a_();
    t2.b_();
    t2.d_();
    const Test t3(3);
    t3.a;
    t3.b;
    t3.c;
    t3.d;
    t3.a_();
    t3.b_();
    t3.d_();
    Test t4(4);
    t4.a;
    t4.b;
    t4.c;
    t4.d;
    t4.a_();
    t4.b_();
    t4.d_();
    cout << Test::a << endl;
    static const Test t5(5);
    t5.a;
    t5.b;
    t5.c;
    t5.d;
    t5.a_();
    t5.b_();
    t5.d_();

    return 0;
}