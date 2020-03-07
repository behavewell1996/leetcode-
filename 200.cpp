#include <vector>
#include <iostream>
using namespace std;
class Solution {
private:
	int d[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };//�� �� �� ��
	int m, n;  //�С���
	vector<vector<bool>> visited;
	bool inArea(int x, int y)
	{
		return x >= 0 && x<m&&y >= 0 && y<n;
	}
	//��grid[x][y]λ�ÿ�ʼ ����floodfill
	void dfs(vector<vector<char>>& grid, int x, int y)
	{
		//���ڵ�ǰ����4������ ����任��4��2��������� {{},{},{},{}} ÿһ�б�ʾһ������ ԭx����+��i�е�1�� ԭy����+��i�е�2��
		//�����µ�4����ֱ��ظ�dfs���� 
		for (int i = 0; i<4; i++)
		{
			//��i�е��߷�
			int newx = x + d[i][0];
			int newy = y + d[i][1];
			//��������ܲ�����&&�����û����ǹ������ظ�������&&������ǵ���
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
		//���ÿһ����
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				//����û�������ĵ�&&Ϊ����ĵ� ����״̬�ͱ���
				if (grid[i][j] == '1'&&!visited[i][j])
				{
					visited[i][j] = true;
					res++;
					//floodfill�㷨 �Ѻ�������������Ķ�fill
					dfs(grid, i, j);
				}
			}
		}
		return res;


	}
};