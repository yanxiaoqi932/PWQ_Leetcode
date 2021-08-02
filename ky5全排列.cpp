#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

char ch[1000][1000];
char tmp[1000][1000];
int n,q;  //n行n列，规模为q
int mysize;  //扩张下前一张图的大小

int main()
{
    while(cin>>n){
        mysize = n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ch[i][j] = tmp[i][j] = 0;
            }
        }
        //输入数据
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ch[i][j] = getchar();
            }
            getchar();
        }
        cin>>q;
        mysize = n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                cout<<ch[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
