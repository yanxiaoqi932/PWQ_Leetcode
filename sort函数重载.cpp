#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

struct name_num{
    char name[100];
    int num;
}str[10];
bool cmp(name_num x,name_num y){
    if(x.num!=y.num){
        return x.num>y.num;    //�������У�������ʱ��sort����Ĭ������
    }else{
        //strcmpֻ�ܱȽ�char���飬���ܱȽ�string��
        //��x.name>y.name��strcmp����1
        int tmp = strcmp(x.name,y.name);
        if(tmp!=0){
            return tmp;
        }
    }
}
int main()
{
    for(int i=0;i<5;i++){
        scanf("%s%d",str[i].name,&str[i].num);
    }
    sort(str,str+5,cmp);
    for(int i=0;i<5;i++){
        printf("%s  %d\n",str[i].name,str[i].num);
    }
    return 0;
}
