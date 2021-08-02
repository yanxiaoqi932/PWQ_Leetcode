#include <iostream>
#include <stdio.h>
using namespace std;

char maze[8][8];  //记录地图
int mark[8][8];  //dfs遍历时用于标记
int n,m,time;  //长宽和时间
int srow,scol,drow,dcol;  //起点和终点
int success;  //记录是否成功

//深度优先搜索,深度优先搜索不会回头重新选择那条已经被抛弃的路线，
//因为已经在上一个if语句选择过了，所以dfs的递归会有穷尽
void dfs(int x,int y,int t)
{
    mark[x][y] = true;  //给该位置标记，避免重复经过该点
    if(maze[x][y] == 'D' && t<=time){  //到达且没有超时
        success = true;
        return;
    }else if(maze[x][y] == 'X'|| t>time){ //遇到墙或者超时
        return;
    }else if(t<=time-1){  //未到达，且下一步不会超时
        if(x+1<=n-1 && mark[x+1][y]!=true){  //没有越界且未被标记
            dfs(x+1,y,t+1);
            if(success == true) return;
            mark[x+1][y] = 0;

        }
        if(x-1>=0 && mark[x-1][y]!=true){
            dfs(x-1,y,t+1);
            if(success == true) return;
            mark[x-1][y] = 0;

        }
        if(y+1<=m-1 && mark[x][y+1]!=true){
            dfs(x,y+1,t+1);
            if(success == true) return;
            mark[x][y+1] = 0;

        }
        if(y-1>=0 && mark[x][y-1]!=true){
            dfs(x,y-1,t+1);
            if(success == true) return;
            mark[x][y-1] = 0;

        }
    }
}

int main()
{
    while(cin>>n>>m>>time && n!=0 && m!=0 && time!=0){
        success = 0;  //标志位归零
        for(int i=0;i<8;i++){  //地图与遍历标志数组归零
            for(int j=0;j<8;j++){
                maze[i][j] = 0;
                mark[i][j] = 0;
            }
        }

        for(int i=0;i<n;i++){
            cin>>maze[i];
            //获取起点坐标
            for(int j=0;j<m;j++){
                if(maze[i][j] == 'S'){
                    srow=i;scol=j;
                }
            }
        }

        dfs(srow,scol,0);
        if(success == true){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}

/*
输入：
4 4 5
S.X.
..X.
..XD
....
3 4 5
S.X.
..X.
...D

输出：
NO
YES
*/
