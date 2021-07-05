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
//尼姆博弈
//将和尚两两分成一组，一组内两和尚之间的台阶即为堆中的个数
int isT(){
    int sum = 0;
    for(int i=0;i<n-1;i+=2){
        sum^=(whe[i+1]-whe[i]-1);
    }
    return sum==0; //如果为零，说明该情况下对手处于奇异局势
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
    for(int monk=0;monk<n-1;monk++){  //既可以移动左边和尚，也可以移动右边和尚，堆可以增大也可以减小
        for(int dis=0;dis<=whe[monk+1]-whe[monk]-1;dis++){
            whe[monk]+=dis;  //做出对应移动
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
