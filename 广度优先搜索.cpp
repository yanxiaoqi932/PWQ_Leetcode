/*����������������ö��У���¼ÿ��״̬������һ��״̬������չ����״̬*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int mark[100][100][100];  //��¼ÿ��״̬�Ƿ񱻱�ǣ��ѱ������˵���ﵽ����С����������Ҫ����
struct state
{
    int x,y,z;  //x,y,z����������������������������
    int bushu;  //�ﵽ���״̬�������С����
};
queue<state> q;  //��¼ÿ��״̬�Ķ���

void AtoB(int &a,int va,int &b,int vb)  //��A�����ϵ���B,A�����Ϊva��B�����Ϊvb
{
    if(vb-b>=a){  //b�����Ͽ�����������a
        b = b+a;
        a = 0;
    }else{  //b�������޷���������a
        a = a-(vb-b);
        b = vb;
    }
}

int main()
{
    int s,n,m;
    while(cin>>s>>n>>m && s!=0 && n!=0 && m!=0){
        int flag = 0;  //�����Ϊ�϶�����flagΪ1
        int goodbushu = 0;  //��Ϊ�϶�����������Ų���
        while(!q.empty()) q.pop();
        state a;
        a.x = s;a.y = 0;a.z = 0;a.bushu = 0;
        mark[s][n][m] = 1;
        q.push(a);

        while(!q.empty()){
            if(s%2!=0) break;  //����ֱ���ų�

            state now = q.front();q.pop();
            int nows,nown,nowm;
            state tmp;  //��¼�м�״̬

            //��һ��״̬��չ������״̬������̽����û��״̬����������������
            //s��n
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
            //n��s
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
            //s��m
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
            //m��s
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
            //n��m
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
            //m��n
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
���룺
4 1 3
�����
3
*/
