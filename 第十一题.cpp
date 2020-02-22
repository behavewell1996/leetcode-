#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
//最优双指针法
//学会了用数组给容器赋值

//动态规划
int maxArea1(vector<int>& height) {
	int hsize = height.size();
	vector<int> dp(hsize + 1, 0);
	if (hsize == 2)
	{
		dp[hsize] = min(height[0], height[1]);
	}
	else
	{
		dp[2] = min(height[0], height[1]);
		for (int i = 3; i<hsize + 1; i++)
		{
			int tmp, ri(0);
			for (int j = 0; j<i - 1; j++)
			{
				tmp = (i - 1 - j)*min(height[j], height[i-1]);
				ri = max(ri, tmp);
			}
			dp[i] = max(dp[i - 1], ri);
		}
	}
	return dp[hsize];
}

//暴力法
int maxArea2(vector<int>& height) {
	int nowmax(0);
	int tmp;
	for (int i = 1; i < height.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			tmp = (i - j)*min(height[i], height[j]);
			nowmax = max(tmp, nowmax);
		}
	}
	return nowmax;
}


//双指针
int maxArea(vector<int>& height) {
	int le(0), ri(height.size()-1), nowmax(0), tmp;
	while (le != ri)
	{
		tmp = (ri - le)*min(height[le], height[ri]);
		nowmax = max(tmp, nowmax);
		if (height[le]<height[ri])
		{
			le++;
		}
		else ri--;
	}
	return nowmax;
};
void main()
{
	int a[] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	vector<int> myVec(a, a + sizeof(a) / sizeof(a[0]));
	cout << maxArea(myVec);
	system("pause");
}