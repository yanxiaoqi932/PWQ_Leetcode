/*����kruscal�㷨�õ���С�����������������б�Ȩ����С����*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int nump;  //��ׯ��Ŀ
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

        sort(e,e+numedge,cmp);  //�������߰��մ�С�����˳������

        for(int i=0;i<numedge;i++){
            int a = e[i].a;
            int b = e[i].b;
            a = findroot(a);
            b = findroot(b);
            if(a!=b){  //����ߵ������㲻��ͬһ�����鼯�У�������
                tree[a] = b;
                ans+=e[i].len;
            }
        }

        cout<<ans<<endl;
    }
}

/*
����ʾ����
3
1 2 1
1 3 2
2 3 4
�����
3
*/
