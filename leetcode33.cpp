#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;
		return search(nums, target, 0, nums.size() - 1);
	}

	int search(vector<int>& nums, int target, int le, int ri)
	{
		if (le == ri)
		{
			return nums[le] == target ? le : -1;
		}
		int m = le + (ri - le) / 2;
		if (nums[m + 1] <= nums[ri])  //说明右边有序
		{
			int left = m + 1;
			int right = ri;
			while (left != right)
			{
				int mid = left + (right - left) / 2;
				if (target>nums[mid]) left = mid + 1;
				else right = mid;
			}
			if (nums[left] == target) return left;
			else return search(nums, target, le, m);
		}
		else //说明左边有序
		{
			int left = le;
			int right = m;
			while (left != right)
			{
				int mid = left + (right - left) / 2;
				if (target>nums[mid]) left = mid + 1;
				else right = mid;
			}
			if (nums[left] == target) return left;
			else return search(nums, target, m + 1, ri);
		}
	}
};