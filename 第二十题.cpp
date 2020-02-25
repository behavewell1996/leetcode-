#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
//(){}[]

//s.assign(s1.begin(),s1.end())直接改变了s的值
//find(it1,it2,'x')

//好像自己的函数都是index??
//s.find("string",index)
//s.replace(index,number,"string")

#include <stack>
//第一个右符号的左旁边一定是对应的左符号------>用栈的方法 从左边开始遍历 左符号入栈 遇到第一个右符号 如果对应则出栈 继续遍历；如果不对应则return false
//用stack实现
//for(auto c:s)
bool isValid(string s)
{
	stack<char> myStack;
	for (auto c : s)
	{
		if (c == '[' || c == '{'||c == '(') myStack.push(c);
		else
		{
			if (c == ']')
			{
				if (myStack.empty() || myStack.top() != '[') return false;
				else myStack.pop(); //出栈		
			}
			if (c == '}')
			{
				if (myStack.empty() || myStack.top() != '{') return false;
				else myStack.pop(); //出栈		
			}
			if (c == ')')
			{
				if (myStack.empty() || myStack.top() != '(') return false;
				else myStack.pop(); //出栈		
			}
		}
	}
	return myStack.empty();
}


void main()
{
	string s = "()";
	cout << isValid(s) << endl;
	//cout<<s.substr(0, 2);
	//cout << s;
	system("pause");
}