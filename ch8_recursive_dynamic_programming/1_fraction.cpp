#include <iostream>

using namespace std;

void dumpArray(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
        printf("arr[%d]: %d\n", i, arr[i]);
}

int fraction(int n, int *memo)
{
    if (0 > n) 
        return 0;
    else if (memo[n] > 0)
        return memo[n];
    else
    {
        memo[n] = fraction(n-1, memo) + fraction(n-2, memo) + fraction(n-3, memo);
//        dumpArray(memo, n);
        return memo[n];
    }
}

int val(int n)
{
    int *memo = new int(5);
    memo[0] = 1;    // terminate condition

    return fraction(n, memo);
}

int main()
{
	cout << "Hello World\n";
        const int checkInt = 6;
        for (int i = 0; i < checkInt; ++i)
            printf("fraction(%d) = %d\n", i, val(i));
	return 0;
}
