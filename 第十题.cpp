#include <iostream>
using namespace std;
#include <string>
#include <vector>

//递归法 和 动态规划
//递归 十分简洁 占用内存大 运行时间长
bool isMatch1(string s, string p)
{
	if (p.empty())
	{
		return s.empty();
	}
	if ('*' == p[1])
	{
		//*表示0个的情况  ||  不表示0个的情况
		//不表示0个时: s肯定不为空且s[0]=p[0]或p[0]='.' && isMatch1(s.substr(1), p)
		return isMatch1(s, p.substr(2)) || (!s.empty()) && (s[0] == p[0] || '.' == p[0]) && isMatch1(s.substr(1), p);
	}
	else
	{
		//先判断s.empty() 如果不先判断empty，substr(1)会触发中断
		return !s.empty()&&isMatch1(s.substr(1), p.substr(1)) && (p[0] == s[0] || p[0] == '.');
	}
}

//动态规划
bool isMatch(string s, string p)
{
	int sSize = int(s.size());
	int pSize = int(p.size());
	if (p.empty())
	{
		return s.empty();
	}
	vector<bool> tmpVec(pSize + 1, false);//dp大小应该比s，p的size大1
	vector<vector<bool>> dp(sSize + 1, tmpVec); //dp[i][j] 表示 s 的前 i 个是否能被 p 的前 j 个匹配
	dp[0][0] = true;
	if (sSize != 0 && (p[0] == s[0] || p[0] == '.'))
	{
		dp[1][1] = true;
	}
	if (p[0] == '*')
	{
		dp[0][1] = true;
	}
	//初始化情况：s为空，p为.*.*的情况
	for (int i = 1; i < pSize; i++)
	{
		if (p[i] == '*' && dp[0][i - 1] == true)
		{
			dp[0][i + 1] = true;
		}
	}

	for (int i = 0; i < sSize; i++)
	{
		for (int j = 1; j < pSize; j++)
		{
			if (p[j] == '.' || p[j] == s[i])
			{ //如果是任意元素 或者是对于元素匹配
				dp[i + 1][j + 1] = dp[i][j];
			}
			if (p[j] == '*')
			{
				//caa cb* -> caa c
				if (p[j - 1] != s[i] && p[j - 1] != '.')
				{ //如果前一个元素不匹配 且不为任意元素
					dp[i + 1][j + 1] = dp[i + 1][j - 1];
				}
				else
				{
					//caa c.* -> ca c.*
					//caa ca* -> ca ca*
					//ca ca* -> ca ca / c ca*
					//ca ca*a* -> ca ca*
					dp[i + 1][j + 1] = (dp[i][j + 1] || dp[i + 1][j - 1]);// || dp[i + 1][j]不需要
				}
			}
		}
	}
	//print(dp);
	return dp[sSize][pSize];
}


void main()
{
	string s = "ab";
	string p = ".*c";
	cout << isMatch1(s, p);
	
	system("pause");
}