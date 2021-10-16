#ifndef STUDENT_H
#define STUDENT_H
#define FILENAME "data.txt"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
/* 学生包含的信息：姓名、性别、学号、三门科目的成绩和总成绩*/
struct Student{
    int _id;
    std::string _name;
    std::string _gender;
    float _math;
    float _english;
    float _c_plus_plus;
    float _total;
};
class Students{//程序只创建一个Students对象
private:
    Students(){}
public:
    std::vector<Student> _data;
    static Students * _instance;
    static Students * getInstance();
    void initialize();//初始化,从文件中读取信息
    void show();//显示所有信息
    void saveInFile();//将数据储存到文件中
    void rankById();//按学号排序
    void rankByScore();//按成绩排序
    void addOneStudent();//增加一个学生
    void addStudents(int _num);//增加若干个学生，num为要增加的学生的数量
    //重载search函数实现按学号或者姓名查找
    std::vector<Student>::iterator search(int _id);
    std::vector<Student>::iterator search(std::string _name);
    std::vector<Student>::iterator autoSearch(std::string _target);//自动判断输入的数据进行查找
    bool deleteStudent(std::string _target);
};
#endif /* STUDENT_H */
