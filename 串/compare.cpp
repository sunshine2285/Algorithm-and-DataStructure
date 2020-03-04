int compare(const string &search, const string &target)
{
	int slen = search.length();
	int tlen = target.length();

	int sindex = 0;
	int tindex = 0;

	while (sindex < slen && tindex < tlen)
	{
		if(search[sindex] == target[tindex])
		{
			++sindex;
			++tindex;
		}
		else
		{
			sindex -= (tindex - 1);
			tindex = 0;
		}
	}

	if (tindex == tlen)
	{
		return (sindex - tindex);
	}
	else
	{
		return -1;
	}
}