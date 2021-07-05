#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std;
int loc;
int ch;
int n;
int dep;
int high;
int maxdep;
struct mypic{;
    int up;
    int down;
}pic[101][101];
string str;
struct node{
    node *lchild;
    node *rchild;
    int c;
    int depth;
    int up = 1;
    int down = 0;
}tree[10000];

void inorder(node *t){
    if(t->rchild!=NULL){
        t->down = 1;
        inorder(t->rchild);
    }
    high++;  //矩阵行数
    if(t->depth>maxdep){
        maxdep = t->depth;   //记录最大深度，即矩阵的列数
    }
    pic[high][t->depth].down = t->down;
    pic[high][t->depth].up = t->up;
    cout<<t->c<<" dep: "<<t->depth<<endl;
    if(t->lchild!=NULL){
        t->down = 1;
        inorder(t->lchild);
    }
}

node *create(){
    tree[loc].rchild = NULL;
    tree[loc].lchild = NULL;
    return &tree[loc++];
}
node *Insert(node *t,int x){
    dep++;
    if(t==NULL){
        t = create();
        t->c = x;  //创建一个新结点并返回
        t->depth = dep;
        dep = 0;
        return t;
    }else if(x<t->c){
        t->lchild = Insert(t->lchild,x);
    }else if(x>t->c){
        t->rchild = Insert(t->rchild,x);
    }
    return t;
}
int main(){
    int n;
    node *root = NULL;
    root->up = 0;
    while(1){
        ch = cin.get();
        if(ch==' '){
            n = std::atoi(str.c_str());
            str = "";

            root = Insert(root,n);
        }
        else if(ch == '\n'){
            n = std::atoi(str.c_str());
            str = "";

            root = Insert(root,n);
            break;
        }else{
            str+=ch;
        }
    }
    inorder(root);

}
