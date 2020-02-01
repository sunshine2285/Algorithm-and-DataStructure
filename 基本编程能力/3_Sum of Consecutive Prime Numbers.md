**知识点**：

* 离线计算：在指处理多个测试数据是

**Source**： http://poj.org/problem?id=2739 

**Description**

Some positive integers can be represented by a sum of one or more consecutive prime numbers. How many such representations does a given positive integer have? For example, the integer 53 has two representations 5 + 7 + 11 + 13 + 17 and 53. The integer 41 has three representations 2+3+5+7+11+13, 11+13+17, and 41. The integer 3 has only one representation, which is 3. The integer 20 has no such representations. Note that summands must be consecutive prime
numbers, so neither 7 + 13 nor 3 + 5 + 5 + 7 is a valid representation for the integer 20.
Your mission is to write a program that reports the number of representations for the given positive integer.

**Input**

The input is a sequence of positive integers each in a separate line. The integers are between 2 and 10 000, inclusive. The end of the input is indicated by a zero.

**Output**

The output should be composed of lines each corresponding to an input line except the last zero. An output line includes the number of representations for the input integer as the sum of one or more consecutive prime numbers. No other characters should be inserted in the output.

**Sample Input**

```
2
3
17
41
20
666
12
53
0
```

**Sample Output**

```
1
1
2
3
0
0
1
2
```

**Code** *(cpp)*

```c++
#include <iostream>
#include <vector>

using namespace std;

void getPrimer(vector<int> &primer, int end)
{
	int i = 0, j = 0;
	primer.push_back(2);
	primer.push_back(3);
	if (end <= 3)
		return;
	for (i = 4; i < end; ++i)
	{
		bool isPrimer = true;
		for (vector<int>::iterator iter = primer.begin(); iter < primer.end(); ++iter)
		{
			if(i % (*iter) == 0)
			{
				isPrimer = false;
				break;
			}
		}
		if(isPrimer)
			primer.push_back(i);
	}
}

int main(int argc, char const *argv[])
{
	vector<int> primer;
	getPrimer(primer, 10000);

	int num = 0;
	cin >> num;
	while (num != 0)
	{
		int count = 0;
		for(vector<int>::iterator iter0 = primer.begin(); (*iter0) <= num || iter0 < primer.end(); ++iter0)
		{
			int sum = 0;
			for (vector<int>::iterator iter1 = iter0; sum < num || iter1 < primer.end(); iter1++)
			{
				sum += (*iter1);
				if(sum == num)
					++count;
			}
		}
		cout << count << endl;
		cin >> num;
	}
	

	return 0;
}

```

