/*拓扑排序：依次找出入度为0的点，最终判断该结构中是否存在有向无环图*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;  //存储入度为0的点
vector<int> edge[501];  //邻接链表
int in[501];  //记录每个点的入度
int nump,nume;  //点数和边数
int zerop;  //记录0入度点的总数，若没有有向无环图，则等于所有点数
int main()
{
    while(scanf("%d %d",&nump,&nume)!=EOF && nump!=0 && nume!=0){
        //对上一轮残留进行清理
        while(!q.empty()){
            q.pop();
        }
        for(int i=0;i<nump;i++){
            edge[i].clear();
        }

        for(int i=0;i<nume;i++){
            int a,b;
            //a指向b，b的入度增加
            scanf("%d %d",&a,&b);
            edge[a].push_back(b);
            in[b]++;
        }
        for(int i=0;i<nump;i++){
            //将入度为0的点加入队列中
            if(in[i] == 0){
                q.push(i);
                zerop++;
            }
        }
        while(!q.empty()){
            int x = q.front();q.pop();
            //将0入度点指向其余点的边删除，被指向的点的入度减1
            for(int i=0;i<edge[x].size();i++){
                int next = edge[x][i];
                in[next]--;
                if(in[next]==0){  //加入新的0入度点
                    q.push(next);
                    zerop++;
                }
            }
        }
        if(zerop == nump){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
/*
示例输入：
3 2
0 1
1 2

2 2
0 1
1 0
输出：
YES
NO
*/
