/*���������������ĸ���*/
#include <iostream>
#include <stdio.h>
using namespace std;

//�����ҵ�10^5����
int num[100005];  //����Ϊ0
int sushu[10000];
int numSu;
long long int n;  //��������
int ans;
void init()
{
    for(int i=2;i<=100002;i++){
        if(num[i] == 1) continue;
        else if(i>1000) continue;
        else{
            sushu[++numSu] = i;
            for(int j=i*i;j<=100002;j+=i){
                num[i] = 1;
            }
        }
    }
}

int main()
{
    init();
    scanf("%d",&n);
    int i=1;
    while(n!=1){
        while(n%sushu[i] == 0){
            n = n/sushu[i];
            ans++;
        }
        i++;
    }
    cout<<ans;
    return 0;
}
