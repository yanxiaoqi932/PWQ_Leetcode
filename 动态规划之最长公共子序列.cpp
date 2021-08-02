/*�����������*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

string str1,str2;
//lvs[i][j]����str1��ǰi���ַ���str2��ǰj���ַ���Ҳ����str1[0~i-1]��str2[0~j-1]���������������
int lvs[100][100];

int main()
{
    cin>>str1;
    cin>>str2;

    for(int i=0;i<str2.length();i++){
        lvs[0][i] = 0;
    }
    for(int i=0;i<str1.length();i++){
        lvs[i][0] = 0;
    }

    //���Ĵ���
    for(int i=1;i<=str1.length();i++){
        for(int j=1;j<=str2.length();j++){

            if(str1[i-1] == str2[j-1]){
                lvs[i][j] = lvs[i-1][j-1] + 1;
            }else
            {
                lvs[i][j] = max(lvs[i-1][j],lvs[i][j-1]);
            }

        }
    }
    cout<<lvs[str1.length()][str2.length()]<<endl;
}

/*
���룺
abcd
cxbydz
�����
2

1
17.151.164.96
10
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
17.151.164.96
*/
