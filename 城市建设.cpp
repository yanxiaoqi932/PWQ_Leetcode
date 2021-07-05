#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int n,m;
int ferry[10001];
int tree[10001] = {-1};
struct edge{
    int x;
    int y;
    int len;
    int a,b;
    bool mark = false;
}road[100001];
int consume;
int ferrymark[10001];

bool cmp(edge e1,edge e2)
{
    return e1.len<e2.len;  //递增序列
}

int findroot(int x)
{
    if(tree[x]==-1)
        return x;
    else{
        int tmp = findroot(tree[x]);
        tree[x] = tmp;
        return tmp;
    }
}

int main()
{
    memset(tree,-1,sizeof(tree));
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>road[i].x>>road[i].y>>road[i].len;
    }
    for(int i=1;i<=n;i++){
        cin>>ferry[i];
    }
    sort(road+1,road+m+1,cmp);

    for(int i=1;i<=m;i++){
        int a = findroot(road[i].x);
        int b = findroot(road[i].y);
        if(a!=b){
            tree[a] = b;
            road[i].a = a;road[i].b = b;
            consume += road[i].len;
            road[i].mark = true;
            //cout<<road[i].x<<" "<<road[i].y<<endl;
        }
    }
    for(int i=1;i<=m;i++){
        if(road[i].len>(ferry[road[i].x] + ferry[road[i].y]) && ferry[road[i].x]!=-1 && ferry[road[i].y]!=-1 && road[i].mark){  //改为渡口可能更便宜
            //cout<<road[i].x<<" "<<road[i].y<<endl;
            int chajia;
            if(ferrymark[road[i].x] && !ferrymark[road[i].y]){
                chajia = road[i].len - (ferry[road[i].y]);
            }else if(ferrymark[road[i].y] && !ferrymark[road[i].x]){
                chajia = road[i].len - (ferry[road[i].x]);
            }else{
                chajia = road[i].len - (ferry[road[i].x] + ferry[road[i].y]);
            }
            ferrymark[road[i].x] = ferrymark[road[i].y] = true;
            consume-=chajia;
        }
    }
    cout<<consume;
}
/*
6 6
1 2 1
2 3 1
3 4 10
4 5 10
5 6 1
6 1 10
10 10 3 1 1 1
*/
