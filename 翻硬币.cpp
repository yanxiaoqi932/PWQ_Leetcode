#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
string str0,str1;
int diff[1000];
int ans;
int main(){
    cin>>str0;
    cin>>str1;
    memset(diff,0,sizeof(diff));

    int len = str0.length();
    for(int i=0;i<len;i++){
        if(str0[i]!=str1[i]){
            diff[i] = 1;
        }
    }

    for(int i=0;i<len;i++){
        if(diff[i]==1){
            int j = i+1;
            while(1){
                if(diff[j]==1){
                    ans += j-i;
                    diff[i] = 0;
                    diff[j] = 0;
                    break;
                }
                j++;
            }
        }
    }
    cout<<ans;
}
