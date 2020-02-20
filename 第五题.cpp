#include <iostream>
using namespace std;
#include <string>

//注意 如果不先排除长度为1的情况 会在第二种情况中死循环 因为永远达不到条件终止状态 本质是自己对循环不熟悉
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