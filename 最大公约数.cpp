/*��ŷ������㷨����������֮�����Լ��*/
#include <iostream>
#include <stdio.h>
using namespace std;
int a,b;

int gcd(int a,int b)
{
    /*���Ĵ���*/
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
