/*������ͬ���ƷǸ�������ת����a����ת10���ƣ�10����תb����*/
#include <iostream>
#include <stdio.h>
#include <stack>
#include <math.h>
#include <string.h>
using namespace std;

int a,b;
string str;

stack<int> result;
int main()
{
    cin>>a>>str>>b;
    int tmp = 0;

    //a����ת10����
    for(int i=0;i<=str.length()-1;i++){
        if(str[i]>='A'&&str[i]<='Z'){
            tmp += (10+str[i]-'A') * pow(a,str.length()-1-i);
        }
        else if(str[i]>='a' && str[i]<='z'){
            tmp += (10+str[i]-'a') * pow(a,str.length()-1-i);
        }
        else{
            tmp += (str[i]-'0') * pow(a,str.length()-1-i);
        }
    }

    //10����תb����
    do{
        int m = tmp%b;
        tmp = tmp/b;
        result.push(m);
    }while(tmp != 0);

    //�������
    while(!result.empty()){
        cout<<result.top();
        result.pop();
    }
    return 0;
}
