#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int findkthelem(vector<int> v1, vector<int> v2, int k)
{
	int len1 = v1.size();
	int len2 = v2.size();
	//i+j = k(��v1 iǰ���Ԫ�ظ�������v2 jǰ���Ԫ�ظ�������k)
	//��ôk��СΪmax(v1[i-1],v2[j-1])
	//�߽�����    0=<i<=len1 0<=j<=len2 ע�����ﲻ�������±����ƣ�Ҫ����i��j��ʵ������
	//��iΪ�������i=0��˵������1û��ǰk��Ԫ�أ����i=len1��˵������1ȫ������ǰk��Ԫ��
	//����ʽ�� max(k-len2,0) <= i <=min(k,len1)
	int le = max(k - len2,0);
	int ri = min(k, len1 );
	int mid;
	while (le < ri)
	{
		mid = le + (ri - le) / 2;   //ż��ʱ ƫ��le
		//����������ж�����<ʱ�϶�����>ʱȴ�����������������С��һ�����ص�һ�����ڵ�
		if (v1[mid] < v2[k - mid - 1])
			le = mid + 1;
		else
			ri = mid;     

	}
	//����������˵ i��j�����������±꣬�����������������
	if (le - 1 < 0) return v2[k - le - 1];  //ȫ��v2��
	if (k - le - 1 < 0) return v1[le - 1];  //ȫ��v1��
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