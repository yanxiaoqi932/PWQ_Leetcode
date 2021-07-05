#include<cstdio>
#include<iostream>
using namespace std;
#define mx 100005
int data[mx];
int main(){
    int i, j, m, n;
    scanf("%d", &i);
    while (scanf("%d", &j)){
        ++data[j];
        cout<<data[j]<<endl;
    }
    for (i = 0; !data[i]; ++i);
    for (m = n = 0; !m || !n; ++i){
        if (!data[i]) m = i;
        if (data[i] > 1) n = i;
    }
    printf("%d %d", m, n);
    return 0;
}
