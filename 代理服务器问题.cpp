#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

queue<int> point;  //队列记录代理服务器与服务器地址的重合情况
vector<int> duan[1002];   //记录每一个代理服务器出现的各个位置
int pend[10000];  //记录每个代理服务器上一个重合的点的位置
string agenSer[1002];  //代理服务器地址集合
string Ser[5002];  //服务器地址集合
int ans;
int n,m;

int main()
{
    while(cin>>n){
        ans = 0;
        for(int i=1;i<=n;i++){
            cin>>agenSer[i];
        }

        cin>>m;
        for(int i=1;i<=m;i++){
            cin>>Ser[i];
            ////发现重合并记录情况
            for(int j=1;j<=n;j++){
                if(Ser[i]==agenSer[j]){
                    point.push(j);break;
                }
            }
        }


    //开始分段
    int k=1; int s = point.size();   //点的总数
    while(!point.empty()){
        duan[point.front()].push_back(k);   //代理服务器地址point.front()
        point.pop();k++;
    }
    for(int i=1;i<=n;i++){
        duan[i].push_back(10000);
    }
    int point_max = 0; int duan_max = 0;
    while(point_max<s){
        int flag = 0;
        for(int i=1;i<=n;i++){
            if(duan[i][0] > point_max && i!=duan_max){
                point_max = duan[i][0];
                duan_max = i;flag = 1;
            }
        }
        ans++;
        if(flag){
            flag = 0;
        }else{
            ans=-1;break;  //无法继续更新
        }
        //删除所有小于等于point_max的点
        for(int i=1;i<=n;i++){
            vector<int>::iterator itor;  //itor就是vector中迭代的指针
            for(itor=duan[i].begin();itor!=duan[i].end();){
                if(*itor<=point_max){
                    duan[i].erase(itor);itor++;
                }else{
                    break;
                }
            }
        }

    }
    cout<<ans<<endl;
    }

}
/*
1
17.151.164.96
10
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
*/
