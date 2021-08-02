#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

struct node
{
    //�ڵ�����������ֵ
    node *lchild;
    node *rchild;
    int value;
}Tree[50];
queue<node> q;

int loc = 0;  //��¼�����ڵ�ĸ���
int num[50];  //��¼��������
int n = 0;  //��¼�������ݸ���
int whe = 1; //��¼��ǰ���ɵ��ӽڵ��������whe��Ԫ��

node *creat()
{
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

//ǰ�����
void preorder(node *Tree)
{
    cout<<Tree->value<<" ";  //��������Ҫʹ��"->"������"."
    if(Tree->lchild!=NULL){
        preorder(Tree->lchild);
    }
    if(Tree->rchild!=NULL){
        preorder(Tree->rchild);
    }

}

//�������
void inorder(node *Tree)
{
    if(Tree->lchild!=NULL){
        inorder(Tree->lchild);
    }
    cout<<Tree->value<<" ";  //��������Ҫʹ��"->"������"."
    if(Tree->rchild!=NULL){
        inorder(Tree->rchild);
    }
}

//�������
void postorder(node *Tree)
{
    if(Tree->lchild!=NULL){
        postorder(Tree->lchild);
    }
    if(Tree->rchild!=NULL){
        postorder(Tree->rchild);
    }
    cout<<Tree->value<<" ";  //��������Ҫʹ��"->"������"."
}

//����ǰ��������ݹ�����һ�ö�����
node *build()  //i��������ĵ�i����
{
    node *nod = creat();
    nod->value = num[whe];

    if((whe+1)<=n){
        whe++;
        nod->lchild = build();  //����nod�ڵ����������ͬʱwhe��õ�����

    }
    if((whe+1)<=n){
        whe++;
        nod->rchild = build();  //����nod�ڵ����������ͬʱwhe��õ�����

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

    node *root = creat();  //����һ�ö�������root�Ǹ����
    root = build();

    preorder(root);cout<<endl;
    inorder(root);cout<<endl;
    postorder(root);

    return 0;
}
