/*画图问题——叠框*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int len;char B;char A;
    while(scanf("%d %c %c",&len,&B,&A)!=EOF){
        if(((len+1)/2)%2!=0){
            char tmp;
            tmp = B;B = A;A = tmp;
        }
        char ch[100][100]={' '};
        int hlen = (len+1)/2;
        for(int i=2;i<=len-1;i++){
            ch[1][i] = A;
        }
        for(int i=2;i<=len-1;i++){
            ch[len][i] = A;
        }
        for(int row=2;row<=hlen;row+=2){  //偶数行
            for(int i=1;i<=len;i++){
                ch[row][i] = B;
            }
            for(int i=1;i<=row/2;i++){
                ch[row][2*i-1] = A;
                ch[row][len-2*i+2] = A;
            }
        }
        if(hlen>=3){                        //奇数行
            for(int row=3;row<=hlen;row+=2){
                for(int i=1;i<=len;i++){
                    ch[row][i] = A;
                }
                for(int i=1;i<=(row-1)/2;i++){
                    ch[row][2*i] = B;
                    ch[row][len+1-2*i] = B;
                }
            }
        }
        for(int row=1;row<=hlen;row++){
            for(int col=1;col<=len;col++){
                cout<<ch[row][col];
            }
            cout<<endl;
        }
        for(int row=hlen+1;row<=len;row++){
            for(int col=1;col<=len;col++){
                cout<<ch[2*hlen-row][col];
            }
            cout<<endl;
        }
    }
    return 0;
}
