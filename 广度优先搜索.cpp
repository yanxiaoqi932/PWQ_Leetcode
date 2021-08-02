/*广度优先搜索：利用队列，记录每个状态，并由一个状态不断扩展出新状态*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int mark[100][100][100];  //记录每个状态是否被标记，已被标记则说明达到了最小步数，不需要操作
struct state
{
    int x,y,z;  //x,y,z各代表三个杯子中所含的饮料量
    int bushu;  //达到这个状态所需的最小步数
};
queue<state> q;  //记录每个状态的队列

void AtoB(int &a,int va,int &b,int vb)  //把A中饮料倒给B,A杯体积为va，B杯体积为vb
{
    if(vb-b>=a){  //b中饮料可以容纳所有a
        b = b+a;
        a = 0;
    }else{  //b中饮料无法容纳所有a
        a = a-(vb-b);
        b = vb;
    }
}

int main()
{
    int s,n,m;
    while(cin>>s>>n>>m && s!=0 && n!=0 && m!=0){
        int flag = 0;  //如果答案为肯定，则flag为1
        int goodbushu = 0;  //若为肯定，则输出最优步数
        while(!q.empty()) q.pop();
        state a;
        a.x = s;a.y = 0;a.z = 0;a.bushu = 0;
        mark[s][n][m] = 1;
        q.push(a);

        while(!q.empty()){
            if(s%2!=0) break;  //奇数直接排除

            state now = q.front();q.pop();
            int nows,nown,nowm;
            state tmp;  //记录中间状态

            //从一个状态扩展六个新状态，并且探查有没有状态满足题设最终条件
            //s倒n
            nows = now.x;nown = now.y;nowm = now.z;
            AtoB(nows,s,nown,n);
            if(mark[nows][nown][nowm]==false){
                mark[nows][nown][nowm] = true;
                tmp.x=nows;tmp.y=nown;tmp.z=nowm;tmp.bushu=now.bushu+1;
                q.push(tmp);
                if((nowm==s/2&&nown==s/2) || (nowm==s/2&&nows==s/2)||(nown==s/2&&nows==s/2)){
                    flag = 1;goodbushu = tmp.bushu;break;
                }
            }
            //n倒s
            nows = now.x;nown = now.y;nowm = now.z;
            AtoB(nown,n,nows,s);
            if(mark[nows][nown][nowm]==false){
                mark[nows][nown][nowm] = true;
                tmp.x=nows;tmp.y=nown;tmp.z=nowm;tmp.bushu=now.bushu+1;
                q.push(tmp);
                if((nowm==s/2&&nown==s/2) || (nowm==s/2&&nows==s/2)||(nown==s/2&&nows==s/2)){
                    flag = 1;goodbushu = tmp.bushu;break;
                }
            }
            //s倒m
            nows = now.x;nown = now.y;nowm = now.z;
            AtoB(nows,s,nowm,m);
            if(mark[nows][nown][nowm]==false){
                mark[nows][nown][nowm] = true;
                tmp.x=nows;tmp.y=nown;tmp.z=nowm;tmp.bushu=now.bushu+1;
                q.push(tmp);
                if((nowm==s/2&&nown==s/2) || (nowm==s/2&&nows==s/2)||(nown==s/2&&nows==s/2)){
                    flag = 1;goodbushu = tmp.bushu;break;
                }
            }
            //m倒s
            nows = now.x;nown = now.y;nowm = now.z;
            AtoB(nowm,m,nows,s);
            if(mark[nows][nown][nowm]==false){
                mark[nows][nown][nowm] = true;
                tmp.x=nows;tmp.y=nown;tmp.z=nowm;tmp.bushu=now.bushu+1;
                q.push(tmp);
                if((nowm==s/2&&nown==s/2) || (nowm==s/2&&nows==s/2)||(nown==s/2&&nows==s/2)){
                    flag = 1;goodbushu = tmp.bushu;break;
                }
            }
            //n倒m
            nows = now.x;nown = now.y;nowm = now.z;
            AtoB(nown,n,nowm,m);
            if(mark[nows][nown][nowm]==false){
                mark[nows][nown][nowm] = true;
                tmp.x=nows;tmp.y=nown;tmp.z=nowm;tmp.bushu=now.bushu+1;
                q.push(tmp);
                if((nowm==s/2&&nown==s/2) || (nowm==s/2&&nows==s/2)||(nown==s/2&&nows==s/2)){
                    flag = 1;goodbushu = tmp.bushu;break;
                }
            }
            //m倒n
            nows = now.x;nown = now.y;nowm = now.z;
            AtoB(nowm,m,nown,n);
            if(mark[nows][nown][nowm]==false){
                mark[nows][nown][nowm] = true;
                tmp.x=nows;tmp.y=nown;tmp.z=nowm;tmp.bushu=now.bushu+1;
                q.push(tmp);
                if((nowm==s/2&&nown==s/2) || (nowm==s/2&&nows==s/2)||(nown==s/2&&nows==s/2)){
                    flag = 1;goodbushu = tmp.bushu;break;
                }
            }
        }
        if(flag!=1){
            cout<<"NO"<<endl;
        }else{
            cout<<goodbushu<<endl;
        }
    }
}
/*
输入：
4 1 3
输出：
3
*/
