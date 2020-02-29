#include <iostream>
using namespace std;
#include <vector>
//string.c_str() ת����char*
//�ݹ鷨  ��Ŀ��Ҫ����vector ���ǵݹ麯�����Բ��÷���vector ���Է���voidͬʱά��һ��vector������һ��vectorԪ�� �ڵݹ���ڰ�Ԫ��push_back
//���ڵݹ麯������Ĺ��� ��Ҫ���ҵ�������ĿҪ��ݹ����

//l:��ǰ�ɲ���� ( ����   r:��ǰ�ɲ���� ) ����
//������Ҫ�õ����� get("",n,0,ans)
//�������⣺����str���滹�ܲ���l��'('��r��')'ʱ��str���Ѿ�������ַ���������vector�������еĿ����ַ���
void getAns(string str, int l, int r, vector<string>& ans)
{
	////�����ٲ�����
	if (l == 0 && r == 0)
	{
		ans.push_back(str);
	}

	////l��r������0ʱ ˵����������ӷ�ʽ
	//if (l > 0)
	//{
	//	getAns(str + '(', l - 1, r + 1, ans);  //�Ϸ�
	//}
	//if (r > 0)
	//{
	//	getAns(str + ')', l, r - 1, ans);
	//}

	//ͬע�͵Ĳ��� д����֪��û��� ������������һЩ
	if (l > 0 && r > 0)
	{
		getAns(str + '(', l - 1, r + 1, ans);   //���� ����(���ַ�����ans
		getAns(str + ')', l, r - 1, ans);       //ans�ټ����� ����)���ַ���
	}
	if (l > 0 && r == 0)
	{
		getAns(str + '(', l - 1, r + 1, ans);
	}
	if (r > 0 && l == 0)
	{
		getAns(str + ')', l, r - 1, ans);
	}
	
}

vector<string> generateParenthesis(int n) 
{
	vector<string> ans;
	getAns("", n, 0, ans);
	return ans;
}


//��������
vector<string> generateParenthesis2(int n,int m)
{
	vector<string> res;
	if (n == 0 && m == 0)
	{
		res.push_back("");
	}
	if (n != 0 && m == 0)
	{
		string tmp = "(";
		for (int i = 0; i < n; i++)
		{
			tmp += "(";
		}
		res.push_back(tmp);
	}
	if (m == n&&m>0&&n>0)
	{
		for (auto s : generateParenthesis2(n, m - 1))
		{
			res.push_back(s + ")");
		}
	}
	else if (n>m&&m>0 && n>0)
	{
		for (auto s : generateParenthesis2(n, m - 1))
		{
			res.push_back(s + ")");
		}
		if (n - 1 >= m)
		{
			for (auto s : generateParenthesis2(n - 1, m))
			{
				res.push_back(s + "(");
			}
		}
	}
	//else if (n < m)
	//{
	//	res.push_back("");
	//}
	return res;
}

void main()
{
	vector<string> res = generateParenthesis2(5,5);
	for (vector<string>::iterator it = res.begin(); it != res.end(); it++)
	{
		cout << (*it).c_str() << endl;
	}
	cout << res.size();  //cao �����ǿ������� ��Ϊ��Ч������ (һ��Ҫ����)
	system("pause");
}