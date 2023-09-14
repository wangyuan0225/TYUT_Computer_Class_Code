#include <iostream>
using namespace std;
void Accept(char Nam[],int *Age_ptr,float &Sal);
void Display(char Nam[],int Age,float Sal);
int main()
{
    char cName[20];
    int iAge;
    float fSalary;
    Accept(cName,&iAge,fSalary);
    Display(cName,iAge,fSalary);
    return 0;
}

void Accept(char Nam[],int *Age_ptr,float &Sal)
{
    cout<<"请输入职员的姓名：\t";
    cin>>Nam;
    cout<<"请输入职员的年龄：\t";
    cin>>*Age_ptr;
    cout<<"请输入职员的月薪：\t";
    cin>>Sal;
}

void Display(char Nam[],int Age,float Sal)
{
    cout<<"\n--------显示个人信息--------"<<endl;
    cout<<"\n职员的名子是：\t"<<Nam<<endl;
    cout<<"\n职员的年龄是：\t"<<Age<<endl;
    cout<<"\n职员的月薪是：\t"<<Sal<<endl;
}
