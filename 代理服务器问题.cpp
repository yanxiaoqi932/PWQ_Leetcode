#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

queue<int> point;  //���м�¼������������������ַ���غ����
vector<int> duan[1002];   //��¼ÿһ��������������ֵĸ���λ��
int pend[10000];  //��¼ÿ�������������һ���غϵĵ��λ��
string agenSer[1002];  //�����������ַ����
string Ser[5002];  //��������ַ����
int ans;
int n,m;

int main()
{
    while(cin>>n){
        ans = 0;
        for(int i=1;i<=n;i++){
            cin>>agenSer[i];
        }

        cin>>m;
        for(int i=1;i<=m;i++){
            cin>>Ser[i];
            ////�����غϲ���¼���
            for(int j=1;j<=n;j++){
                if(Ser[i]==agenSer[j]){
                    point.push(j);break;
                }
            }
        }


    //��ʼ�ֶ�
    int k=1; int s = point.size();   //�������
    while(!point.empty()){
        duan[point.front()].push_back(k);   //�����������ַpoint.front()
        point.pop();k++;
    }
    for(int i=1;i<=n;i++){
        duan[i].push_back(10000);
    }
    int point_max = 0; int duan_max = 0;
    while(point_max<s){
        int flag = 0;
        for(int i=1;i<=n;i++){
            if(duan[i][0] > point_max && i!=duan_max){
                point_max = duan[i][0];
                duan_max = i;flag = 1;
            }
        }
        ans++;
        if(flag){
            flag = 0;
        }else{
            ans=-1;break;  //�޷���������
        }
        //ɾ������С�ڵ���point_max�ĵ�
        for(int i=1;i<=n;i++){
            vector<int>::iterator itor;  //itor����vector�е�����ָ��
            for(itor=duan[i].begin();itor!=duan[i].end();){
                if(*itor<=point_max){
                    duan[i].erase(itor);itor++;
                }else{
                    break;
                }
            }
        }

    }
    cout<<ans<<endl;
    }

}
/*
1
17.151.164.96
10
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
*/
