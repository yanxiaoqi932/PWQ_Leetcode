#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int buf[100];
int main()
{
    int n=5;
    for(int i=0;i<n;i++){
        scanf("%d",&buf[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){

            if(buf[j]>buf[j+1]){    //ÉýÐò
                int tmp = buf[j];
                buf[j] = buf[j+1];
                buf[j+1] = tmp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\n",buf[i]);
    }
    return 0;
}
