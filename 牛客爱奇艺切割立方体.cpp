#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//ע��int������  int ���10λ10����
__int64 numblock(__int64 x, __int64 y, __int64 z, __int64 k)
{
	vector<int> myVec;
	myVec.push_back(x);
	myVec.push_back(y);
	myVec.push_back(z);
	sort(myVec.begin(), myVec.end());

	if (k == 0)
	{
		return 1;
	}
	else if (k <= 3 * (myVec[0] - 1))
	{
		if (k % 3 == 0)
		{
			return (k / 3 + 1)*(k / 3 + 1)*(k / 3 + 1);
		}
		else if (k % 3 == 1)
		{
			return (k / 3 + 2)*(k / 3 + 1)*(k / 3 + 1);
		}
		else{
			return (k / 3 + 2)*(k / 3 + 1)*(k / 3 + 1);
		}
	}
	else if (k>3 * (myVec[0] - 1) && k <= myVec[0] + 2 * myVec[1]-3)
	{
		if ((k - myVec[0] + 1) % 2 == 0)
		{
			return (myVec[0])*((k - myVec[0] + 1) / 2 + 1)*((k - myVec[0] + 1) / 2 + 1);
		}
		else
		{
			return (myVec[0])*((k - myVec[0] + 1) / 2 + 1)*((k - myVec[0] + 1) / 2 + 2);
		}
	}
	else if (k>myVec[0] + 2 * myVec[1]-3 && k <= x + y + z - 3)
	{
		return (myVec[0])*(myVec[1])*(k - myVec[0] - myVec[1] + 3);
	}
	else if (k>x + y + z - 3)
	{
		return numblock(x, y, z, x + y + z - 3);
	}
}
int main()
{
	__int64 a, b, c, d;
	while (cin >> a >> b >> c >> d)//ע��while������case
	cout<<numblock(a, b, c, d)<<endl;
	return 0;
}

// clang++��������         __int64_t