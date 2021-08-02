/*利用栈解决计算器问题*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>
using namespace std;
string formula;
//优先级函数:#,+,-,*,/
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
    formula+="#";   //结尾加入一个结束符号
    int len = formula.size();
    double n = 0.00;  //临时记录读取的数字
    op.push(0.00); //将"#"压入符号栈中
    for(int i=0;i<len;i++){
        if(formula[i]>='0' && formula[i]<='9'){   //当读取到一个数字时，临时记录，可能它有下一位
            n = n*10.00+(double)(formula[i]-'0');
        }
        else{   //读取到一个符号
            num.push(n);n = 0; //将前一个计算结果压入数字栈中
            int m = getop(formula[i]);  //m临时记录当前读取的符号
            //1.如果当前读到的符号优先级低于栈顶符号，则计算栈顶符号的结果
            while(!priority[m][op.top()]){
                double a = num.top();num.pop();
                double b = num.top();num.pop();
                int o = op.top();op.pop();
                double re = 0.00;  //计算结果
                switch(o){
                    case 1:re = b+a;break;
                    case 2:re = b-a;break;
                    case 3:re = b*a;break;
                    case 4:re = b/a;break;
                    default:break;
                }
                num.push(re);
            //易错点：计算完成之后，将结果压入数字栈后,
            //新符号必须继续和下一个op.top()比较,直至优先级比它高为止
            }
            //2.如果当前读到的符号优先级高于栈顶符号，则压入栈
            if(priority[m][op.top()]){
                op.push(m);
            }
        }
    }
    printf("%.2lf",num.top());
}
