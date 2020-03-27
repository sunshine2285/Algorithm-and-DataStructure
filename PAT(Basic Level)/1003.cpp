#include <iostream>
#include <string>

using namespace std;

bool isPAT(string &str) 
{
	int count[3] = { 0,0,0 };
	int pos = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		if(str[i] == 'A')
		{
			++count[pos];
		}
		else if(str[i] == 'P' && pos == 0)
		{
			pos = 1;
		}
		else if(str[i] == 'T' && pos == 1)
		{
			pos = 2;
		}
		else
		{
			return false;
		}
	}
	return pos == 2 && count[1] > 0 && count[2] == count[0] * count[1];
}

int main()
{
	int n = 0;
	cin >> n;
	while (n > 0)
	{
		string str;
		cin >> str;
		if (isPAT(str))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		--n;
	}
}