#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

int nump,updown;  //人数，上升或下降

struct student
{
    string name;
    int score;
    int id;
};

bool cmp0(student stu1,student stu2)  //降序排列
{
    if(stu1.score!=stu2.score){
        return stu1.score>stu2.score;
    }
    else{
        return stu1.id<stu2.id;
    }
}

bool cmp1(student stu1,student stu2)  //升序排列
{
    if(stu1.score!=stu2.score){
        return stu1.score<stu2.score;
    }
    else{
        return stu1.id<stu2.id;
    }
}

int main()
{
    while(cin>>nump>>updown){
        student stu[1001];
        for(int i=1;i<=nump;i++){
            string name;
            int score;
            cin>>name>>score;
            stu[i].name = name;
            stu[i].score = score;
            stu[i].id = i;
        }
        if(updown){
            sort(stu+1,stu+1+nump,cmp1);
        }
        else{
            sort(stu+1,stu+1+nump,cmp0);
        }
        for(int i=1;i<=nump;i++){
            cout<<stu[i].name<<" "<<stu[i].score<<endl;
        }
    }
    return 0;
}
