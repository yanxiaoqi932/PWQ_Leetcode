/*利用kruscal算法得到最小生成树，即生成树中边权和最小的树*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int nump;  //村庄数目
struct edge{
    int a,b;
    int len;
}e[200];
int tree[200];
int ans;

int findroot(int x)
{
    if(tree[x]==-1){
        return x;
    }else{
        int tmp = findroot(tree[x]);
        tree[x] = tmp;
        return tmp;
    }
}

bool cmp(edge a,edge b)
{
    return a.len<b.len;
}

int main()
{
    memset(tree,-1,sizeof(tree));

    while(scanf("%d",&nump)!=EOF && nump!=0){
        int numedge = nump * (nump-1) /2;
        int a=0; int b=0; int len=0;
        for(int i=0;i<numedge;i++){
            scanf("%d %d %d",&a,&b,&len);
            e[i].a = a;
            e[i].b = b;
            e[i].len = len;
        }

        sort(e,e+numedge,cmp);  //将各条边按照从小到大的顺序排列

        for(int i=0;i<numedge;i++){
            int a = e[i].a;
            int b = e[i].b;
            a = findroot(a);
            b = findroot(b);
            if(a!=b){  //如果边的两个点不在同一个并查集中，则连接
                tree[a] = b;
                ans+=e[i].len;
            }
        }

        cout<<ans<<endl;
    }
}

/*
输入示例：
3
1 2 1
1 3 2
2 3 4
输出：
3
*/
