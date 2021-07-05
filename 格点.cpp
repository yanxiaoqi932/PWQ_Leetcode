#include <iostream>
#include <stdio.h>
using namespace std;
int ans;
int main()
{
    for(int i=1;i<=2021;i++){
        for(int j=1;j<=2021;j++){
            if(i*j<=2021){
                ans++;
            }
        }
    }
    cout<<ans;
}
