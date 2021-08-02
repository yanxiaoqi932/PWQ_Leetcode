#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MaxSize 1001
//m代表转换前的原始进制，a代表转换的字符串
//(该函数输出的字符串a是反向的，低位在前，高位在后)，n为转换后的目标进制
string conversion(int m, string a, int n){
    int len = a.size(), remind = 0;
    string strout;
    //只要被除数仍然大于等于1，那就继续模n取余
    for(int i = 0; i < len;){
        remind = 0;
        //12345 / 2 变成  06172 那么下次跳过了数字为 0 的下标，从 6 开始 ,但是下标总是以 n 结束
        for(int j = i; j < len; j++){
            //当前余数t=被除数(上一轮的余数k*转换前进制m+当前位上的数a[j]) % 转换后的目标进制n
            int tmp = (remind * m + a[j] - '0') % n;
            a[j] = (remind * m + a[j] - '0') / n + '0';//a[j]赋值为商
            remind = tmp;//更新上一轮的余数k为当前余数t
        }
        strout += char(remind + '0');//这一轮运算得到的余数k(低位在前，高位在后)
        while(a[i] == '0') i++;//跳过这一次产生的高位的0,找到下一轮商的起始位置
    }
    return strout;
}
int main(){
    string a, b, c;
    while(cin >> a){
        b = conversion(10, a, 2);
        a = conversion(2, b, 10);
        reverse(a.begin(), a.end());  //reverse函数用于翻转first到last之间的顺序
        cout << a << endl;
    }
    return 0;
}
