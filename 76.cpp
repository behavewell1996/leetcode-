#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <ctime>

bool issub(string s,string t)
{
	bool res = true;
	for (auto w : t)
	{
		bool subres = false;
		for (auto v : s)
		{
			subres = subres || (v == w);
		}
		res = res&&subres;
	}
	return res;
}

//bool issub2(string s, string t)
//{
//	unordered_map<char,int> mymap;
//	for (auto w : s)
//	{
//		mymap.insert(pair<char, int>(w, 0));
//	}
//	for (auto w : t)
//	{
//		if (mymap.find(w) == mymap.end())
//		{
//			return false;
//		}
//	}
//	return true;
//
//}
bool issub2(string s, string t)
{
	unordered_map<char, int> mymap;
	for (auto w : s)
	{
		if (mymap.find(w) == mymap.end())
		{
			mymap.insert(pair<char, int>(w, 1));
		}
		else
		{
			mymap[w]++;
		}
	}
	for (auto w : t)
	{
		if (mymap.find(w) == mymap.end())
		{
			return false;
		}
		else{
			mymap[w]--;
			if (mymap[w]<0)
				return false;
		}
	}
	return true;

}
string minWindow(string s, string t) {
	int l(0), r(-1);
	int tmpl(0), tmp(s.size() + 1);
	while (l<s.size())
	{
		if ((r+1) < s.size() && !issub2(s.substr(l, r - l + 2), t))
		{
			r++;
		}
		else
		{
			if (issub2(s.substr(l, r - l + 2), t) && (r - l + 2)<tmp)
			{
				tmp = r - l + 2;
				tmpl = l;
			}
			l++;
		}

	}
	return issub2(s.substr(tmpl, tmp), t) == true ? s.substr(tmpl, tmp):"";
}

void main()
{
	
	cout << issub2("babb", "baba");
	cout << minWindow("babb", "baba") << endl;
	system("pause");
}