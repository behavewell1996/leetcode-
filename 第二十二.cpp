#include <iostream>
using namespace std;
#include <vector>
//string.c_str() 转换成char*
//递归法  题目需要返回vector 但是递归函数可以不用返回vector 可以返回void同时维护一个vector参数和一个vector元素 在递归出口把元素push_back
//难在递归函数语意的构造 主要是找到符合题目要求递归对象

//l:当前可插入的 ( 数量   r:当前可插入的 ) 数量
//最终需要得到的是 get("",n,0,ans)
//函数语意：当在str后面还能插入l个'('和r个')'时（str是已经插入的字符串），用vector保存所有的可能字符串
void getAns(string str, int l, int r, vector<string>& ans)
{
	////不能再插入了
	if (l == 0 && r == 0)
	{
		ans.push_back(str);
	}

	////l和r都大于0时 说明有两种添加方式
	//if (l > 0)
	//{
	//	getAns(str + '(', l - 1, r + 1, ans);  //合法
	//}
	//if (r > 0)
	//{
	//	getAns(str + ')', l, r - 1, ans);
	//}

	//同注释的部分 写出来知道没差别 但是下面好理解一些
	if (l > 0 && r > 0)
	{
		getAns(str + '(', l - 1, r + 1, ans);   //添完 填完(后字符串的ans
		getAns(str + ')', l, r - 1, ans);       //ans再继续添 填完)的字符串
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


//卡特兰数
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
	cout << res.size();  //cao 发现是卡特兰数 因为有效的括号 (一定要多于)
	system("pause");
}