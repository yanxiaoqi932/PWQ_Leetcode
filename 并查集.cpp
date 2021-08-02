/*求一个图中的并查集个数*/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int numCity,numRoad;  //城镇数目与道路条数
int tree[1000];

int findroot(int x)
{
    if(tree[x] == -1){
        return x;
    }else{
        int tmp = findroot(tree[x]);
        tree[x] = tmp;   //路径压缩
        return tmp;
    }
}

int main()
{
    memset(tree,-1,sizeof(tree));
    int ans = 0;
    cin>>numCity>>numRoad;
    for(int i=1;i<=numRoad;i++){
        int a,b;
        cin>>a>>b;
        a = findroot(a);
        b = findroot(b);
        if(a!=b){
            tree[a] = b;
        }
    }
    for(int i=1;i<=numCity;i++){
        if(tree[i] == -1){
            ans++;
        }
    }
    cout<<ans-1;
}

/*
测试：
5 2
1 2
3 5
输出：
2
*/
