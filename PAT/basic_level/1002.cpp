#include <iostream>
#include <string>

using namespace std;

int main()
{
	

	string numStr;
	cin >> numStr;
	
	int bitSum = 0;

	for(auto bitChar : numStr)
	{
		bitSum += (bitChar - '0');
	}
    
	string numNames[10] = { "ling","yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

	int base = 1;
	while (bitSum / base >= 10)
	{
		base *= 10;
	}

	while (base != 0)
	{
		cout << numNames[bitSum / base];
		bitSum %= base;
		base /= 10;
		if (base != 0)
			cout << ' ';
	}
	cout << endl;
}
