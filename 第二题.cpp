#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int i) :val(i), next(NULL){}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	//计算两个长度
	ListNode* p1 = l1;
	int len1 = 1;
	while (p1->next != NULL)
	{
		len1++;
		p1 = p1->next;
	}

	ListNode* p2 = l1;
	int len2 = 1;
	while (p2->next != NULL)
	{
		len2++;
		p2 = p2->next;
	}
	//补0 
	if (len1 < len2)
	{
		for (int i = 0; i < len2 - len1; i++)
		{
			p1->next = new ListNode(0);
			p1 = p1->next;
		}
	}
	else if (len2 < len1)
	{
		for (int i = 0; i < len1 - len2; i++)
		{
			p2->next = new ListNode(0);
			p2 = p2->next;
		}
	}
	//相加
	ListNode* l3 = new ListNode(-1);
	ListNode* p3 = l3;

	p1 = l1;
	p2 = l2;
	//从头（低位）加到尾（高位）
	int flag = 0;
	for (int i = 0; i < max(len1, len2); i++)
	{
		int value = p1->val + p2->val + flag;
		if (value < 10)
		{
			p3->next = new ListNode(value);			
			flag = 0;

		}
		else
		{
			p3->next = new ListNode(value % 10);
			flag = 1;
		}
		p3 = p3->next;
		p1 = p1->next;
		p2 = p2->next;
	}
	if (flag == 1)
	{
		p3->next = new ListNode(1);
	}
	return l3->next;
}



void main()
{
	ListNode* l1 = new ListNode(-1);
	ListNode* p1 = l1;
	ListNode* l2 = new ListNode(-1);
	ListNode* p2 = l2;
	
	cout << "请逐个输入l1，输入-1结束"<<endl;
	while (1)
	{
		int i;
		cin >> i;
		if (i == -1)
		{
			break;
		}
		p1->next = new ListNode(i);
		p1 = p1->next;
	}
	cout << "请输入l2，输入-1结束" << endl;
	while (1)
	{
		int j;
		cin >> j;
		if (j == -1)
		{
			break;
		}
		p2->next = new ListNode(j);
		p2 = p2->next;
	}
	ListNode* l3 = addTwoNumbers(l1->next, l2->next);
	ListNode* p3=l3;
	while (p3->next != NULL)
	{
		cout << p3->val;
		p3 = p3->next;
	}
	cout << p3->val;

	system("pause");
}