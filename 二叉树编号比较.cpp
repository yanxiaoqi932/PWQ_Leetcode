#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int n;

struct duan{
    long long int l,r;
}du[65];

void init(){
    for(int i=0;i<=60;i++){
        long long int l = pow(2,i);
        long long int r = pow(2,i+1)-1;
        du[i].l = l;
        du[i].r = r;
        //cout<<du[i].r<<endl;
    }
}
int wheduan(long long int num)
{
    int whe = 0;
    while(whe<=60){
        if(du[whe].r>=num){
            //cout<<"ok"<<endl;
            return whe;
        }else{
            whe++;
        }
    }
    return 0;
}
int main()
{
    init();
    cin>>n;
    for(int i=1;i<=n;i++){
        long long int l,r;
        cin>>l>>r;
        int d1 = wheduan(l);  //返回各自所在层数
        int d2 = wheduan(r);
        //cout<<d1<<" "<<d2<<endl;
        if(d1==d2){
            cout<<(l>r?"YES":"NO");
        }else if(d1<d2){
            while(1){
                if(d2==d1+1){
                    if(r==2*l){
                        cout<<"YES";break;
                    }
                    else if(r==2*i+1){
                        cout<<"NO";break;
                    }
                }
                r/=2;
                d2--;
                if(d2==d1){
                    cout<<(l>r?"YES":"NO");break;
                }
            }
        }else if(d1>d2){
            while(1){
                if(d1==d2+1){
                    if(l==2*r){
                        cout<<"NO";break;
                    }
                    else if(l==2*r+1){
                        cout<<"YES";break;
                    }
                }
                l/=2;
                d1--;
                if(d2==d1){
                    cout<<(l>r?"YES":"NO");break;
                }
            }
        }
        if(i!=n)
            cout<<endl;
    }
    return 0;
}
