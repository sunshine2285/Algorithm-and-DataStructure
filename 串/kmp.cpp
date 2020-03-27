#include <iostream>
#include <string>

using namespace std;

void getNextArray(const string &target, int *next)
{
	int head = -1;
	int tail = 0;
	int len = target.length();
	next[0] = -1;

	while (tail < len)
	{
		if (head == -1 || target[head] == target[tail])
		{
			++head;
			++tail;
			next[tail] = head;
			/*if (target[head] != target[tail])
			{
				next[tail] = head;
			}
			else
			{
				next[tail] = next[head];
			}*/
		}
		else
		{
			head = next[head];
		}
	}
}

int kmp(const string &search, const string &target)
{
	int slen = search.length();
	int tlen = target.length();
	int *next = new int[tlen + 1];
	getNextArray(target, next);

	for (int i = 0; i < target.length(); i++)
	{
		cout << next[i];
	}
	cout << endl;
	

	int sindex = 0;
	int tindex = 0;

	while (sindex < slen && tindex < tlen)
	{
		if (search[sindex] == target[tindex])
		{
			++sindex;
			++tindex;
		}
		else if (tindex != 0)
			tindex = next[tindex];
		else
			++sindex;
	}

	delete[] next;

	if (tindex == tlen)
		return sindex - tlen;
	else
		return -1;
}

int main()
{
	string s = "abcdabcabc";
	string t = "cabc";

	while (true)
	{
		cin >> s;
		cin >> t;

		cout << kmp(s, t) + 1 << endl;
	}

	return 0;
}
