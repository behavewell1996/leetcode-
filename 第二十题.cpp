#include <iostream>
using namespace std;
#include <algorithm>
#include <string>
//(){}[]

//s.assign(s1.begin(),s1.end())ֱ�Ӹı���s��ֵ
//find(it1,it2,'x')

//�����Լ��ĺ�������index??
//s.find("string",index)
//s.replace(index,number,"string")

#include <stack>
//��һ���ҷ��ŵ����Ա�һ���Ƕ�Ӧ�������------>��ջ�ķ��� ����߿�ʼ���� �������ջ ������һ���ҷ��� �����Ӧ���ջ �����������������Ӧ��return false
//��stackʵ��
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
				else myStack.pop(); //��ջ		
			}
			if (c == '}')
			{
				if (myStack.empty() || myStack.top() != '{') return false;
				else myStack.pop(); //��ջ		
			}
			if (c == ')')
			{
				if (myStack.empty() || myStack.top() != '(') return false;
				else myStack.pop(); //��ջ		
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