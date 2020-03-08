#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool canPartition(vector<int>& nums) {
	if (nums.size() == 0) return false;
	//�������� sum���Ϊ20000 �൱�ڱ�������Ϊ10^5�� �ڱ�����Ѱ��Ԫ��ʹ�øպ�����Ϊsum/2 ������dp����
	int sum = 0;
	for (auto w : nums)
	{
		sum += w;
	}
	if (sum % 2 == 1) return false;
	vector<vector<bool>> dp(nums.size(), vector<bool>(sum / 2 + 1, false));
	if (nums[0]<= sum/2) dp[0][nums[0]] = true;
	for (int i = 1; i < nums.size(); i++)
	{
		for (int j = 1; j < sum / 2 + 1; j++)
		{

			dp[i][j] = j >= nums[i] ? (dp[i - 1][j] || dp[i - 1][j - nums[i]]) : dp[i - 1][j];
		}
		
	}
	return dp[nums.size()-1][sum / 2];

}


void main()
{
	vector<int> myVec{ 200 };
	cout<<canPartition(myVec);
	system("pause");
}