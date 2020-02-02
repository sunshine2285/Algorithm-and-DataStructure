**Source**： http://poj.org/problem?id=1316

**Description**

 In 1949 the Indian mathematician D.R. Kaprekar discovered a class of numbers called self-numbers. For any positive integer n, define d(n) to be n plus the sum of the digits of n. (The d stands for digitadition, a term coined by Kaprekar.) For example, d(75) = 75 + 7 + 5 = 87. Given any positive integer n as a starting point, you can construct the infinite increasing sequence of integers n, d(n), d(d(n)), d(d(d(n))), .... For example, if you start with 33, the next number is 33 + 3 + 3 = 39, the next is 39 + 3 + 9 = 51, the next is 51 + 5 + 1 = 57, and so you generate the sequence

33, 39, 51, 57, 69, 84, 96, 111, 114, 120, 123, 129, 141, ...
The number n is called a generator of d(n). In the sequence above, 33 is a generator of 39, 39 is a generator of 51, 51 is a generator of 57, and so on. Some numbers have more than one generator: for example, 101 has two generators, 91 and 100. A number with no generators is a self-number. There are thirteen self-numbers less than 100: 1, 3, 5, 7, 9, 20, 31, 42, 53, 64, 75, 86, and 97.

**Input**

 No input for this problem. 

**Output**

Write a program to output all positive self-numbers less than 10000 in increasing order, one per line. 

**Sample Input**

**Sample Output**

```
1
3
5
7
9
20
31
42
53
64
 |
 |       <-- a lot more numbers
 |
9903
9914
9925
9927
9938
9949
9960
9971
9982
9993
```

**Code** *(cpp)*

```c++
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n = 0;
	cin >> n;
	int sum = 0;
	int lastHours = 0;
	int currentHours = 0;
	int speed = 0;
	while (n != -1)
	{

		for (int i = 0; i < n; ++i)
		{
			cin >> speed >> currentHours;
			sum += (currentHours - lastHours) * speed;
			lastHours = currentHours;
		}

		cout << sum << " miles" << endl;

		sum = 0;
		lastHours = 0;
		cin >> n;
	}

	return 0;
}
```

