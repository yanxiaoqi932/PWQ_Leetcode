/*��֪ǰ�����������������������ؽ������������*/
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

char str1[100];  //ǰ���������
char str2[100];  //�����������

//�½�һ��Node�ڵ�
Node *creat()
{
    Tree[loc].lchild = NULL;
    Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

//������������
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

    //Ѱ�����������root��λ��
    int wheRoot;
    for(int i=st2;i<=end2;i++){
        if(str2[i]==str1[st1]){
            wheRoot = i;
            break;
        }
    }

    //��ʼ����������
    int lenR = wheRoot-st2;
    if(wheRoot!=st2){  //����������
        point->lchild = build(st1+1,lenR+st1,st2,wheRoot-1);
    }
    if(wheRoot!=end2){  //����������
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
