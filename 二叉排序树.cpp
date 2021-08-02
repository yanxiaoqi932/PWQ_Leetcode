/*����һ�����ݣ�����������������������С����������*/
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

//ǰ�к������
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

//���õݹ�ȶԵķ�ʽ�������ֲ��������������
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
    node *root = NULL;  //Insert���Զ�����һ���㣬���ﲻ��Ҫ��������㣬ֻ��Ҫ������Ϊ�ռ���
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
