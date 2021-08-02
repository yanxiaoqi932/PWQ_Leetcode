/*利用素数筛法求出一段范围内的素数*/
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

int num[10005];  //非素数为1，素数为0
int sushu[3000];
int numSu = 0;  //记录素数个数


//核心代码：素数筛法
void init()
{
    for(int i=2;i<=10001;i++){
        if(num[i] == 1) continue;  //不是素数，下一个
        else{   //若没有被标记为1，则说明它是素数，不需要专门验证
            sushu[++numSu] = i;
            //得到新素数后，将更多未知的数确定为非素数
            for(int j=i*i;j<=10002;j+=i){
                num[j] = 1;
            }
        }
    }
}

int main()
{
    init();  //得到1~10000之间所有素数，注意：1不是素数！！！
    int x;
    scanf("%d",&x);
    for(int i=1;i<=numSu;i++){
        if(sushu[i]<x && sushu[i]%10==1){
            cout<<sushu[i]<<" ";
        }
    }
    return 0;
}
