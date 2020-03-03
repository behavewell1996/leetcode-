class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> res;
		if (nums.size() == 0)
		{
			res.push_back(-1);
			res.push_back(-1);
			return res;
		}
		int le(0), ri(nums.size() - 1), mid;
		while (le != ri)
		{
			mid = le + (ri - le) / 2;
			if (nums[mid] < target)
			{
				le = mid + 1;
			}
			else ri = mid;
		}
		if (nums[le] != target)
		{
			res.push_back(-1);
			res.push_back(-1);
			return res;
		}
		res.push_back(le);
		le = 0;
		ri = nums.size() - 1;
		while (le != ri)
		{
			mid = ri - (ri - le) / 2;
			if (nums[mid] > target)
			{
				ri = mid - 1;

			}
			else
			{
				le = mid;
			}

		}
		res.push_back(le);
		return res;
	}

};