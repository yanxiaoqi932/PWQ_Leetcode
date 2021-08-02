#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
using namespace std;

string num;  //数字
int remain;  //余数
stack<int> st;  //存储二进制结果，并倒序输出

//一个string类型的数字除以2
void divide()
{
    int remain = 0;  //每一级除2的余数
    for(int i=0;i<num.length();i++){
        int tmp = (num[i]-'0'+remain*10)%2;
        num[i] = (num[i]-'0'+remain*10)/2 + '0';
        remain = tmp;
    }
    while(num[0] == '0')  //除以二后最高位为0
    {
        num.erase(0,1);
    }
}

int main()
{
    while(cin>>num){
        while(!num.empty()){
            int remain = (num[num.length()-1]-'0')%2;
            st.push(remain);
            divide();
        }
        while(!st.empty()){
            cout<<st.top();
            st.pop();
        }
        cout<<endl;
    }
    return 0;
}
