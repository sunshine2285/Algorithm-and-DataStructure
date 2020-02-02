**知识点**

* 二分查找

**Source**：http://poj.org/problem?id=1003 

**Description**

How far can you make a stack of cards overhang a table? If you have one card, you can create a maximum overhang of half a card length. (We're assuming that the cards must be perpendicular to the table.) With two cards you can make the top card overhang the bottom one by half a card length, and the bottom one overhang the table by a third of a card length, for a total maximum overhang of 1/2 `+` 1/3 `=` 5/6 card lengths. In general you can make *n* cards overhang by 1/2 `+` 1/3 `+` 1/4 `+` ... `+` 1/(*n* `+` 1) card lengths, where the top card overhangs the second by 1/2, the second overhangs tha third by 1/3, the third overhangs the fourth by 1/4, etc., and the bottom card overhangs the table by 1/(*n* `+` 1). This is illustrated in the figure below. 

![](hangover.jpg)

**Input**

The first line of input will be a positive integer indicating how many data sets will be included (N). Each of the next N lines will contain the X and Y Cartesian coordinates of the land Fred is considering. These will be floating point numbers measured in miles. The Y coordinate will be non-negative. (0,0) will not be given. 

**Output**

For each test case, output the minimum number of cards necessary to achieve an overhang of at least c card lengths. Use the exact output format shown in the examples. 

**Sample Input**

```
1.00
3. 71
0.04
5.19
0.00
```

**Sample Output**

```
3 card(s)
61 card(s)
1 card(s)
273 card(s)
```

**Code** *(cpp)*

```c++
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	//离线计算所有可能的长度值
	const int count = 278;
	double lens[count] = {0};
	double sum = 0;
	for (int i = 2; i <= count; ++i)
	{
		sum += (1.0/i);
		lens[i-1] = sum;
	}

	double len = 0;
	cin >> len;
	while (len != 0.00)
	{
		//二分查找不小于len长度的最少卡片数量
		int left = 0;
		int right = 277;
		int mid = 0;
		while (right-left > 1)
		{
			mid = (left + right) / 2;
			if(lens[mid] == len)
			{
				// cout << "[-] " << mid << " " << lens[mid] << " = " << len << endl;
				cout << mid << " card(s)" << endl;
				break;
			}else if(lens[mid] > len)
			{
				right = mid;
				// cout << "[-] " << mid << " " << lens[mid] << " > " << len << endl;
			}
			else
			{
				left = mid;
				// cout << "[-] " << mid << " " << lens[mid] << " < " << len << endl;
			}
			// cout << left << ' ' << right << ' ' << mid << endl;
		}
		if (right-left == 1)
		{
			cout << right << " card(s)" << endl;
		}
		cin >> len;
	}
	return 0;
}
```

