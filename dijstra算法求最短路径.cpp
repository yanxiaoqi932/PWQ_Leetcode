/*dijstra算法求最短路径*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

#define inf 100000

int nump,nume;  //点数和边数
int mark[1001]; //已经加入点1到点i的最小路径集合中的点
int dis[1001];  //点1到点i之间的最小距离
int cost[1001];  //点1到点i之间需要的最小费用
int st,en;  //起点和终点

struct edge
{
    int next;  //下一个点
    int len;  //两点连接的边长
    int cost;  //边的花费
};

vector<edge> e[1001];

int main()
{
    //初始化标志数组和距离数组，默认dis和cost都是无穷大
    for(int i=0;i<=1000;i++){
        mark[i] = false;
        dis[i] = inf;
        cost[i] = inf;
    }

    while(scanf("%d %d",&nump,&nume)!=EOF && nump!=0 && nume!=0){
        for(int i=1;i<=nume;i++){
            e[i].clear();
        }
        for(int i=1;i<=nume;i++){
            int a,b,d,p;
            scanf("%d %d %d %d",&a,&b,&d,&p);
            //无向图，点a和点b互相将对方的信息接入自己的邻点集合中
            edge x;
            x.next = b;x.len = d;x.cost = p;e[a].push_back(x);
            x.next = a;e[b].push_back(x);
        }

        scanf("%d %d",&st,&en);
        mark[st] = true;
        dis[st] = 0;
        cost[st] = 0;

        int newp = st;  //初始时，先将起点作为新加入点

        //搜寻nump轮，能够保证每个点都有会被设为newp的时刻
        for(int i=1;i<nump;i++){
            //从新加入的点开始搜寻，寻找它的邻点到起点的最短距离
            for(int j=0;j<e[newp].size();j++){
                int next = e[newp][j].next;
                int len = e[newp][j].len;
                int co = e[newp][j].cost;
                //dis[next]更新条件：没有被标记，且新的dis距离更短，或者距离相同但是花费更少
                if(mark[next] == true) continue;
                if(dis[next]>dis[newp]+len || (dis[next]==dis[newp]+len && cost[next]>cost[newp]+co)){
                    dis[next] = dis[newp]+len;
                    cost[next] = cost[newp]+co;
                }
            }

            //找出当前，除了已经标记确定了的dis[i]之外，其余点中到起点的距离最小的点,
            //这个最短距离的点就是新的加入点，它到起点的最短距离已经确认，被mark数组标记
            int minlen = inf; int minp;
            for(int i=1;i<=nump;i++){
                if(mark[i]==true) continue;
                if(dis[i]<minlen){
                    minlen = dis[i];
                    minp = i;
                }
            }
            mark[minp] = true;
            newp = minp;
        }
        cout<<dis[en]<<" "<<cost[en]<<endl;
    }
    return 0;
}
/*
输入数据：
3 2
1 2 5 6
2 3 4 5
1 3
输出：
9 11
*/

