#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct bigInteger
{
    int digit[1000];  //每个digit[]存储一个四位数
    int size;  //该大数一共使用了size个digit[]来存储,即0~size-1

    void init()  //归零size和所有digit
    {
        for(int i=0;i<=999;i++){
            digit[i] = 0;
        }
        size = 0;
    }

    void set(int x)   //用小整数为大数赋值
    {
        init();
        do{
            digit[size++] = x%10000;
            x/=10000;
        }while(x!=0);
    }

    void output()   //输出整个大数
    {
        for(int i=0;i<size;i++){
            //当digit[i]不是最高位时，必须补零为4位，如10001要补齐后四位
            if(i!=size-1) printf("%04d",digit[i]);
            else{
                printf("%d",digit[i]);
            }
        }
        printf("\n");
    }

    bigInteger operator * (int x) const   //重载运算符*，计算大数与普通整数的乘积
    {
        bigInteger ret;
        ret.init();  //将结构体的大数与整数x相乘，其结果储存在新大数ret中
        int carry = 0;  //用于存储前一位溢出的值

        for(int i=0;i<size;i++){
            int tmp = digit[i]*x + carry;
            carry = tmp/10000;
            ret.digit[ret.size++] = tmp%10000;
        }
        if(carry != 0){
            ret.digit[ret.size++] = carry;  //如果相乘后大数位增加，则将carry放进更高一级中
        }
        return ret;
    }

    bigInteger operator + (const bigInteger &A) const  //重载运算符+，计算大数与大数之和
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

    bigInteger operator / (int x) const   //重载运算符/，计算大数与普通整数的商
    {
        bigInteger ret;
        ret.init();
        int reminder = 0;  //上一级的余数
        for(int i=size-1;i>=0;i--){
            int t = digit[i] + reminder*10000;
            reminder = t%x;
            ret.digit[i] = t/x;
        }
        //求ret.size（最高级可能被除为0）
        ret.size = 0;
        for(int i=0;i<size;i++){
            if(ret.digit[i]!=0) ret.size = i;
        }
        ret.size++;

        return ret;
    }

    int operator % (int x) const   //重载运算符%，计算大数与普通整数的余数
    {
        bigInteger ret;
        ret.init();
        int reminder = 0;  //从最高层开始除，上一级的余数
        for(int i=size-1;i>=0;i--){
            int t = digit[i] + reminder*10000;
            reminder = t%x;
            ret.digit[i] = t/x;
        }
        return reminder;
    }
}a,b,c;

int m,n;
char str[10000];  //输入的字符串数组
char ans[10000];  //输出的字符串数组

int main()
{
    cin>>m>>n;  //m进制转成n进制
    cin>>str;
    int len = strlen(str);
    bigInteger a,b;
    a.init();b.init();
    a.set(0);b.set(1);
    //从低位开始，将输入m进制字符串转化为10进制，并储存在大数a中
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
    //将10进制大数a转成n进制大数，并储存在ans字符串中
    int s = 0; //记录ans字符数组的动态大小
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
