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
        return x.num>y.num;    //降序排列（不重载时，sort函数默认升序）
    }else{
        //strcmp只能比较char数组，不能比较string，
        //当x.name>y.name，strcmp返回1
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
