#include <iostream>
#include <stdio.h>
using namespace std;
int qian[100001];
int zhong[100001];
struct node{
    node *lchild;
    node *rchild;
    int c;
}tree[100000];
int loc;
node *creat(int x){
    tree[loc].lchild = NULL;
    tree[loc].rchild = NULL;
    tree[loc].c = x;
    return &tree[loc++];
}

void postorder(node *root){  //后序遍历
    if(root->lchild!=NULL){
        postorder(root->lchild);
    }
    if(root->rchild!=NULL){
        postorder(root->rchild);
    }
    cout<<root->c<<" ";
}

node *findpost(int a1,int a2,int b1,int b2){
    node *root = creat(qian[a1]);
    int findroot;
    int whe_root;
    int lenleft,lenright;
    findroot = b1;
    if(zhong[b1]!=qian[a1]){   //左子树存在
        while(zhong[findroot]!=qian[a1]){
            findroot++;
        }
        whe_root = findroot;
        lenleft = whe_root-b1;
        root->lchild = findpost(a1+1,a1+lenleft,b1,whe_root-1);
    }else{                      //左子树不存在
        whe_root = b1;
    }

    if(qian[a1]!=zhong[b2]){  //右子树存在
        lenright = b2 - whe_root;
        root->rchild = findpost(a2-lenright+1,a2,whe_root+1,b2);
    }

    return root;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>qian[i];
    }
    for(int i=1;i<=n;i++){
        cin>>zhong[i];
    }
    node *root;
    root = findpost(1,n,1,n);
    postorder(root);
    return 0;
}
