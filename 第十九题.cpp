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

 //�ݹ������񷽷�  �����Ǽ�¼�����鳤�� Ȼ���ָ���ĵ�����n��ɾ��
 //�ú�ѧϰ...
 class Solution {
 public:
	 int cur = 0;
	 ListNode* removeNthFromEnd(ListNode* head, int n) {
		 if (!head) return NULL;   //�������ؿ�
		 head->next = removeNthFromEnd(head->next, n);
		 cur++;  //����һ���+1
		 if (n == cur) return head->next;    //return ������Ե�һ���������������յĽ�����������ж����鳤��(cur)�Ƿ����n�����������Ҫ��һ�ڣ���������򱣳�head
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
	cout << s1.cur << endl;  //˵��������n��
	system("pause");
}