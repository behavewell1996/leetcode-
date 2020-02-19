#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <assert.h>

//求两个有序数组中位数 是 求两个有序数组第k小的特殊情况
int findKthElm(vector<int>& nums1, vector<int>& nums2, int k)
{
	//二分法
	//1、首先确定边界
	//第一个数组大小为n，第二个数组大小为m，选择在第一个数组中进行二分搜索，搜索的边界应该是(max(0,k-m),min(n,k))
	int n(nums1.size()),m(nums2.size());
	int le = max(0,k - m );
	int ri = min(n, k);
	//2、逼近 ---->剩两个的话输出左边的，三个的话 中间偏小输出右边的，中间偏大变成两个的情况
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
	//3、第k个最小值要么在nums1的第 le-1,要么在nums2的 k-le-1
	if (k - le - 1 < 0)
		return nums1[le-1];
	else if (le -1 < 0)
		return nums2[k - le - 1];
	else
		return max(nums1[le-1], nums2[k - le - 1]);
	
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int n = nums1.size() + nums2.size();
	if (n & 1){//两个数组长度和为奇数
		return findKthElm(nums1, nums2, n/2 + 1);
	}
	else{//为偶数
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