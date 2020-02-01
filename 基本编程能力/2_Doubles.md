**Source**： http://poj.org/problem?id=1552 

**Description**

As part of an arithmetic competency program, your students will be given randomly generated lists of from 2 to 15 unique positive integers and asked to determine how many items in each list are twice some other item in the same list. You will need a program to help you with the grading. This program should be able to scan the lists and output the correct answer for each one. For example, given the list `1 4 3 2 9 7 18 22`
your program should answer 3, as 2 is twice 1, 4 is twice 2, and 18 is twice 9.

**Input**

The input will consist of one or more lists of numbers. There will be one list of numbers per line. Each list will contain from 2 to 15 unique positive integers. No integer will be larger than 99. Each line will be terminated with the integer 0, which is not considered part of the list. A line with the single number -1 will mark the end of the file. The example input below shows 3 separate lists. Some lists may not contain any doubles.

**Output**

The output will consist of one line per input list, containing a count of the items that are double some other item.

**Sample Input**

```
1 4 3 2 9 7 18 22 0
2 4 8 10 0
7 5 11 13 1 3 0
-1
```

**Sample Output**

```
3
2
0
```

**Code** *(cpp)*

```c++
#include <iostream>

using namespace std;

int main()
{
	//注意2-15个数字再加上最后一个0，最多有16个数 
	int num[16] = {0};
	do
	{
		cin >> num[0];
		if(num[0] == -1)
			break;
			
		int index = 1;
		do
		{ 
			cin >> num[index];
			if(num[index] == 0)
				break;
			++index;
		}while(true);
		
		int count = 0;
		for(int i = 0; i < index; ++i)
		{
			for(int j = i; j < index; ++j)
			{
				//可能前一个数是后一个数两倍，也可能后一个数是前一个数两倍 
				if(num[j] == num[i]*2 || num[i] == num[j] * 2)
					++count;
			}
		}
		cout << count << endl;
	}while(true);
	
	return 0;
} 
```

