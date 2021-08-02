#include <iostream>
#include <stdio.h>
using namespace std;

char maze[8][8];  //��¼��ͼ
int mark[8][8];  //dfs����ʱ���ڱ��
int n,m,time;  //�����ʱ��
int srow,scol,drow,dcol;  //�����յ�
int success;  //��¼�Ƿ�ɹ�

//�����������,����������������ͷ����ѡ�������Ѿ���������·�ߣ�
//��Ϊ�Ѿ�����һ��if���ѡ����ˣ�����dfs�ĵݹ�����
void dfs(int x,int y,int t)
{
    mark[x][y] = true;  //����λ�ñ�ǣ������ظ������õ�
    if(maze[x][y] == 'D' && t<=time){  //������û�г�ʱ
        success = true;
        return;
    }else if(maze[x][y] == 'X'|| t>time){ //����ǽ���߳�ʱ
        return;
    }else if(t<=time-1){  //δ�������һ�����ᳬʱ
        if(x+1<=n-1 && mark[x+1][y]!=true){  //û��Խ����δ�����
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
        success = 0;  //��־λ����
        for(int i=0;i<8;i++){  //��ͼ�������־�������
            for(int j=0;j<8;j++){
                maze[i][j] = 0;
                mark[i][j] = 0;
            }
        }

        for(int i=0;i<n;i++){
            cin>>maze[i];
            //��ȡ�������
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
���룺
4 4 5
S.X.
..X.
..XD
....
3 4 5
S.X.
..X.
...D

�����
NO
YES
*/
