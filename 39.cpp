#include <iostream>
using namespace std;
#include <vector>


vector<vector<int>> mySum(vector<int>& candidates, int index, int target)
{
	vector<vector<int>> res;
	if (index == 0)
	{
		if (target%candidates[0] == 0)
		{
			vector<int> subres(target / candidates[0], candidates[0]);
			res.push_back(subres);
		}
		return res;
	}
	res = mySum(candidates, index - 1, target);
	if (candidates[index] > target) return res;
	int i = 1;
	while (target - candidates[index] * i >= 0)
	{
		vector<vector<int>> tmp = mySum(candidates, index - 1, target - i*candidates[index]);
		for (auto vec : tmp)
		{
			for (int j = 0; j < i; j++)
			{
				vec.push_back(candidates[index]);
			}
			res.push_back(vec);
		}
		i++;
	}
	return res;
}




void main()
{
	system("pause");
}