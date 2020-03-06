#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int le(0), ri(numbers.size() - 1);
		vector<int> res;
		while (le<ri)
		{
			if (numbers[le] + numbers[ri] == target)
			{
				res.push_back(le + 1);
				res.push_back(ri + 1);
				return res;
			}
			else if (numbers[le] + numbers[ri]<target)
			{
				le++;
			}
			else ri--;
		}
		return res;
	}
};