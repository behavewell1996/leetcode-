#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <assert.h>

//����������������λ�� �� ���������������kС���������
int findKthElm(vector<int>& nums1, vector<int>& nums2, int k)
{
	//���ַ�
	//1������ȷ���߽�
	//��һ�������СΪn���ڶ��������СΪm��ѡ���ڵ�һ�������н��ж��������������ı߽�Ӧ����(max(0,k-m),min(n,k))
	int n(nums1.size()),m(nums2.size());
	int le = max(0,k - m );
	int ri = min(n, k);
	//2���ƽ� ---->ʣ�����Ļ������ߵģ������Ļ� �м�ƫС����ұߵģ��м�ƫ�������������
	while (le < ri)
	{
		int mid = le + (ri - le) / 2;
		if (nums1[mid] < nums2[k - mid - 1])
		{
			le = mid+1;
		}
		else
		{
			ri = mid;
		}
	}
	//3����k����СֵҪô��nums1�ĵ� le-1,Ҫô��nums2�� k-le-1
	if (k - le - 1 < 0)
		return nums1[le-1];
	else if (le -1 < 0)
		return nums2[k - le - 1];
	else
		return max(nums1[le-1], nums2[k - le - 1]);
	
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int n = nums1.size() + nums2.size();
	if (n & 1){//�������鳤�Ⱥ�Ϊ����
		return findKthElm(nums1, nums2, n/2 + 1);
	}
	else{//Ϊż��
		return (findKthElm(nums1, nums2, n/2) + findKthElm(nums1, nums2, n/2 + 1)) / 2.0;
	}
}
void main()
{
	vector<int> nums1, nums2;
	nums1.push_back(1);
	nums1.push_back(2);
	nums2.push_back(3);
	nums2.push_back(4);
	cout << findMedianSortedArrays(nums1, nums2) << endl;
	system("pause");
}