#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

int longestValidParentheses(string s)
{
	//以该元素结尾的最长有效长度   不是题目的解
	//题目的解应该是dp中最大的数
	
	//以（结尾
	vector<int> dp(s.size(), 0);  
	//边填表边维护最大值
	int max = 0;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] == ')')
		{
			if (s[i - 1] == '(')
			{
				dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
			}
			//如果i-1-dp[i-1]<0说明i-1一直匹配到头 则dp[i]=0;
			//如果i-1-dp[i-1]>=0且s[i-1-dp[i-1]]==')' 说明dp[i]=0
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