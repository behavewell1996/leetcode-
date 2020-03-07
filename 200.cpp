#include <vector>
#include <iostream>
using namespace std;
class Solution {
private:
	int d[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };//上 右 下 左
	int m, n;  //行、列
	vector<vector<bool>> visited;
	bool inArea(int x, int y)
	{
		return x >= 0 && x<m&&y >= 0 && y<n;
	}
	//从grid[x][y]位置开始 进行floodfill
	void dfs(vector<vector<char>>& grid, int x, int y)
	{
		//对于当前点有4个方向 坐标变换用4行2列数组给出 {{},{},{},{}} 每一行表示一个方向 原x坐标+第i行第1列 原y坐标+第i行第2列
		//对于新的4个点分别重复dfs过程 
		for (int i = 0; i<4; i++)
		{
			//第i行的走法
			int newx = x + d[i][0];
			int newy = y + d[i][1];
			//这个方向能不能走&&这个点没被标记过（不重复遍历）&&这个点是岛屿
			if (inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == '1')
			{
				visited[newx][newy] = true;
				dfs(grid, newx, newy);
			}
		}
		return;
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		m = grid.size();
		if (m == 0) return 0;
		n = grid[0].size();

		visited = vector<vector<bool>>(m, vector<bool>(n, false));

		int res = 0;
		//检查每一个点
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				//对于没遍历过的点&&为岛屿的点 更改状态和遍历
				if (grid[i][j] == '1'&&!visited[i][j])
				{
					visited[i][j] = true;
					res++;
					//floodfill算法 把和这个坐标相连的都fill
					dfs(grid, i, j);
				}
			}
		}
		return res;


	}
};