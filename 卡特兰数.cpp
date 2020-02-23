#include <iostream>
using namespace std;

int buy_ways(int n,int m, int money_5, int money_10)
{
	if (money_5 == 0&&n>=1&&m>=0)
	{
		return n*buy_ways(n - 1, m, money_5 + 1, money_10);
	}
	else if (money_5 == 0 && n == 0 && m >= 1)
	{
		return 0;
	}
	else if(money_5>0&&n>=1&&m>=1)
	{
		return n*buy_ways(n - 1, m, money_5 + 1, money_10) + m*buy_ways(n, m - 1, money_5 - 1, money_10 + 1);
	}
	else if (money_5> 0 && n >= 1 && m == 0)
	{
		return n*buy_ways(n - 1, m, money_5 + 1, money_10);
	}
	else if (money_5 > 0 && n == 0 && m >= 1)
	{
		return m*buy_ways(n, m - 1, money_5 - 1, money_10 + 1);
	}
	if (n == 0 && m == 0)
	{
		return 1;
	}
}


void main()
{
	cout << buy_ways(4,4,0,0) << endl;
	system("pause");
}