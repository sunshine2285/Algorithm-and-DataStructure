#include <iostream>

using namespace ::std;

template <class T>
int quickSort(T* sequence, int left, int right)
{
	static int count = 0;
	++count;

	//设置左右检查哨
	int i = left;
	int j = right;

	//设置基准值默认为最左边的值
	T benchmark = sequence[left];

	//归类所有元素，小于基准值的放到左边，大于基准值的在右边
	while (i != j)
	{
		//找到右边第一个比基准值小的，且索引值不能小于 i
		while (sequence[j] >= benchmark && i < j)
			--j;

		//找到左边第一个比基准值大的，且索引值不能大于 j
		while (sequence[i] <= benchmark && i < j)
			++i;

		//如果 i 与 j 没有相遇，则交换对于的 i 和 j 的位置
		if (i < j)
		{
			T temp = sequence[i];
			sequence[i] = sequence[j];
			sequence[j] = temp;
		}
	}
	//让基准值归位
	sequence[left] = sequence[i];
	sequence[i] = benchmark;

	//递归处理左右部分
	if (left < i - 1)
		quickSort(sequence, left, i - 1);
	if (i + 1 < right)
		quickSort(sequence, i + 1, right);
	return count;
}

int main(int argc, char const* argv[])
{
	int num[7] = { 4, 7, 1, 3, 8, 2, 11};
	int count = quickSort(num, 0, sizeof(num) / sizeof(int) - 1);
	for (int i = 0; i < 7; ++i)
	{
		cout << num[i] << endl;
	}
	cout << "排序次数：count" << count;

	return 0;
}
