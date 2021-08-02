/*采用<queue>的小顶堆，求哈夫曼树——即最小带权路径和，以及对应的二叉树*/
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int ,vector<int>,greater<int> > Q;//声明一个小顶堆Q的方式
//priority_queue<int> Q;//声明一个大顶堆Q的方式
int n = 0;int ans;
int main()
{
    while(scanf("%d",&n)!=EOF){
        while(!Q.empty()) Q.pop();

        for(int i=1;i<=n;i++){
            int weight;
            scanf("%d",&weight);
            Q.push(weight);
        }

        while(Q.size()>1){
            int a,b;
            a = Q.top();Q.pop();
            b = Q.top();Q.pop();
            ans+=(a+b);
            Q.push(a+b);
        }
        cout<<ans<<endl;
    }
}
/*
示例：
5
1 2 2 5 9
输出：37
*/
