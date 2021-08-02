/*dijstra�㷨�����·��*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

#define inf 100000

int nump,nume;  //�����ͱ���
int mark[1001]; //�Ѿ������1����i����С·�������еĵ�
int dis[1001];  //��1����i֮�����С����
int cost[1001];  //��1����i֮����Ҫ����С����
int st,en;  //�����յ�

struct edge
{
    int next;  //��һ����
    int len;  //�������ӵı߳�
    int cost;  //�ߵĻ���
};

vector<edge> e[1001];

int main()
{
    //��ʼ����־����;������飬Ĭ��dis��cost���������
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
            //����ͼ����a�͵�b���ཫ�Է�����Ϣ�����Լ����ڵ㼯����
            edge x;
            x.next = b;x.len = d;x.cost = p;e[a].push_back(x);
            x.next = a;e[b].push_back(x);
        }

        scanf("%d %d",&st,&en);
        mark[st] = true;
        dis[st] = 0;
        cost[st] = 0;

        int newp = st;  //��ʼʱ���Ƚ������Ϊ�¼����

        //��Ѱnump�֣��ܹ���֤ÿ���㶼�лᱻ��Ϊnewp��ʱ��
        for(int i=1;i<nump;i++){
            //���¼���ĵ㿪ʼ��Ѱ��Ѱ�������ڵ㵽������̾���
            for(int j=0;j<e[newp].size();j++){
                int next = e[newp][j].next;
                int len = e[newp][j].len;
                int co = e[newp][j].cost;
                //dis[next]����������û�б���ǣ����µ�dis������̣����߾�����ͬ���ǻ��Ѹ���
                if(mark[next] == true) continue;
                if(dis[next]>dis[newp]+len || (dis[next]==dis[newp]+len && cost[next]>cost[newp]+co)){
                    dis[next] = dis[newp]+len;
                    cost[next] = cost[newp]+co;
                }
            }

            //�ҳ���ǰ�������Ѿ����ȷ���˵�dis[i]֮�⣬������е����ľ�����С�ĵ�,
            //�����̾���ĵ�����µļ���㣬����������̾����Ѿ�ȷ�ϣ���mark������
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
�������ݣ�
3 2
1 2 5 6
2 3 4 5
1 3
�����
9 11
*/

