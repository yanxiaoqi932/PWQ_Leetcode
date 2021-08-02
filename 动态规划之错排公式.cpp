/*装错信封问题，n个信封全部装错，求有多少种错误方式*/
#include <iostream>
#include <stdio.h>
using namespace std;

int f[10000];

int main()
{
    int n;
    cin>>n;
    f[1] = 1;
    f[2] = 1;
    for(int i=3;i<=n;i++){
        f[i] = (i-1)*f[i-1] + (i-1)*f[i-2];
    }
    cout<<f[n];
}
