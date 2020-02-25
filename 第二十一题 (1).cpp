#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	if (l1->val <= l2->val)
	{
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	if (l1->val > l2->val)
	{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}

void main()
{
	ListNode* p1 = new ListNode(1);
	p1->next = new ListNode(2);
	p1->next->next = new ListNode(4);

	ListNode* p2 = new ListNode(1);
	p2->next = new ListNode(3);
	p2->next->next = new ListNode(4);

	ListNode* result = mergeTwoLists(p1, p2);
	while (result != NULL)
	{
		cout << result->val << "	";
		result = result->next;
	}
	system("pause");
}