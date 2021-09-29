//[==============================================================]
//[ @Author: Chenrenhao 
//[ @Created Time : 2021年09月29日 星期三 18时22分12秒
//[==============================================================]

#include <iostream>
#include "Seqlist.h"
using namespace std;
int main()
{
    Seqlist<int> a;
    cout<<"初始化后"<<endl;
    for(int i = 0; i < 10;i ++){
        a.insert(i,i+1);
    }
    a.showData();
    cout<<"删除的数据是"<<a.deleteData(7)<<endl;
    cout<<"删除后"<<endl;
    a.showData();

    return 0;
}
