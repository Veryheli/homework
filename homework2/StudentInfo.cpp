#include <iostream>
using namespace std;
struct Student
{
    int id = -1;//将id默认标记为-1用于判断数据是否初始化
    string name;
    float score1;
    float score2;
    float score3;
    float average;
};
//求成绩平均分的函数
void average(Student students[6])
{
    for(int i = 0;i < 6;i ++)
    {
        students[i].average = (students[i].score1 + students[i].score2 +students[i].score3)/3;
    }
}
//输入数据的函数
void inputMessage(Student students[6])
{
    if(students[0].id != -1)//第一次录入信息后不能重复录入
    {
        cout<<"已录入学生信息，不可重复录入！"<<endl;
        return;
    }
    cout<<"输入6个学生信息"<<endl;
    cout<<"每输入一项后按TAB分隔"<<endl;
    for(int i = 0;i < 6;i++)
    {
        //默认按id为1,2,3,4,5,6来输入
        students[i].id = i+1;
        cout<<"|第"<<i + 1<<"个学生信息"<<endl;
        cout<<"|id\tname\tscore1\tscore2\tscore3\t"<<endl;
        cout<<"|"<<i+1<<"\t";
        cin>>students[i].name>>students[i].score1>>students[i].score2>>students[i].score3;
    }
    //录入学生信息后顺便将平均分求出来
    average(students);
    cout<<"成功录入学生信息！"<<endl;
}
//输出学生信息的函数
void showMessage(Student students[6])
{
    //用id是否为-1 来判断数据是否初始化
    if(students[0].id == -1)
    {
        cout<<"尚未录入学生信息！请先录入学生信息！"<<endl;
        return;
    }
    cout<<"|id\t|name\t|score1\t|score2\t|score3\t|average"<<endl;
    for(int i = 0;i < 6;i++)
    {
        cout<<"|"<<students[i].id<<"\t|"<<students[i].name<<"\t|"<<students[i].score1<<"\t|"<<
            students[i].score2<<"\t|"<<students[i].score3<<"\t|"<<students[i].average<<endl;
    }

}
//按id查找学生的函数
void findStudent(Student students[6])
{
    //先判断数据是否初始化
    if(students[0].id == -1)
    {
        cout<<"尚未录入学生信息！请先录入学生信息！"<<endl;
        return;
    }
    int id;
    cout<<"请输入你要查询的学生的id:";
    cin>>id;
    //根据用户输入的id输出对应的信息
    if(id > 6 || id < 1)
    {
        cout<<"输入错误！请重新输入！"<<endl;
        return;
    }
        cout<<"查询信息如下"<<endl;
        cout<<"|id\t|name\t|score1\t|score2\t|score3\t|average"<<endl;
        cout<<"|"<<students[id - 1].id<<"\t|"<<students[id - 1].name<<"\t|"<<students[id - 1].score1<<"\t|"<<students[id - 1].score2<<"\t|"<<
            students[id - 1].score3<<"\t|"<<students[id - 1].average<<endl;
}
//按平均数用选择法进行排序
void rankStudent(Student students[6])
{
   Student *p,temp;//p 用来记录分数最小的学生
   int i,j;
   p = &students[0];
   for(i = 0,j = 0; i < 5;i ++)
   {
       //遍历出分数最小的学生
        while(j < 6 - i)
        {
            if(p->average > students[j].average)
                p = &students[j];
            j++;
        }
        j = 0;
        //将分数最小的学生交换到数组的末尾
        if(p != &students[6 - i -1])
        {
            temp = *p;
            *p = students[6 - i -1];
            students[6 - i -1] = temp;
        }
        //从头开始遍历
        p = &students[0];
   }

}
//展示菜单的函数
void showMenu()
{
        cout<<"     |-----输入数字选择功能----|        "<<endl;
        cout<<"     |-------------------------|        "<<endl;
        cout<<"     |-----1.录入学生信息------|        "<<endl;
        cout<<"     |-----2.显示学生信息------|        "<<endl;
        cout<<"     |-----3.按成绩排序并输出--|        "<<endl;
        cout<<"     |-----4.按id查询学生------|        "<<endl;
        cout<<"     |-----5.显示菜单----------|        "<<endl;
        cout<<"     |-----0.退出程序----------|        "<<endl;
        cout<<"     |-------------------------|        "<<endl;
}
//实现菜单的逻辑
void menu(Student students[6])
{   
    bool isRun = true;//isRun作为程序运行的标志
    int ch;//记录用户的输入
    showMenu();
    while(isRun)
    {
        cout<<"请输入你的选择：";
        cin>>ch;
        switch(ch)
        {
            case 1:{
                       inputMessage(students);
                       break;
                   }
            case 2:{
                       showMessage(students);
                       break;
                   }
            case 3:{
                       rankStudent(students);
                       showMessage(students);
                       break;
                   }
            case 4:{
                       findStudent(students);
                       break;
                   }
            case 5:{
                       showMenu();
                       break;
                   }
            case 0:{
                       isRun = false;
                       cout<<"程序已退出！"<<endl;
                       break;
                   }
            default:
                   cout<<"输入错误！请重新输入！"<<endl;
        }
    }
}
int main()
{
    Student students[6];
    menu(students);
    return 0;
}
