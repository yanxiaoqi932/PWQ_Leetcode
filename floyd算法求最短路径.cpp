/*floyd�㷨�����·��*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

#define inf 10000

int nump,nume; //·������·��
int d[101][101][101]; //d[k][i][j]�����i�㵽j�㣬�м�ֻ�������ǰk����ʱ�����·������
int main()
{
    memset(d,inf,sizeof(d));  //����·����ʼ��

    while(scanf("%d %d",&nump,&nume)!=EOF && nump!=0 && nume!=0){
        //��a����a������Ϊ0
        for(int i=1;i<=nump;i++){
            for(int k=0;k<=nump;k++){
                d[k][i][i] = 0;
            }
        }
        //��ʼ������֮�����
        for(int i=1;i<=nume;i++){
            int a,b,len;
            scanf("%d %d %d",&a,&b,&len);
            d[0][a][b] = len; d[0][b][a] = len;
        }

        for(int k=1;k<=nump;k++){
            for(int i=1;i<=nump;i++){
                for(int j=1;j<=nump;j++){
                    //��������ǰk-1���㣬i��j֮�䲻���ھ�����k��·��ʱ
                    if(d[k-1][i][k]==inf || d[k-1][k][j]==inf){
                        d[k][i][j] = d[k-1][i][j];
                    }
                    //��������ǰk-1���㣬i��j֮�䲻����·�������ߴ���·���������ڼ����k�����·��ʱ
                    else if((d[k-1][i][j]==inf) || (d[k-1][i][k]+d[k-1][k][j] < d[k-1][i][j])){
                        d[k][i][j] = d[k-1][i][k]+d[k-1][k][j];
                    }
                    //�������������������ǰk-1���㣬����·����С�ڼ����k�����·��
                    else{
                        d[k][i][j] = d[k-1][i][j];
                    }
                }
            }
        }
        cout<<d[nump][1][nump]<<endl;
    }
    return 0;
}
/*
����ʾ����
3 3
1 2 5
2 3 5
3 1 2
�����
2
*/
