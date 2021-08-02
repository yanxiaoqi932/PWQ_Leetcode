/*��һ��ͼ�еĲ��鼯����*/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int numCity,numRoad;  //������Ŀ���·����
int tree[1000];

int findroot(int x)
{
    if(tree[x] == -1){
        return x;
    }else{
        int tmp = findroot(tree[x]);
        tree[x] = tmp;   //·��ѹ��
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
���ԣ�
5 2
1 2
3 5
�����
2
*/
