/*̰���㷨֮���ӽ�Ŀ*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct item{
    int st;
    int en;
}pro[200];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0){break;}
        for(int i=1;i<=n;i++){
            scanf("%d %d",&pro[i].st,&pro[i].en);
        }
        for(int i=1;i<=n-1;i++){     //���ݽ�Ŀ����ʱ���С������������
            for(int j=1;j<=n-i;j++){
                if(pro[j].en>pro[j+1].en){
                    item tmp = pro[j];
                    pro[j] = pro[j+1];
                    pro[j+1] = tmp;
                }
            }
        }
        //̰���㷨��ÿ��ѡȡ��С�Ľ���ʱ�䣬�Ϳ��Եõ����Ľ�Ŀ
        int num_item = 0;int end_time = 0;
        for(int i=1;i<=n;i++){
            if(pro[i].st>=end_time){
                end_time = pro[i].en;
                num_item++;
            }
        }
        cout<<num_item<<endl;
    }

}
/*
ʵ�飺
12
1 3
3 4
0 7
3 8
15 19
15 20
10 15
8 18
6 12
5 10
4 14
2 9
*/
