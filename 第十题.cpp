#include <iostream>
using namespace std;
#include <string>
#include <vector>

//�ݹ鷨 �� ��̬�滮
//�ݹ� ʮ�ּ�� ռ���ڴ�� ����ʱ�䳤
bool isMatch1(string s, string p)
{
	if (p.empty())
	{
		return s.empty();
	}
	if ('*' == p[1])
	{
		//*��ʾ0�������  ||  ����ʾ0�������
		//����ʾ0��ʱ: s�϶���Ϊ����s[0]=p[0]��p[0]='.' && isMatch1(s.substr(1), p)
		return isMatch1(s, p.substr(2)) || (!s.empty()) && (s[0] == p[0] || '.' == p[0]) && isMatch1(s.substr(1), p);
	}
	else
	{
		//���ж�s.empty() ��������ж�empty��substr(1)�ᴥ���ж�
		return !s.empty()&&isMatch1(s.substr(1), p.substr(1)) && (p[0] == s[0] || p[0] == '.');
	}
}

//��̬�滮
bool isMatch(string s, string p)
{
	int sSize = int(s.size());
	int pSize = int(p.size());
	if (p.empty())
	{
		return s.empty();
	}
	vector<bool> tmpVec(pSize + 1, false);//dp��СӦ�ñ�s��p��size��1
	vector<vector<bool>> dp(sSize + 1, tmpVec); //dp[i][j] ��ʾ s ��ǰ i ���Ƿ��ܱ� p ��ǰ j ��ƥ��
	dp[0][0] = true;
	if (sSize != 0 && (p[0] == s[0] || p[0] == '.'))
	{
		dp[1][1] = true;
	}
	if (p[0] == '*')
	{
		dp[0][1] = true;
	}
	//��ʼ�������sΪ�գ�pΪ.*.*�����
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
			{ //���������Ԫ�� �����Ƕ���Ԫ��ƥ��
				dp[i + 1][j + 1] = dp[i][j];
			}
			if (p[j] == '*')
			{
				//caa cb* -> caa c
				if (p[j - 1] != s[i] && p[j - 1] != '.')
				{ //���ǰһ��Ԫ�ز�ƥ�� �Ҳ�Ϊ����Ԫ��
					dp[i + 1][j + 1] = dp[i + 1][j - 1];
				}
				else
				{
					//caa c.* -> ca c.*
					//caa ca* -> ca ca*
					//ca ca* -> ca ca / c ca*
					//ca ca*a* -> ca ca*
					dp[i + 1][j + 1] = (dp[i][j + 1] || dp[i + 1][j - 1]);// || dp[i + 1][j]����Ҫ
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