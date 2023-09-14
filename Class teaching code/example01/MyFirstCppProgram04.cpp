#include <iostream>
using namespace std;
class Employee
{
private:
    char cName[20];
    int iAge;
    float fSalary;
public:
    Employee();
    void Display();
};

int main()
{
    Employee Tom;
    Tom.Display();
    return 0;
}

Employee::Employee()
{
    cout<<"请输入职员的姓名：";
    cin>>cName;
    cout<<"请输入职员的年龄：";
    cin>>iAge;
    cout<<"请输入职员的月薪：";
    cin>>fSalary;
}

void Employee::Display()
{
    cout<<"\n--------显示个人信息--------"<<endl;
    cout<<"\n职员的名子是："<<cName<<endl;
    cout<<"\n职员的年龄是："<<iAge<<endl;
    cout<<"\n职员的月薪是："<<fSalary<<endl;
}
