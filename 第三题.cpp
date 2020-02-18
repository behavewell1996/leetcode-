#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

//Ϊɶ����ʱ���ǲ��ù�ϣ���5��
//�������� + ��ϣ����
//ע�� map.find(key) �÷������ص�����

int lengthOfLongestSubstring(string s)
{
	int head(0), tail(0), result(0), tmp(0);
	//�ù�ϣ���¼ char �� �±�
	unordered_map<char, int> mymap;
	//ֻҪβָ��δ��β
	while (tail < s.size())
	{
		//��Ŀǰ�Ĵ�����δ�ҵ� <==> 1�ڹ�ϣ�����ҵ� 2��valueֵ���ڵ���head��ֵ
		if (mymap.find(s[tail]) != mymap.end() && mymap[s[tail]] >= head)
		{
			head = mymap[s[tail]] + 1;
			tmp = tail - head;
		}
		//��û�ҵ���Ҫ��������
		mymap[s[tail]] = tail;
		tail++;
		tmp++;
		result = max(result, tmp);  //һ�����ڵ����ֵ
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