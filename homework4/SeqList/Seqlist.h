//[==============================================================]
//[ @Author: Chenrenhao 
//[ @Created Time : 2021年09月29日 星期三 18时15分05秒
//[==============================================================]
 
#pragma once
#include <iostream>
#define CAPACITY 20 //元素的容量
#define FLOWOUT_ERROR  -1 //数据溢出的错误信息
#define OUT_OF_BOUNDS_ERROR  -2 //访问越界错误信息
template <typename T>
class Seqlist{
public:
    Seqlist (){
        this->length = 0;
    }
    bool insert(int index,T data){
        //防止访问越界
        if(index >this->length + 1 || index < 0){
            throw OUT_OF_BOUNDS_ERROR;
            return false;
        }
        //防止数据溢出
        if(this->length == CAPACITY){
            throw FLOWOUT_ERROR;
            return false;
        }
        int i;
        for (i = this->length - 1; i > index  ; --i) {
            this->data[i + 1] = this->data[i];
        }
        this->data[index] = data;
        this->length++;
        return true;
    }
    T deleteData(int index){
        //防止访问越界
        if(index > this->length - 1 || index < 0){
            throw OUT_OF_BOUNDS_ERROR;
            return (T) 0;
        }
        int i;
        T target = this->data[index];
        for (i = index; i < this->length - 1; ++i) {
            this->data[i] = this->data[i + 1];
        }
        this->length--;
        return target;
    }
    void showData(){
        int i;
        for (i = 0; i < this->length; ++i) {
            std::cout<<this->data[i]<<"\t";
        }
        std::cout<<"\n";
    }

private:
    /* data */
    int length;
    T data[CAPACITY];
};
