#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>
#include <typeinfo>

//unordered_map��map
//unordered_map�ڲ�ʵ����һ����ϣ��(ɢ�б�)
//map�ڲ�ʵ����һ�������

void func(vector<string> &res, string str, string &digits, unordered_map<char, string> &m, int k);
vector<string> letterCombinations(string digits)
{
	//unordered_map���Ԫ��
	unordered_map<char, string> mymap{ { '2', "abc" },
	{ '3', "def" }, { '4', "ghi" }, { '5', "jkl" },
	{ '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" },
	{ '9', "wxyz" } };

	vector<string> res;
	if (digits == "")
		return res;
	else
	{
		func(res, "", digits, mymap, 0);
		return res;
	}

}
void func(vector<string> &res, string str, string &digits, unordered_map<char, string> &m, int k){
	if (str.size() == digits.size()){
		res.push_back(str);
		return;
	}
	string tmp = m[digits[k]];
	for (char w : tmp){
		str += w;
		func(res, str, digits, m, k + 1);  //��ǰ�ַ�������
		str.pop_back();
	}
	return;
}

void main()
{
vector<string> result = letterCombinations("2");
for (vector<string>::iterator it = result.begin(); it != result.end(); it++)
{
	cout << *it << endl;
}
system("pause");
}