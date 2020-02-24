#include <iostream>
using namespace std;
#include <string>
#include <unordered_map>
#include <typeinfo>

//string s = "adad"
//s[0]ÎªcharÐÍ
//char->string: srting tmp(1,s[0]);

vector<string> letterCombinations(string digits)
{
	unordered_map<char, string> mymap;
	mymap['1'] = "!@#";
	mymap['2'] = "abc";
	mymap.insert(make_pair('3', "def"));
	mymap.insert(pair<char, string>('4', "ghi"));
	mymap['5'] = "jkl";
	mymap['6'] = "mno";
	mymap['7'] = "pqrs";
	mymap['8'] = "tuv";
	mymap['9'] = "wxyz";
	if (digits.size() == 1)
	{
		vector<string> result;
		for (int i = 0; i < (mymap[digits[0]]).size(); i++)
		{			
			string tmp(1, mymap[digits[0]][i]);   //char -> string
			result.push_back(tmp);
		}
		return result;
	}
	else
	{
		vector<string> lastresult = letterCombinations(digits.substr(0, digits.size() - 1));
		vector<string> result;
		for (int i = 0; i < mymap[digits.back()].size(); i++)
		{
			for (int j = 0; j < lastresult.size(); j++)
			{
				result.push_back(lastresult[j] + mymap[digits.back()][i]);
			}
		}
		return result;

	}
	
}
void main()
{
	/*string s = "dad";
	cout << s.substr(0, s.size() - 1)<<endl;*/
	//vector<string> result;
	//string tmp(1,s[0]);
	//result.push_back(tmp);
	//cout << s[0] << endl << tmp << endl;
	//cout << typeid(s[0]).name() << endl << typeid(tmp).name();

	vector<string> result = letterCombinations("");
	for (vector<string>::iterator it = result.begin(); it != result.end(); it++)
	{
		cout << *it << endl;
	}
	system("pause");
}