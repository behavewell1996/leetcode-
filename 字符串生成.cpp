#include <iostream>
using namespace std;
#include <string>
#include <ctime>

string generate_string(int n)
{
	if (n == 0) return "";
	else
	{
		int tmpint = rand() % 100;
		while (!(tmpint <= 57 && tmpint >= 48) && !(tmpint >= 97 && tmpint <= 122) && !(tmpint >= 65 && tmpint <= 90))
		{
			tmpint = rand() % 100;
		}
		char tmp = (char)tmpint;
		return generate_string(n-1) + tmp;
	}
}

void main()
{
	cout << generate_string(7);
	system("pause");
}