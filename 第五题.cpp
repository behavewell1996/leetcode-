#include <iostream>
using namespace std;
#include <string>

//ע�� ��������ų�����Ϊ1����� ���ڵڶ����������ѭ�� ��Ϊ��Զ�ﲻ��������ֹ״̬ �������Լ���ѭ������Ϥ
string longestPalindrome(string s) {
	//if (s == "")
	//{
	//	return "";
	//}
	int length = 0;
	string result="";
	for (int i = 0; i<s.size(); i++)
	{
		int j = 0;
		while (i - j >= 0 && i + j<s.size() && s[i - j] == s[i + j])
		{
			if (length<1 + 2 * j)
			{
				length = 1 + 2 * j;
				result = s.substr(i - j, length);
			}
			j++;
		}
	}
	for (int i = 0; i<s.size() - 1; i++)
	{
		int j = 0;
		while (i - j >= 0 && i + j + 1<s.size() && s[i - j] == s[i + j + 1])
		{
			if (length<(j + 1) * 2)
			{
				length = 2 * j + 2;
				result = s.substr(i - j, length);
			}
			j++;
		}
	}
	return result;
}

void main()
{
	string s = "";
	cout<<longestPalindrome(s)<<endl;
	system("pause");
}