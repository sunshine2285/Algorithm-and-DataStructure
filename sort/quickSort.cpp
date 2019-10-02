#include <iostream>

using namespace ::std;

template <class T>
void quickSort(T* sequence, int left, int right)
{
    for (int i = 0; i < right; ++i)
    {
        cout << sequence[i] << endl;
    }
    
}

int main(int argc, char const *argv[])
{
    int num[7] = {4, 7, 1, 3, 8, 2, 11};
    quickSort(num, 0, 7);

    return 0;
}
