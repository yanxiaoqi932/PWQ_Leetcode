#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

long long int suan[205][200005];  //在某个时间点某计算机算力
long long int n,m;  //计算机数目与任务数
int main()
{
    cin>>n>>m;
    for(long long int i=1;i<=n;i++){
        long long int tmp;cin>>tmp;
        for(long long int j=1;j<=m;j++){
            suan[j][i] = tmp;
        }
    }
    for(long long int i=1;i<=m;i++){
        long long int wuyong ,bianhao ,shijian,suanli;
        cin>>wuyong>>bianhao>>shijian>>suanli;
        if(suan[i][bianhao] >= suanli){
            cout<<suan[i][bianhao]-suanli;
            for(long long int x=i;x<=i+shijian-1;x++){
                suan[x][bianhao]-=suanli;
            }
        }else{
            cout<<-1;
        }
        if(i!=m){
            cout<<endl;
        }
    }
    return 0;
}
