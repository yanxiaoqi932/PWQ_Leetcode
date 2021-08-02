/*求正整数素因数的个数*/
#include <iostream>
#include <stdio.h>
using namespace std;

//素数找到10^5即可
int num[100005];  //素数为0
int sushu[10000];
int numSu;
long long int n;  //输入数据
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
