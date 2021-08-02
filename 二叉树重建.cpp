/*已知前序遍历和中序遍历，求树的重建，并后序遍历*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct Node{
    Node *lchild;
    Node *rchild;
    char c;
}Tree[100];
int loc = 0;

char str1[100];  //前序遍历输入
char str2[100];  //后序遍历输入

//新建一个Node节点
Node *creat()
{
    Tree[loc].lchild = NULL;
    Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

//后序遍历并输出
void postOrder(Node *node)
{
    if(node->lchild != NULL){
        postOrder(node->lchild);
    }
    if(node->rchild != NULL){
        postOrder(node->rchild);
    }
    cout<<node->c;
}

Node *build(int st1,int end1,int st2,int end2)
{
    Node *point = creat();
    char root = str1[st1];
    point->c = str1[st1];

    //寻找中序遍历中root的位置
    int wheRoot;
    for(int i=st2;i<=end2;i++){
        if(str2[i]==str1[st1]){
            wheRoot = i;
            break;
        }
    }

    //开始找左右子树
    int lenR = wheRoot-st2;
    if(wheRoot!=st2){  //左子树存在
        point->lchild = build(st1+1,lenR+st1,st2,wheRoot-1);
    }
    if(wheRoot!=end2){  //右子树存在
        point->rchild = build(lenR+st1+1,end1,wheRoot+1,end2);
    }
    return point;

}

int main()
{
    while(scanf("%s",str1)!=EOF){
        scanf("%s",str2);
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        Node *root = build(0,len1-1,0,len2-1);
        postOrder(root);
        cout<<endl;
    }


    return 0;
}
