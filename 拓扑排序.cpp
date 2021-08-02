/*�������������ҳ����Ϊ0�ĵ㣬�����жϸýṹ���Ƿ���������޻�ͼ*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

queue<int> q;  //�洢���Ϊ0�ĵ�
vector<int> edge[501];  //�ڽ�����
int in[501];  //��¼ÿ��������
int nump,nume;  //�����ͱ���
int zerop;  //��¼0��ȵ����������û�������޻�ͼ����������е���
int main()
{
    while(scanf("%d %d",&nump,&nume)!=EOF && nump!=0 && nume!=0){
        //����һ�ֲ�����������
        while(!q.empty()){
            q.pop();
        }
        for(int i=0;i<nump;i++){
            edge[i].clear();
        }

        for(int i=0;i<nume;i++){
            int a,b;
            //aָ��b��b���������
            scanf("%d %d",&a,&b);
            edge[a].push_back(b);
            in[b]++;
        }
        for(int i=0;i<nump;i++){
            //�����Ϊ0�ĵ���������
            if(in[i] == 0){
                q.push(i);
                zerop++;
            }
        }
        while(!q.empty()){
            int x = q.front();q.pop();
            //��0��ȵ�ָ�������ı�ɾ������ָ��ĵ����ȼ�1
            for(int i=0;i<edge[x].size();i++){
                int next = edge[x][i];
                in[next]--;
                if(in[next]==0){  //�����µ�0��ȵ�
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
ʾ�����룺
3 2
0 1
1 2

2 2
0 1
1 0
�����
YES
NO
*/
