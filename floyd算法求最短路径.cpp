/*floyd算法求最短路径*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

#define inf 10000

int nump,nume; //路口数和路数
int d[101][101][101]; //d[k][i][j]代表从i点到j点，中间只允许加入前k个点时的最短路径长度
int main()
{
    memset(d,inf,sizeof(d));  //所有路径初始化

    while(scanf("%d %d",&nump,&nume)!=EOF && nump!=0 && nume!=0){
        //点a到点a距离总为0
        for(int i=1;i<=nump;i++){
            for(int k=0;k<=nump;k++){
                d[k][i][i] = 0;
            }
        }
        //初始化两点之间距离
        for(int i=1;i<=nume;i++){
            int a,b,len;
            scanf("%d %d %d",&a,&b,&len);
            d[0][a][b] = len; d[0][b][a] = len;
        }

        for(int k=1;k<=nump;k++){
            for(int i=1;i<=nump;i++){
                for(int j=1;j<=nump;j++){
                    //当允许经过前k-1个点，i到j之间不存在经过点k的路径时
                    if(d[k-1][i][k]==inf || d[k-1][k][j]==inf){
                        d[k][i][j] = d[k-1][i][j];
                    }
                    //当允许经过前k-1个点，i到j之间不存在路径；或者存在路径，但大于加入点k后的新路径时
                    else if((d[k-1][i][j]==inf) || (d[k-1][i][k]+d[k-1][k][j] < d[k-1][i][j])){
                        d[k][i][j] = d[k-1][i][k]+d[k-1][k][j];
                    }
                    //其它情况，例如允许经过前k-1个点，存在路径且小于加入点k后的新路径
                    else{
                        d[k][i][j] = d[k-1][i][j];
                    }
                }
            }
        }
        cout<<d[nump][1][nump]<<endl;
    }
    return 0;
}
/*
输入示例：
3 3
1 2 5
2 3 5
3 1 2
输出：
2
*/
