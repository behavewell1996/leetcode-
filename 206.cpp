#include <iostream>
using namespace std;
#include <vector>
#include <stack>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reverseList(ListNode* head)
{
	stack<ListNode*> mySta;
	ListNode* move = head;
	while (move!= NULL)
	{
		mySta.push(move);
		move = move->next;
	}
	ListNode* res = mySta.top();
	move = res;
	while (mySta.size() >=2)
	{
		mySta.pop();
		move->next = mySta.top();
		move = move->next;
	}
	move->next = NULL;
	return res;
}


void main()
{
	ListNode* p = new ListNode(1);
	p->next = new ListNode(2);
	p->next->next = new ListNode(3);
	p->next->next->next = new ListNode(4);
	p->next->next->next->next = new ListNode(5);
	reverseList(p);
	system("pause");
}