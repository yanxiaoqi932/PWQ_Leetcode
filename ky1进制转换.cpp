#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
using namespace std;

string num;  //����
int remain;  //����
stack<int> st;  //�洢�����ƽ�������������

//һ��string���͵����ֳ���2
void divide()
{
    int remain = 0;  //ÿһ����2������
    for(int i=0;i<num.length();i++){
        int tmp = (num[i]-'0'+remain*10)%2;
        num[i] = (num[i]-'0'+remain*10)/2 + '0';
        remain = tmp;
    }
    while(num[0] == '0')  //���Զ������λΪ0
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
