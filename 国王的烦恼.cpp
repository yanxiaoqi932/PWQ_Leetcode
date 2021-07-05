#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int numisland,numbridge;
struct road{
    int x;
    int y;
    int len;

}arr[100005];
int protestday;
int tree[10005];

bool cmp(road a1,road a2){  //�ݼ�
    return a1.len>a2.len;
}

int findroot(int x){
    if(tree[x]==-1){
        return x;
    }else{
        int root = findroot(tree[x]);
        tree[x] = root;    //ѹ��·��
        return root;
    }
}

int main()
{
    memset(tree,-1,sizeof(tree));
    cin>>numisland>>numbridge;
    for(int i=0;i<numbridge;i++){
        cin>>arr[i].x>>arr[i].y>>arr[i].len;
    }
    sort(arr,arr+numbridge,cmp);  //�ݼ�����

    for(int i=0;i<numbridge;i++){   //�������������
        int a = findroot(arr[i].x);
        int b = findroot(arr[i].y);
        //cout<<a<<" "<<b<<endl;
        if(a!=b){
            tree[b] = a;
            protestday = arr[i].len;
            //cout<<protestday<<endl;
        }
    }

    cout<<arr[0].len - protestday + 1;
}
/*
4 4
1 2 2
1 3 1
2 3 1
3 4 3
*/
