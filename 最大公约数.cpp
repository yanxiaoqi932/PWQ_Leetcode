/*用欧几里得算法计算两个数之间最大公约数*/
#include <iostream>
#include <stdio.h>
using namespace std;
int a,b;

int gcd(int a,int b)
{
    /*核心代码*/
    while(b!=0){
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

int main()
{
    scanf("%d %d",&a,&b);
    cout<<gcd(a,b);
    return 0;
}
