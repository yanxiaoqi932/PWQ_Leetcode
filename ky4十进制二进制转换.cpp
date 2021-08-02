#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MaxSize 1001
//m����ת��ǰ��ԭʼ���ƣ�a����ת�����ַ���
//(�ú���������ַ���a�Ƿ���ģ���λ��ǰ����λ�ں�)��nΪת�����Ŀ�����
string conversion(int m, string a, int n){
    int len = a.size(), remind = 0;
    string strout;
    //ֻҪ��������Ȼ���ڵ���1���Ǿͼ���ģnȡ��
    for(int i = 0; i < len;){
        remind = 0;
        //12345 / 2 ���  06172 ��ô�´�����������Ϊ 0 ���±꣬�� 6 ��ʼ ,�����±������� n ����
        for(int j = i; j < len; j++){
            //��ǰ����t=������(��һ�ֵ�����k*ת��ǰ����m+��ǰλ�ϵ���a[j]) % ת�����Ŀ�����n
            int tmp = (remind * m + a[j] - '0') % n;
            a[j] = (remind * m + a[j] - '0') / n + '0';//a[j]��ֵΪ��
            remind = tmp;//������һ�ֵ�����kΪ��ǰ����t
        }
        strout += char(remind + '0');//��һ������õ�������k(��λ��ǰ����λ�ں�)
        while(a[i] == '0') i++;//������һ�β����ĸ�λ��0,�ҵ���һ���̵���ʼλ��
    }
    return strout;
}
int main(){
    string a, b, c;
    while(cin >> a){
        b = conversion(10, a, 2);
        a = conversion(2, b, 10);
        reverse(a.begin(), a.end());  //reverse�������ڷ�תfirst��last֮���˳��
        cout << a << endl;
    }
    return 0;
}
