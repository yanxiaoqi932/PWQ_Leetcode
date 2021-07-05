#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

int mark[1000005];   //false为素数，true非素数
int sushu[1000000];
int numsu[1000005];
int n;
long long num[10005];

struct fenjie{
    int sushu;
    int cifang;
};
stack<fenjie> st;

int whesu = 0;
void init()
{

    for(int i=2;i<=10005;i++){
        if(mark[i]==true)
            continue;
        else{
            sushu[++whesu] = i;  //将素数i放入sushu数组中
            for(int j=i * i;j<=1000005;j+=i){
                mark[j] = true;
            }
        }
    }
}

long long solve(long long num)
{
    long long ans = 1;
    while(!st.empty()){
        st.pop();
    }
    for(int i=1;i<=whesu;i++){
        int cifang = 0;
        if(num%sushu[i]==0){
            while(num%sushu[i]==0){
            num/=sushu[i];
            cifang++;
            }
            fenjie m;
            m.cifang = cifang;
            m.sushu = sushu[i];
            st.push(m);
        }

    }
    while(!st.empty()){
        fenjie m;
        m = st.top();
        st.pop();

        while(m.cifang>=3){
            m.cifang-=3;
            ans = ans*m.sushu;
        }
    }
    return ans;
}

int main()
{
    //memset(mark,false,sizeof(mark));
    init();

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];

    }
    for(int i=1;i<=n;i++){
        cout<<solve(num[i]);
        if(i!=n)
            cout<<endl;
    }

    return 0;
}
