/*����<queue>��С���ѣ������������������С��Ȩ·���ͣ��Լ���Ӧ�Ķ�����*/
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int ,vector<int>,greater<int> > Q;//����һ��С����Q�ķ�ʽ
//priority_queue<int> Q;//����һ���󶥶�Q�ķ�ʽ
int n = 0;int ans;
int main()
{
    while(scanf("%d",&n)!=EOF){
        while(!Q.empty()) Q.pop();

        for(int i=1;i<=n;i++){
            int weight;
            scanf("%d",&weight);
            Q.push(weight);
        }

        while(Q.size()>1){
            int a,b;
            a = Q.top();Q.pop();
            b = Q.top();Q.pop();
            ans+=(a+b);
            Q.push(a+b);
        }
        cout<<ans<<endl;
    }
}
/*
ʾ����
5
1 2 2 5 9
�����37
*/
