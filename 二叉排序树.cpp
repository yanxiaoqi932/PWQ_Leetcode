/*输入一串数据，建立二叉排序树：左子树小，右子树大*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct node
{
    node *lchild;
    node *rchild;
    int c;
}Tree[200];
int loc = 0;

node *creat()
{
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

//前中后序遍历
void preOrder(node *p)
{
    cout<<p->c;
    if(p->lchild!=NULL){
        preOrder(p->lchild);
    }
    if(p->rchild!=NULL){
        preOrder(p->rchild);
    }
}

void inOrder(node *p)
{
    if(p->lchild!=NULL){
        inOrder(p->lchild);
    }
    cout<<p->c;
    if(p->rchild!=NULL){
        inOrder(p->rchild);
    }
}

void postOrder(node *p)
{
    if(p->lchild!=NULL){
        postOrder(p->lchild);
    }
    if(p->rchild!=NULL){
        postOrder(p->rchild);
    }
    cout<<p->c;
}

//采用递归比对的方式，将数字插入排序二叉树中
node *Insert(node *p,int m)
{
    if(p==NULL){
        p = creat();
        p->c = m;
        return p;
    }
    else{
        if(m > p->c){
            p->rchild = Insert(p->rchild,m);
        }else{
            p->lchild = Insert(p->lchild,m);
        }
    }
    return p;
}

int main()
{
    int n,m;
    node *root = NULL;  //Insert会自动创建一个点，这里不需要创建根结点，只需要定义它为空即可
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&m);
            root = Insert(root,m);
        }
        preOrder(root);cout<<endl;
        inOrder(root);cout<<endl;
        postOrder(root);cout<<endl;
    }
    return 0;
}
