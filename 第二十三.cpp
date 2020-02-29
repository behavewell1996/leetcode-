#include <iostream>
using namespace std;
#include<queue>
#include<vector>
#include <algorithm>
#include <functional>
//Pr_pred表示谓词
//typename_Pr 谓词类名
//Fn1_Func 一元函数对象
//Fn2_Func 二元函数对象

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Listgreater
{
	bool operator()(ListNode* &p1, ListNode* &p2)
	{
		return p1->val > p2->val;
	}
};


ListNode* mergeKLists(vector<ListNode*>& lists)
{
	priority_queue<ListNode*, vector<ListNode*>, Listgreater> myque;
	for (auto p : lists)
	{
		if (p != NULL) myque.push(p);
	}
	ListNode* res = new ListNode(-1);
	ListNode* moveres = res;
	while (myque.size() != 0)
	{
		moveres->next = myque.top();
		if (myque.top()->next != NULL) myque.push(myque.top()->next);
		myque.pop();
		moveres = moveres->next;
	}
	return res->next;
}

void main()
{

	priority_queue<int,vector<int>,greater<int>> my;    //小的先进
	my.push(1);
	my.push(3);
	my.push(5);
	cout << my.top();
	my.pop();
	cout << my.top();
	my.pop();
	cout << my.top();
	system("pause");
}