#include<iostream>
using namespace std;
#include <vector>

void moveZeroes(vector<int>& nums) {
	int count(0), length(nums.size());
	for (int i = 0; i<length-count; i++)
	{
		if (nums[i] == 0)
		{
			for (int j = i + 1; j<length - count; j++)
			{
				nums[j - 1] = nums[j];
			}
			i--;
			count++;
		}
	}

	for (int i = 0; i<count; i++)
	{
		nums[length-1] = 0;
		length--;
	}
}

void moveZeroes1(vector<int>& nums) {
	vector<int> tmp;
	for (int i = 0; i<nums.size(); i++)
	{
		if (nums[i] != 0) tmp.push_back(nums[i]);
	}
	for (int i = 0; i<tmp.size(); i++)
	{
		nums[i] = tmp[i];
	}
	for (int i = tmp.size(); i < nums.size();i++)
	{
		nums[i] = 0;
	}
}

void moveZeroes2(vector<int>& nums)
{
	int le(0), ri(0);
	while (ri < nums.size())
	{
		if (nums[ri] == 0)
		{
			while (nums[ri] == 0)
			{
				ri++;
				if (ri >= nums.size())
					break;
			}

		}
		nums[le] = nums[ri];
		le++;
		ri++;
	}
	for (int i = le; i < nums.size(); i++)
		nums[i] = 0;

}
void main()
{
	vector<int> myVec{ 0};
	moveZeroes2(myVec);
	for (auto i : myVec)
	{
		cout << i << endl;
	}


	system("pause");
}