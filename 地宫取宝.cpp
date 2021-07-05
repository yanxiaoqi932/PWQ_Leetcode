#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
int digong[100][100];
int cinn,cinm,cink;
int d[51][51][13][2];  //行，列，宝物个数，拥有宝物的最大价值，d：方法数目
long long int mod = 1000000007;
int main()
{
    cin>>cinn>>cinm>>cink;
    int themax = 0;
    for(int i=1;i<=cinn;i++){
        for(int j=1;j<=m;j++){
            cin>>digong[i][j];
            if(themax<digong[i][j]){
                themax = digong[i][j];
            }
        }
    }

    int mymax = 0;
    d[1][1][0][0] = 0;
    for(int n=1;n<=cinn;n++){
        for(int m=1;m<=cinm;m++){
            for(int k=0;k<=cink;k++){
                for(int c = 0;c<=themax;c++){
                    int s1 = 0;int s2 = 0;
                    if(digong[n][m]>c && k>0){
                        s1 = d[n-1][m][k-1][c] + d[n][m-1][k-1][c];  //选取了一个
                    }
                    s2 = d[n-1][m][k][c] + d[n][m-1][k][c];     //没有选取
                    d[n][m][k][digong[n][m]] = (s1+s2)%mod;
                }
            }
        }
    }
}
