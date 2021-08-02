/*贪心算法之电视节目*/
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
        for(int i=1;i<=n-1;i++){     //根据节目结束时间从小到大重新排列
            for(int j=1;j<=n-i;j++){
                if(pro[j].en>pro[j+1].en){
                    item tmp = pro[j];
                    pro[j] = pro[j+1];
                    pro[j+1] = tmp;
                }
            }
        }
        //贪心算法：每次选取最小的结束时间，就可以得到最多的节目
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
实验：
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
