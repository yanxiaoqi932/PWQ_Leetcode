#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

struct bigInteger
{
    int digit[1000];
    int size;

    void init()
    {
        for(int i=0;i<=999;i++){
            digit[i] = 0;
        }
        size = 0;
    }

    void set(string str)
    {
        for(int i=str.length()-1;i>=0;i--){
            int tmp = 0;
            if(str[i]>='0' && str[i]<='9'){
                tmp = str[i]-'0';
            }else{
                tmp = str[i]-'A'+10;
            }
            digit[size] = digit[size]+tmp*pow(10,i%4);
            if((i+1)%4 == 0){
                size++;
            }
        }
        if(digit[size]!=0) size++;  //size要比digit实际的最高数组位置大1
    }

    void output()
    {
        for(int i=size-1;i>=0;i--){
            if(i!=size-1){  //非最高位时，都要补齐四位数
                printf("%04d",digit[i]);
            }else{
                printf("%d",digit[i]);
            }
        }
        printf("\n");
    }

    bigInteger operator + (const bigInteger &A) const
    {
        bigInteger ret;ret.init();
        int carry = 0;  //低位数的进位
        for(int i=0;i<size||i<A.size;i++){
            int tmp = 0;
            tmp = digit[i]+A.digit[i]+carry;
            carry = tmp/10000;
            ret.digit[ret.size++] = tmp%10000;
        }
        return ret;
    }
}a,b,ans;

string str1,str2;

int main()
{
    cin>>str1>>str2;
    a.set(str1);b.set(str2);
    ans = a+b;
    ans.output();
}
