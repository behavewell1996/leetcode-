#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

int longestValidParentheses(string s)
{
	//�Ը�Ԫ�ؽ�β�����Ч����   ������Ŀ�Ľ�
	//��Ŀ�Ľ�Ӧ����dp��������
	
	//�ԣ���β
	vector<int> dp(s.size(), 0);  
	//������ά�����ֵ
	int max = 0;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == ')')
		{
			if (s[i - 1] == '(')
			{
				dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
			}
			//���i-1-dp[i-1]<0˵��i-1һֱƥ�䵽ͷ ��dp[i]=0;
			//���i-1-dp[i-1]>=0��s[i-1-dp[i-1]]==')' ˵��dp[i]=0
			else if (i - 1 - dp[i-1]>=0&&s[i-1-dp[i-1]]=='(')
			{
				dp[i] = (i - 2 - dp[i - 1]) >= 0 ? (2 + dp[i - 1] + dp[i - 2 - dp[i - 1]]) : (dp[i - 1] + 2);
			}
		}
		if (dp[i] > max)
			max = dp[i];
	}
	return max;
}



void main()
{
	system("pause");
}