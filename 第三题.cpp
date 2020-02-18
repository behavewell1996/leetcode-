#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

//为啥运行时间是不用哈希表的5倍
//滑动窗口 + 哈希查找
//注意 map.find(key) 用法，返回迭代器

int lengthOfLongestSubstring(string s)
{
	int head(0), tail(0), result(0), tmp(0);
	//用哈希表记录 char 和 下标
	unordered_map<char, int> mymap;
	//只要尾指针未到尾
	while (tail < s.size())
	{
		//在目前的窗口中未找到 <==> 1在哈希表中找到 2且value值大于等于head的值
		if (mymap.find(s[tail]) != mymap.end() && mymap[s[tail]] >= head)
		{
			head = mymap[s[tail]] + 1;
			tmp = tail - head;
		}
		//找没找到都要做的事情
		mymap[s[tail]] = tail;
		tail++;
		tmp++;
		result = max(result, tmp);  //一个窗口的最大值
	}
	
	return result;
}


void main()
{
	string s = "acbdaksbin";
	cout << s.size() << endl;
	cout << lengthOfLongestSubstring(s) << endl;

	system("pause");
}