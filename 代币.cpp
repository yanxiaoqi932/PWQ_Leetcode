#include <iostream>
#include <stdio.h>
using namespace std;
int num;
int ans;
int main()
{
    cin>>num;
    while(num>=16){
        num-=16;
        ans+=227;
    }
    while(num>=8){
        num-=8;
        ans+=109;
    }
    while(num>=4){
        num-=4;
        ans+=49;
    }
    while(num>=2){
        num-=2;
        ans+=23;
    }
    while(num>=1){
        num-=1;
        ans+=10;
    }
    cout<<ans;
    return 0;
}
