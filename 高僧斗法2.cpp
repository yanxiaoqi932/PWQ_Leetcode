#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
char ch;
string str;
int bianhao;
int whe[1001];
int n;
//��ķ����
//�����������ֳ�һ�飬һ����������֮���̨�׼�Ϊ���еĸ���
int isT(){
    int sum = 0;
    for(int i=0;i<n-1;i+=2){
        sum^=(whe[i+1]-whe[i]-1);
    }
    return sum==0; //���Ϊ�㣬˵��������¶��ִ����������
}

int main(){
    while(1){
        ch = cin.get();
        if(ch==' '){
            bianhao = std::atoi(str.c_str());
            whe[n++] = bianhao;
            str="";
        }else if(ch=='\n'){
            bianhao = std::atoi(str.c_str());
            whe[n++] = bianhao;
            str="";
            break;
        }else{
            str+=ch;
        }
    }
    for(int monk=0;monk<n-1;monk++){  //�ȿ����ƶ���ߺ��У�Ҳ�����ƶ��ұߺ��У��ѿ�������Ҳ���Լ�С
        for(int dis=0;dis<=whe[monk+1]-whe[monk]-1;dis++){
            whe[monk]+=dis;  //������Ӧ�ƶ�
            if(isT()){
                cout<<whe[monk]-dis<<" "<<whe[monk];
                return 0;
            }
            whe[monk]-=dis;
        }
    }
    cout<<-1;
    return 0;
}
