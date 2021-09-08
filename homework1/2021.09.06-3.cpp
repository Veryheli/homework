//设计一个计算机实现加减乘除的功能
#include <iostream>
#include<cstdlib>
#include<string>
using namespace std;
template <typename T>
T myAdd(T a, T b)
{
    return a + b;
}
template<typename T>
T mySub(T a,T b)
{
    return a - b;
}
template<typename T>
float myDivision(T a,T b)
{
    return float(a) / (float)b;
}
template<typename T>
T myMulti(T a,T b)
{
    return a * b;
}
int main()
{
    string a;
    int pos1,pos2,pos3,pos4;
    cin>>a;
    pos1=a.find("+");
    pos2=a.find("-");
    pos3=a.find("*");
    pos4=a.find("/");
    if(pos1 != -1)
    {
        string former = a.substr(0,pos1);
        if(former.find(".")!=-1)
        {
            double formerf = atof(former.c_str());
            string later = a.substr(pos1 + 1,a.length()-pos1-1);
            double laterf = atof(later.c_str());
            cout<<former<<"+"<<later<<"="<<myAdd(formerf,laterf)<<endl;
        }
        else
        {
            int formerf = atoi(former.c_str());
            string later = a.substr(pos1 + 1 ,a.length() - pos1-1);
            int laterf = atoi(later.c_str());
            cout<<former<<"+"<<later<<"="<<myAdd(formerf,laterf)<<endl;
        }
    }
    else if (pos2 != -1) 
    {
        string former = a.substr(0,pos2);
        if(former.find(".")!=-1)
        {
            double formerf = atof(former.c_str());
            string later = a.substr(pos2 + 1,a.length()-pos2-1);
            double laterf = atof(later.c_str());
            cout<<former<<"-"<<later<<"="<<mySub(formerf,laterf)<<endl;
        }
        else
        {
            int formerf = atoi(former.c_str());
            string later = a.substr(pos2+1,a.length() - pos2-1);
            int laterf = atoi(later.c_str());
            cout<<former<<"-"<<later<<"="<<mySub(formerf,laterf)<<endl;
        }
    }
    else if (pos3 != -1)
    {
        string former = a.substr(0,pos3);
        if(former.find(".")!=-1)
        {
            double formerf = atof(former.c_str());
            string later = a.substr(pos3+1,a.length()-pos3-1);
            double laterf = atof(later.c_str());
            cout<<former<<"*"<<later<<"="<<myMulti(formerf,laterf)<<endl;
        }
        else
        {
            int formerf = atoi(former.c_str());
            string later = a.substr(pos3+1,a.length() - pos3-1);
            int laterf = atoi(later.c_str());
            cout<<former<<"*"<<later<<"="<<myMulti(formerf,laterf)<<endl;
        }
    }
    else if (pos4 != -1)
    {
        string former = a.substr(0,pos4);
        if(former.find(".")!=-1)
        {
            double formerf = atof(former.c_str());
            string later = a.substr(pos4+1,a.length()-pos4-1);
            double laterf = atof(later.c_str());
            cout<<former<<"/"<<later<<"="<<myDivision(formerf,laterf)<<endl;
        }
        else
        {
            int formerf = atoi(former.c_str());
            string later = a.substr(pos4+1,a.length() - pos4-1);
            int laterf = atoi(later.c_str());
            cout<<former<<"/"<<later<<"="<<myDivision(formerf,laterf)<<endl;
        }

    }


    return 0;
}

