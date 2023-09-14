#include <stdio.h>
struct Employee
{
    char cName[20];
    int iAge;
    float fSalary;
};
struct Employee Accept();
void Display(struct Employee);
int main()
{
    struct Employee Tom;
    Tom=Accept();
    Display(Tom);
    return 0;
}

struct Employee Accept()
{
    struct Employee Work_Person;
    printf("请输入职员的姓名：\n");
    scanf("%s",Work_Person.cName);
    printf("请输入职员的年龄：\n");
    scanf("%d",&Work_Person.iAge);
    printf("请输入职员的月薪：\n");
    scanf("%f",&Work_Person.fSalary);
    return Work_Person;
}

void Display(struct Employee Work_Person)
{
    printf("\n--------显示个人信息--------\n");
    printf("\n职员的名子是：\t%s\n",Work_Person.cName);
    printf("职员的年龄是：\t%d\n",Work_Person.iAge);
    printf("\n职员的月薪是：\t%f\n",Work_Person.fSalary);
}
