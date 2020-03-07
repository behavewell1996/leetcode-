#include <iostream>
using namespace std;
#include <vector>
class Solution {
private:
	vector<vector<int>> myVec;
public:
	void permute(vector<int>&nums, vector<int> tmp)
	{
		if (nums.size() == 0)
		{
			myVec.push_back(tmp);
			return;
		}
		for (int i = 0; i<nums.size(); i++)
		{
			vector<int> te = tmp;
			te.push_back(nums[i]);
			vector<int> rest = nums;
			rest.erase(i + rest.begin());
			permute(rest, te);
		}

	}
	vector<vector<int>> permute(vector<int>& nums) {
		if (nums.size() == 0) return myVec;
		vector<int> tmp;
		permute(nums, tmp);
		return myVec;
	}
};