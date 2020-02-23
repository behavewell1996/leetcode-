#include <iostream>
using namespace std;
#include <vector>

int buy_ways(int n, int m)
{
	if (n > m)
	{
		return 0;
	}
	else if (n == m&&n>=1)
	{
		return buy_ways(n - 1, m);
	}
	else if (n < m&&n >= 1 && m >= 1)
		return buy_ways(n - 1, m) + buy_ways(n, m - 1);
	else if (n == 0)
		return 1;
}

void main()
{
	cout << buy_ways(5,5) << endl;
	system("pause");
}