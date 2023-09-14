#include <iostream>
using namespace std;
int main()
{
    char cName[20];
    int iAge;
    float fSalary;
    cout<<"请输入职员的姓名：\t";
    cin>> cName;
    cout<<"请输入职员的年龄：\t";
    cin>> iAge;
    cout<<"请输入职员的月薪：\t";
    cin>> fSalary;
    cout<<"\n--------显示个人信息--------"<<endl;
    cout<<"\n职员的名子是：\t"<< cName <<endl;
    cout<<"\n职员的年龄是：\t"<< iAge <<endl;
    cout<<"\n职员的月薪是：\t"<< fSalary <<endl;
    return 0;
}
