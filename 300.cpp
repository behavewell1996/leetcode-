#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int lengthOfLIS(vector<int>& nums) {
	if (nums.size() == 0) return 0;
	vector<int> dp(nums.size(), 1);
	int res(1);
	for (int i = 1; i<nums.size(); i++)
	{
		int tmp(1);
		for (int j = 0; j<i; j++)
		{
			if (nums[j]<nums[i])
			{
				tmp = max(tmp, 1 + dp[j]);
			}
		}
		dp[i] = tmp;
		res = max(dp[i], res);
	}
	return res;
}

void main()
{
	vector<int> myVec{ 10, 9, 2, 5, 3, 7, 101, 18 };
	cout << lengthOfLIS(myVec)<<endl;
	system("pause");
}