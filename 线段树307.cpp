#include <iostream>
using namespace std;
#include <vector>

//知道tree中的index和对于data中index的范围 就可以往下递推
class NumArray {

public:
	vector<int> tree;
	vector<int> data;
private:
	int leftchild(int index)
	{
		return index * 2 + 1;
	}
	int rightchild(int index)
	{
		return index * 2 + 2;
	}
	void buildTree(int index, int l, int r)
	{
		if (l == r)
		{
			tree[index] = data[l];
		}
		else
		{
			int mid = l + (r - l) / 2;
			int lc(leftchild(index)), lr(rightchild(index));
			buildTree(lc, l, mid);
			buildTree(lr, mid + 1, r);
			tree[index] = tree[lc] + tree[lr];
		}
	}
	int sumRange(int index, int l, int r, int queryL, int queryR)
	{
		if (l == queryL&&r == queryR) return tree[index];
		int mid = l + (r - l) / 2;
		int lc = leftchild(index);
		int lr = rightchild(index);
		if (queryL >= mid + 1)  return sumRange(lr, mid + 1, r, queryL, queryR);
		else if (queryR <= mid)  return sumRange(lc, l, mid, queryL, queryR);
		else if (queryL<mid + 1 && queryR>mid)
		{
			return sumRange(lc, l, mid, queryL, mid) + sumRange(lr, mid + 1, r, mid + 1, queryR);
		}
	}
	//不停的判断要更新的dataindex i在tree的左treeindex还是右treeindex
	void update(int index, int l, int r,int i,int val)
	{
		if (l == r)
		{
			tree[index] = val;
			return;
		}
		int mid = l + (r - l) / 2;
		int lc = leftchild(index);
		int lr = rightchild(index);
		//在左边就更新左节点 在右边就更新右节点
		if (i <= mid) update(lc, l, mid, i, val);
		else  update(lr, mid + 1, r, i, val);
		tree[index] = tree[lc] + tree[lr];  //重新更新父节点
	}

public:
	NumArray(vector<int>& nums) {
		if (nums.size() > 0)
		{
			for (auto v : nums)
			{
				data.push_back(v);
			}
			tree.resize(4 * data.size());
			buildTree(0, 0, data.size() - 1);
		}
	}

	int sumRange(int i, int j) {
		if (data.size() == 0) return 0;
		return sumRange(0, 0, data.size() - 1, i, j);
	}

	//把index为i的值更新为val
	void update(int i, int val)
	{
		if (data.size() == 0) return;
		data[i] = val;  //更新data
		//更新tree
		update(0, 0, data.size() - 1,i,val);
	}
};

void main()
{
	vector<int> myVec{ -8261, 2300, -1429, 6274, 9650, -3267, 1414, -8102, 6251, -5979, -5291, -4616, -4703 };
	NumArray* mynum = new NumArray(myVec);
	for (vector<int>::iterator it = mynum->tree.begin(); it != mynum->tree.end(); it++)
	{
		cout << (*it) << "  ";
	}
	cout << mynum->sumRange(0, 8)<<endl;
	mynum->update(0, 1);
	cout << mynum->sumRange(0, 8);
	system("pause");
}