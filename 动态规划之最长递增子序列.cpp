/*�����������⣺�������������*/
#include <iostream>
#include <stdio.h>
using namespace std;

int num;
int n[1000];
int ans[1000];
int maxnum = 0;
int main()
{
    while(cin>>num){
        for(int i=0;i<1000;i++){
            ans[i] = 1;   //Ĭ����С�����������г���Ϊ1
        }

        for(int i=1;i<=num;i++){
            cin>>n[i];
            for(int j=i-1;j>=1;j--){
                if(n[j]>=n[i]){
                    ans[i] = ans[j]+1;

                    if(ans[i]>maxnum){   //�ҳ����Ĳ�����������
                        maxnum = ans[i];
                    }
                    break;
                }
            }
        }
        cout<<maxnum<<endl;

    }
}

/*
8
300 207 155 300 299 170 158 65
*/
