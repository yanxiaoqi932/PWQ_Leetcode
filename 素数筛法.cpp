/*��������ɸ�����һ�η�Χ�ڵ�����*/
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

int num[10005];  //������Ϊ1������Ϊ0
int sushu[3000];
int numSu = 0;  //��¼��������


//���Ĵ��룺����ɸ��
void init()
{
    for(int i=2;i<=10001;i++){
        if(num[i] == 1) continue;  //������������һ��
        else{   //��û�б����Ϊ1����˵����������������Ҫר����֤
            sushu[++numSu] = i;
            //�õ��������󣬽�����δ֪����ȷ��Ϊ������
            for(int j=i*i;j<=10002;j+=i){
                num[j] = 1;
            }
        }
    }
}

int main()
{
    init();  //�õ�1~10000֮������������ע�⣺1��������������
    int x;
    scanf("%d",&x);
    for(int i=1;i<=numSu;i++){
        if(sushu[i]<x && sushu[i]%10==1){
            cout<<sushu[i]<<" ";
        }
    }
    return 0;
}
