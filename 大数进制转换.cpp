#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct bigInteger
{
    int digit[1000];  //ÿ��digit[]�洢һ����λ��
    int size;  //�ô���һ��ʹ����size��digit[]���洢,��0~size-1

    void init()  //����size������digit
    {
        for(int i=0;i<=999;i++){
            digit[i] = 0;
        }
        size = 0;
    }

    void set(int x)   //��С����Ϊ������ֵ
    {
        init();
        do{
            digit[size++] = x%10000;
            x/=10000;
        }while(x!=0);
    }

    void output()   //�����������
    {
        for(int i=0;i<size;i++){
            //��digit[i]�������λʱ�����벹��Ϊ4λ����10001Ҫ�������λ
            if(i!=size-1) printf("%04d",digit[i]);
            else{
                printf("%d",digit[i]);
            }
        }
        printf("\n");
    }

    bigInteger operator * (int x) const   //���������*�������������ͨ�����ĳ˻�
    {
        bigInteger ret;
        ret.init();  //���ṹ��Ĵ���������x��ˣ������������´���ret��
        int carry = 0;  //���ڴ洢ǰһλ�����ֵ

        for(int i=0;i<size;i++){
            int tmp = digit[i]*x + carry;
            carry = tmp/10000;
            ret.digit[ret.size++] = tmp%10000;
        }
        if(carry != 0){
            ret.digit[ret.size++] = carry;  //�����˺����λ���ӣ���carry�Ž�����һ����
        }
        return ret;
    }

    bigInteger operator + (const bigInteger &A) const  //���������+��������������֮��
    {
        bigInteger ret;
        ret.init();
        int carry = 0;

        for(int i=0;i<A.size||i<size;i++){
            int tmp = A.digit[i] + digit[i] + carry;
            carry = tmp/10000;
            ret.digit[ret.size++] = tmp%10000;
        }
        if(carry!=0){
            ret.digit[ret.size++] = carry;
        }
        return ret;
    }

    bigInteger operator / (int x) const   //���������/�������������ͨ��������
    {
        bigInteger ret;
        ret.init();
        int reminder = 0;  //��һ��������
        for(int i=size-1;i>=0;i--){
            int t = digit[i] + reminder*10000;
            reminder = t%x;
            ret.digit[i] = t/x;
        }
        //��ret.size����߼����ܱ���Ϊ0��
        ret.size = 0;
        for(int i=0;i<size;i++){
            if(ret.digit[i]!=0) ret.size = i;
        }
        ret.size++;

        return ret;
    }

    int operator % (int x) const   //���������%�������������ͨ����������
    {
        bigInteger ret;
        ret.init();
        int reminder = 0;  //����߲㿪ʼ������һ��������
        for(int i=size-1;i>=0;i--){
            int t = digit[i] + reminder*10000;
            reminder = t%x;
            ret.digit[i] = t/x;
        }
        return reminder;
    }
}a,b,c;

int m,n;
char str[10000];  //������ַ�������
char ans[10000];  //������ַ�������

int main()
{
    cin>>m>>n;  //m����ת��n����
    cin>>str;
    int len = strlen(str);
    bigInteger a,b;
    a.init();b.init();
    a.set(0);b.set(1);
    //�ӵ�λ��ʼ��������m�����ַ���ת��Ϊ10���ƣ��������ڴ���a��
    for(int i=len-1;i>=0;i--){
        int tmp = 0;
        if(str[i]>='0' && str[i]<='9'){
            tmp = str[i]-'0';
        }else{
            tmp = str[i]-'A'+10;
        }
        a = a+b*tmp;
        b = b*m;
    }
    //��10���ƴ���aת��n���ƴ�������������ans�ַ�����
    int s = 0; //��¼ans�ַ�����Ķ�̬��С
    do{
        int tmp = a%n;
        if(tmp>=0 && tmp<=9){
            ans[s++] = tmp+'0';
        }else{
            ans[s++] = tmp+'A';
        }
        a = a/n;

    }while(a.digit[0]!=0 || a.size>1);
    for(int i=s-1;i>=0;i--){
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
