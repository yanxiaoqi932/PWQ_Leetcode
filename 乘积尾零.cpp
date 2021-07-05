#include <iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#define ll long long
map<ll,int>mp;
int a[3] = {3,5,7};
int ans = 0;
priority_queue<ll,vector<ll>,greater<ll> >q; //小顶堆

void init(ll n){
    while(1){
        ll x = q.top();
        q.pop();
        if(x==n){
            cout<<ans;
            return;
        }
        for(int i=0;i<3;i++){
            ll m = x*a[i];
            if(mp.count(m)==0){   //没有重复出现过
                //cout<<m<<endl;
                q.push(m);
                mp[m] = 1;
            }
        }
        ans++;
    }
}

int main(){
    q.push(1);
    init(59084709587505);
    return 0;
}
