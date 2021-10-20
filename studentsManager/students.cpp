/******************************************************************************
*@ File:             students.cpp
*
*@ Author:           Chenrenhao
*@ Created:          10/15/21 
*****************************************************************************/

#include "students.h"
#include <cstdlib>
#include <fstream>
#include <algorithm>
Students * Students::_instance = nullptr;
Students * Students::getInstance(){
    if(_instance == nullptr){
        _instance = new Students();
    }
    return _instance;
}
/******************************************************************************
* Function:         void Students::show
* Description:      
*****************************************************************************/
void Students::show(){
    std::cout<<"学号"<<"\t\t"<<"姓名"<<"\t\t"<<"性别"<<"\t\t"<<"数学"<<"\t\t"<<"英语"
        <<"\t\t"<<"c++"<<"\t\t"<<"总分"<<std::endl;
    for (auto i = _data.begin(); i != _data.end(); ++i) {
        std::cout<<i->_id<<"\t\t"<<i->_name<<"\t\t"<<i->_gender<<"\t\t"<<i->_math<<"\t\t"<<i->_english
            <<"\t\t"<<i->_c_plus_plus<<"\t\t"<<i->_total<<std::endl;
    }
}
/******************************************************************************
* Function:         void Students::initialize
* Description:      初始化Students,从文件中读取数据
*****************************************************************************/
void Students::initialize(){
    std::fstream f;
    f.open(FILENAME,std::ios::in);
    if(!f){
        std::cout<<"未检测到"<<FILENAME<<"文件!"<<std::endl;
        return;
    }
    Student _buffer;
    while(!f.eof()){
        f>>_buffer._id;
        f>>_buffer._name;
        f>>_buffer._gender;
        f>>_buffer._math;
        f>>_buffer._english;
        f>>_buffer._c_plus_plus;
        f>>_buffer._total;
        _data.push_back(_buffer);
    }
    //每次读取都会多读取一个数据
    _data.pop_back();
    std::cout<<"初始化完成！"<<std::endl;
    f.close();
}
/******************************************************************************
* Function:         void Students::saveInFile
* Description:      将数据保存文件中
*****************************************************************************/
void Students::saveInFile(){
    std::fstream f;
    f.open(FILENAME,std::ios::out);
    for (auto i = _data.begin(); i != _data.end(); ++i) {
        f<<i->_id<<"\t"<<i->_name<<"\t\t"<<i->_gender<<"\t"<<i->_math<<"\t"<<i->_english<<"\t"<<i->_c_plus_plus<<"\t"<<i->_total<<"\n";
    }
    std::cout<<"保存成功！"<<std::endl;
    f.close();
}
/******************************************************************************
* Function:         void Students::rankById
* Description:      按学号排序
*****************************************************************************/
bool idCompare(Student a,Student b){
    return a._id < b._id;
}
void Students::rankById(){
    std::sort(_data.begin(),_data.end(),idCompare);
    std::cout<<"按学号排序后结果如下:"<<std::endl;
    show();
}
/******************************************************************************
* Function:         void Students::rankByScore
* Description:      按成绩排序
*****************************************************************************/
bool scoreCompare(Student a,Student b){
    return a._total > b._total;
}
void Students::rankByScore(){
    std::sort(_data.begin(),_data.end(),scoreCompare);   
    std::cout<<"按成绩排序后结果如下:"<<std::endl;
    show();
}
/******************************************************************************
* Function:         void Students::addOneStudent
* Description:      增加一个学生
*****************************************************************************/
void Students::addOneStudent(){
    Student _buffer;
    std::cin>>_buffer._id;
    std::cin>>_buffer._name;
    std::cin>>_buffer._gender;
    std::cin>>_buffer._math;
    std::cin>>_buffer._english;
    std::cin>>_buffer._c_plus_plus;
    _buffer._total = _buffer._math + _buffer._english + _buffer._c_plus_plus;
    if((_buffer._gender != "男" && _buffer._gender != "女") || (_buffer._id < 0) || (_buffer._math < 0) ||
            (_buffer._english < 0) || (_buffer._c_plus_plus < 0)){
        std::cout<<"信息输入有误！请重新输入该生信息！"<<std::endl;
        addOneStudent();
    }else{
        _data.push_back(_buffer);
    }
}
/******************************************************************************
* Function:         void Students::addStudents
* Description:      添加若干个学生，num为要添加的学生数量
*****************************************************************************/
void Students::addStudents(int num){
    std::cout<<"输入信息时按照学号、姓名、性别、数学成绩、英语成绩、C++成绩的顺序输入。\n每一项按TAB或者空格分开。"<<std::endl;
    for(int i = 0;i < num ;i++){
        std::cout<<"请输入第"<<i + 1<<"个学生的信息"<<std::endl;
        addOneStudent();
    }
}
/******************************************************************************
* Function:         bool Students::search(std::string _name)
* Description:      按名字查找
* Return:  查找到信息则返回对应的迭代器否则返回_data.end()         
*****************************************************************************/
std::vector<Student>::iterator Students::search(std::string _name){
    for (auto i = _data.begin(); i != _data.end(); ++i) {
        if(i->_name == _name){
            std::cout<<"查询结果如下："<<std::endl;
            
            std::cout<<"学号"<<"\t"<<"姓名"<<"\t"<<"性别"<<"\t"<<"数学"<<"\t"<<"英语"
                <<"\t"<<"c++"<<"\t"<<"总分"<<std::endl;
            std::cout<<i->_id<<"\t"<<i->_name<<"\t"<<i->_gender<<"\t"<<i->_math<<"\t"<<i->_english
                <<"\t"<<i->_c_plus_plus<<"\t"<<i->_total<<std::endl;
            return i;
        }
    }
    return _data.end();
}
/******************************************************************************
* Function:         bool Students::search(int _id)
* Description:      按学号查询
* Return:           找到返回对应的迭代器否则返回_data.end()
*****************************************************************************/
std::vector<Student>::iterator Students::search(int _id){
    for (auto i = _data.begin(); i != _data.end(); ++i) {
        if(i->_id == _id){
            std::cout<<"查询结果如下："<<std::endl;
            std::cout<<"学号"<<"\t"<<"姓名"<<"\t"<<"性别"<<"\t"<<"数学"<<"\t"<<"英语"
                <<"\t"<<"c++"<<"\t"<<"总分"<<std::endl;
            std::cout<<i->_id<<"\t"<<i->_name<<"\t"<<i->_gender<<"\t"<<i->_math<<"\t"<<i->_english
                <<"\t"<<i->_c_plus_plus<<"\t"<<i->_total<<std::endl;
            return i;
        }
    }
    return _data.end();
}
//该函数用于判断一个string是否为数字
bool allIsNum(std::string _tar){
    for (auto i = _tar.begin(); i != _tar.end(); ++i) {
        if(int(*i) < 48 || int(*i) > 57){
            return false;
        }
    }
    return true;
}
/******************************************************************************
* Function:         void Students::auroSearch
* Description:      自动判断用户输入并查询
* Return:           对应的迭代器，未找到返回_data.end()
*****************************************************************************/
std::vector<Student>::iterator Students::autoSearch(std::string _target){
    std::vector<Student>::iterator f;
    if(allIsNum(_target)){
        f = search(atoi(_target.c_str()));
    }else{
        f = search(_target);
    }
    if(_data.end() == f){
        std::cout << "未查询到信息！" << std::endl;
    }
    return f;
}
/******************************************************************************
* Function:         void Students::deleteStudent
* Description:      通过用户的输入判断输入的为名字还是学号，并删除目标
* Return:           删除成功返回true否则返回false
*****************************************************************************/
bool Students::deleteStudent(std::string _target){
    std::vector<Student>::iterator it = autoSearch(_target);
    if(it == _data.end()){
        return false;
    }
    _data.erase(it);
    std::cout<<"删除成功！"<<std::endl;
    return true;
}

