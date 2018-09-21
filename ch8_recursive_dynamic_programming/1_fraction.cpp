#include <iostream>
#include <stdio.h>  // for printf

using namespace std;

int fraction(int n, int *memo)
{
    if (0 > n) 
        return 0;
    else if (memo[n] > 0)
        return memo[n];
    else
    {
        memo[n] = fraction(n-1, memo) + fraction(n-2, memo) + fraction(n-3, memo);
        return memo[n];
    }
}

int fraction(int n)
{
    int *memo = new int[n+1];
    memset(memo, -1, sizeof(int) * (n+1));
    memo[0] = 1;    // terminate condition

    int value = fraction(n, memo);
    if (memo)
        delete [] memo;
    return value;
}

int main()
{
        const int checkInt = 6;
        for (int i = 0; i < checkInt; ++i)
            printf("fraction(%d) = %d\n", i, fraction(i));
	return 0;
}
