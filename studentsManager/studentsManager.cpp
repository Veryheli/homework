/******************************************************************************
*@ File:             studentsManager.cpp
*
*@ Author:           Chenrenhao
*@ Created:          10/13/21 
*@ Description:      学生信息管理系统

    一、学生的信息包含：1.学号
                        2.姓名
                        3.性别
                        4.成绩（各科成绩和总成绩）
    二、使用顺序存储结构（vector）
    三、对文件进行操作
    四、实现的功能：
        1、增添改查；
        2、文件保存与读取
        3、排序；
        4、求平均值（个人平均与全部学生的平均）
*****************************************************************************/
#include"students.h"
using namespace std;
Students * _students;// 将创建出来的学生类声明为全局变量
void initialize(){
    _students = Students::getInstance();
    _students->initialize();
    cout<<"[--------------欢迎使用学生管理系统！------------]"<<endl;
}
void drawMenu(){
    cout<<"[-------------1 、显示所有学生信息---------------]"<<endl;
    cout<<"[-------------2 、增加学生-----------------------]"<<endl;
    cout<<"[-------------3 、删除信息-----------------------]"<<endl;
    cout<<"[-------------4 、修改信息-----------------------]"<<endl;
    cout<<"[-------------5 、查询信息-----------------------]"<<endl;
    cout<<"[-------------6 、按学号排序---------------------]"<<endl;
    cout<<"[-------------7 、按成绩排序---------------------]"<<endl;
    cout<<"[-------------8 、求平均成绩---------------------]"<<endl;
    cout<<"[-------------9 、保存文件-----------------------]"<<endl;
    cout<<"[-------------10、显示菜单-----------------------]"<<endl;
    cout<<"[-------------0 、退出程序-----------------------]"<<endl;
}
void addStudent(){
   int _num;
   cout<<"要增加几个学生信息？"<<endl;
   cin>>_num;
   if(_num > 0)
   {
       _students->addStudents(_num);
   }else{
       cout<<"输入错误！"<<endl;
   }

}
void deleteStudent(){
   string _target;
   cout<<"输入你要删除的学生的姓名或学号"<<endl;
   cin>>_target;
   _students->deleteStudent(_target);

}
void fixData(){
   string _target;
   cout<<"输入要修改的学生的学号或姓名：";
   cin>>_target;
   vector<Student>::iterator it = _students->autoSearch(_target);
   if(it != _students->_data.end() ){
        Student _buffer;
        cout<<"输入修改后的信息:"<<endl;
        std::cin>>_buffer._id;
        std::cin>>_buffer._name;
        std::cin>>_buffer._gender;
        std::cin>>_buffer._math;
        std::cin>>_buffer._english;
        std::cin>>_buffer._c_plus_plus;
        _buffer._total = _buffer._math + _buffer._english + _buffer._c_plus_plus;
        *it = _buffer;
        cout<<"修改成功！"<<endl;
   }
}
void search(){
   string _target;
   cout<<"输入你要查询的学生的姓名或学号:";
   cin>>_target;
   _students->autoSearch(_target);
}
void average(){
   int count = 0;
   float math_total = 0,english_total = 0,cpp_total = 0, total = 0;
   for (auto i = _students->_data.begin(); i != _students->_data.end(); ++i) {
       math_total += i->_math;
       english_total += i->_english;
       cpp_total += i->_c_plus_plus;
       total += i->_total;
       count ++;
   }
   cout<<"数学平均分为："<<math_total       / count<<endl;
   cout<<"英语平均分为："<<english_total    / count<<endl;
   cout<<"c++平均分为：" <<cpp_total        / count<<endl;
   cout<<"总分平均分为："<<total            / count<<endl;
}
void menu(){
    int ch;
    drawMenu();
    while(1){
        cin>>ch;
        switch(ch){
            case 1:{
                       system("clear");
                       _students->show();
                       drawMenu();
                       break;
                   }
            case 2:{
                       system("clear");
                       addStudent();
                       drawMenu();
                       break;
                   }
            case 3:{
                       system("clear");
                       _students->show();
                       deleteStudent();
                       drawMenu();
                       break;
                   }
            case 4:{
                       system("clear");
                       _students->show();
                       fixData();
                       drawMenu();
                       break;
                   }
            case 5:{
                       system("clear");
                       _students->show();
                       search();
                       drawMenu();
                       break;
                   }
            case 6:{
                       system("clear");
                       _students->rankById();
                       drawMenu();
                       break;
                   }
            case 7:{
                       system("clear");
                       _students->rankByScore();
                       drawMenu();
                       break;
                   }
            case 8:{
                       system("clear");
                       average();
                       drawMenu();
                       break;
                   }
            case 9:{
                       system("clear");
                       _students->saveInFile();
                       drawMenu();
                       break;
                   }
            case 10:{
                        system("clear");
                        drawMenu();
                        break;
                    }
            case 0:{
                        system("clear");
                        return;
                   }
            default:{
                       system("clear");
                       drawMenu();
                       cout<<"输入错误！"<<endl;
                    }
        }
    }
}
void run(){
    menu();
    system("clear");
    cout<<"退出前是否保存？(输入y保存，输入其他选项不保存)"<<endl;
    char ch = 'y';
    cin>>ch;
    if('y' == ch){
        _students->saveInFile();
    }
    delete _students;
}
int main(){
    initialize();
    run();
    return 0;
}
