/*����ջ�������������*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>
using namespace std;
string formula;
//���ȼ�����:#,+,-,*,/
int priority[5][5]={1,0,0,0,0,
                    1,0,0,0,0,
                    1,0,0,0,0,
                    1,1,1,0,0,
                    1,1,1,0,0};
stack<int> op;
stack<double> num;
int getop(char c){
    if(c=='+'){
        return 1;
    }else if(c=='-'){
        return 2;
    }else if(c=='*'){
        return 3;
    }else if(c=='#'){
        return 0;
    }else{
        return 4;
    }
}
int main()
{
    cin>>formula;
    formula+="#";   //��β����һ����������
    int len = formula.size();
    double n = 0.00;  //��ʱ��¼��ȡ������
    op.push(0.00); //��"#"ѹ�����ջ��
    for(int i=0;i<len;i++){
        if(formula[i]>='0' && formula[i]<='9'){   //����ȡ��һ������ʱ����ʱ��¼������������һλ
            n = n*10.00+(double)(formula[i]-'0');
        }
        else{   //��ȡ��һ������
            num.push(n);n = 0; //��ǰһ��������ѹ������ջ��
            int m = getop(formula[i]);  //m��ʱ��¼��ǰ��ȡ�ķ���
            //1.�����ǰ�����ķ������ȼ�����ջ�����ţ������ջ�����ŵĽ��
            while(!priority[m][op.top()]){
                double a = num.top();num.pop();
                double b = num.top();num.pop();
                int o = op.top();op.pop();
                double re = 0.00;  //������
                switch(o){
                    case 1:re = b+a;break;
                    case 2:re = b-a;break;
                    case 3:re = b*a;break;
                    case 4:re = b/a;break;
                    default:break;
                }
                num.push(re);
            //�״�㣺�������֮�󣬽����ѹ������ջ��,
            //�·��ű����������һ��op.top()�Ƚ�,ֱ�����ȼ�������Ϊֹ
            }
            //2.�����ǰ�����ķ������ȼ�����ջ�����ţ���ѹ��ջ
            if(priority[m][op.top()]){
                op.push(m);
            }
        }
    }
    printf("%.2lf",num.top());
}
