#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode* removeNthFromEnd(ListNode* head, int n) {
	 ListNode* p1 = head;
	 ListNode* p2 = p1;
	 for (int i = 0; i < n ; i++)
	 {
		 p2 = p2->next;
	 }
	 while (p2->next != NULL)
	 {
		 p1 = p1->next;
		 p2 = p2->next;
	 }
	 ListNode* tmp = p1->next;
	 p1->next = tmp->next;
	 free(tmp);
	 return head;
 }

 //递归真是神方法  本质是记录了数组长度 然后把指定的倒数第n个删除
 //好好学习...
 class Solution {
 public:
	 int cur = 0;
	 ListNode* removeNthFromEnd(ListNode* head, int n) {
		 if (!head) return NULL;   //空链表返回空
		 head->next = removeNthFromEnd(head->next, n);
		 cur++;  //调用一遍就+1
		 if (n == cur) return head->next;    //return 都是针对第一遍迭代，即针对最终的结果，这里是判断数组长度(cur)是否等于n，如果等于则不要这一节，如果不等则保持head
		 return head;
	 }
 };

void main()
{
	ListNode* test = new ListNode(1);
	test->next = new ListNode(2);
	test->next->next = new ListNode(3);
	test->next->next->next = new ListNode(4);
	test->next->next->next->next = new ListNode(5);
	//test = removeNthFromEnd(test, 2);

	Solution s1;
	test = s1.removeNthFromEnd(test, 2);
	
	ListNode* p = test;
	while (p!= NULL)
	{
		cout << p->val;
		p = p->next;
	}
	cout << endl;
	cout << s1.cur << endl;  //说明调用了n次
	system("pause");
}