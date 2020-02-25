#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* newList=new ListNode(-1);
	ListNode* pNew = newList;
	while (l1 != NULL && l2 != NULL)
	{
		if (l1->val <= l2->val)
		{
			pNew->next = l1;
			pNew = pNew->next;
			l1 = l1->next;
		}
		else
		{
			pNew->next = l2;
			pNew = pNew->next;
			l2 = l2->next;
		}		
	}
	if (l1 == NULL)
	{
		pNew->next = l2;
	}
	if (l2 == NULL)
	{
		pNew->next = l1;
	}
	return newList->next;
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
		cout << result->val<<"	";
		result = result->next;
	}
	system("pause");
}