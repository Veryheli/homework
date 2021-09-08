#include <iostream>
using namespace std;
void draw(int n)
{
    int row = 1;
    int num = 1;
    for(;row <= n;row++)
    {
        int i = 0;
        while(i < row)
        {
            cout<<num<<"\t";
            num++;
            i++;
        }
        i = 0;
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    draw(n);
    return 0;
}

