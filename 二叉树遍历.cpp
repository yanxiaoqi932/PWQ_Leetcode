#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

struct node
{
    //节点左右子树和值
    node *lchild;
    node *rchild;
    int value;
}Tree[50];
queue<node> q;

int loc = 0;  //记录创建节点的个数
int num[50];  //记录输入数据
int n = 0;  //记录输入数据个数
int whe = 1; //记录当前生成的子节点是数组第whe个元素

node *creat()
{
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

//前序遍历
void preorder(node *Tree)
{
    cout<<Tree->value<<" ";  //在引用中要使用"->"而不是"."
    if(Tree->lchild!=NULL){
        preorder(Tree->lchild);
    }
    if(Tree->rchild!=NULL){
        preorder(Tree->rchild);
    }

}

//中序遍历
void inorder(node *Tree)
{
    if(Tree->lchild!=NULL){
        inorder(Tree->lchild);
    }
    cout<<Tree->value<<" ";  //在引用中要使用"->"而不是"."
    if(Tree->rchild!=NULL){
        inorder(Tree->rchild);
    }
}

//后序遍历
void postorder(node *Tree)
{
    if(Tree->lchild!=NULL){
        postorder(Tree->lchild);
    }
    if(Tree->rchild!=NULL){
        postorder(Tree->rchild);
    }
    cout<<Tree->value<<" ";  //在引用中要使用"->"而不是"."
}

//按照前序遍历，递归生成一棵二叉树
node *build()  //i代表数组的第i个数
{
    node *nod = creat();
    nod->value = num[whe];

    if((whe+1)<=n){
        whe++;
        nod->lchild = build();  //生成nod节点的左子树，同时whe会得到更新

    }
    if((whe+1)<=n){
        whe++;
        nod->rchild = build();  //生成nod节点的右子树，同时whe会得到更新

    }
    return nod;
}

int main()
{

    if(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++){
            scanf("%d",&num[i]);
        }
    }

    node *root = creat();  //构建一棵二叉树，root是根结点
    root = build();

    preorder(root);cout<<endl;
    inorder(root);cout<<endl;
    postorder(root);

    return 0;
}
