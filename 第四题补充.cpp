#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int findkthelem(vector<int> v1, vector<int> v2, int k)
{
	int len1 = v1.size();
	int len2 = v2.size();
	//i+j = k(即v1 i前面的元素个数加上v2 j前面的元素个数等于k)
	//那么k最小为max(v1[i-1],v2[j-1])
	//边界条件    0=<i<=len1 0<=j<=len2 注意这里不是数组下标限制，要分清i和j的实际意义
	//以i为例，如果i=0，说明数组1没有前k个元素；如果i=len1，说明数组1全部都是前k个元素
	//由上式得 max(k-len2,0) <= i <=min(k,len1)
	int le = max(k - len2,0);
	int ri = min(k, len1 );
	int mid;
	while (le < ri)
	{
		mid = le + (ri - le) / 2;   //偶数时 偏向le
		//根据下面的判断条件<时肯定动，>时却包含，所以如果不恒小于一定返回第一个大于的
		if (v1[mid] < v2[k - mid - 1])
			le = mid + 1;
		else
			ri = mid;     

	}
	//正如上面所说 i和j并不是数组下标，所以有两种特殊情况
	if (le - 1 < 0) return v2[k - le - 1];  //全在v2中
	if (k - le - 1 < 0) return v1[le - 1];  //全在v1中
	else return max(v1[le - 1], v2[k - le - 1]); 

}
void main()
{
	vector<int> nums1, nums2;
	nums1.push_back(1);
	nums1.push_back(3);
	nums2.push_back(2);
	cout << findkthelem(nums1, nums2,2) << endl;
	system("pause");
}