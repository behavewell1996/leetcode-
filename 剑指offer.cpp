#include <iostream>
using namespace std;
#include <vector>
#include <string>
//#include <stdlib.h>
class Solution
{
private:
	int m;//ÐÐ
	int n;//ÁÐ
	string s;
	vector<vector<char>> mat;
	vector<vector<bool>> isvisit;
	bool isvalid(int i, int j)
	{
		if (i >= 0 && i <= m - 1 && j >= 0 && j <= n - 1)
			return true;
		else return false;
	}

	
	bool bianli(int i, int j,int k)
	{
		int rcho[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
		if (k >= s.length()) return true;

		for (int c = 0; c < 4;c++)
		{
			int i_new = i + rcho[c][0];
			int j_new = j + rcho[c][1];
			if (isvalid(i_new, j_new) && !isvisit[i_new][j_new]&&s[k]==mat[i_new][j_new])
			{
				isvisit[i_new][j_new] = true;
				int k_new = k+1;
				return bianli(i_new, j_new,k_new);
			}		
		}
		return false;
	}
public:
	bool hasroute(string s, vector<vector<char>> mat)
	{
		if (mat.size() == 0) return false;
		this->m = mat.size();
		this->n = mat[0].size();
		this->s = s;
		this->mat = mat;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				isvisit = vector<vector<bool>>(m, vector<bool>(n, false));
				int start = 0;
				if (!isvisit[i][j]&&mat[i][j]==s[0])
				{
					isvisit[i][j] = true;
					start++;
					if( bianli(i, j,start)) return true;
				}
			}
		}

		return false;
	}
};
void main()
{
	vector<vector<char>> mat(3, vector<char>(4, 'a'));
	mat[0][0] = 'a';
	mat[0][1] = 'b';
	mat[0][2] = 't';
	mat[0][3] = 'g';
	mat[1][0] = 'c';
	mat[1][1] = 'f';
	mat[1][2] = 'c';
	mat[1][3] = 's';
	mat[2][0] = 'j';
	mat[2][1] = 'd';
	mat[2][2] = 'e';
	mat[2][3] = 'h';
	Solution s1;
	cout<<s1.hasroute("abtgscfcjdeh", mat)<<endl;

	system("pause");
}