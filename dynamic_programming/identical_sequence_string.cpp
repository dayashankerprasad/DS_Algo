/*
Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.
Input:
    A = "rabbbit" 
    B = "rabbit"

Output:
    3

Explanation:
    These are the possible removals of characters:
        => A = "ra_bbit" = B
        => A = "rab_bit" = B
        => A = "rabb_it" = B

	_ is the removed character.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int distinctWays(string const &a, string const &b)
{
    vector<vector<int>> dp(a.size(), vector<int>(b.size(), 0));

    int const n = a.size();
    int const m = b.size();

    if(a[0] == b[0])
        dp[0][0] = 1;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if (i == 0);
            else if(j ==0)
            {
                if(a[i] == b[j])
                    dp[i][j] = dp[i - 1][j] + 1; //if matached top charac + 1
                else
                    dp[i][j] = dp[i - 1][j]; //if not matched then top charac combinations
            }
            else
            {
                if(a[i] == b[j])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; //nCr=(n-1)C(r-1) + (n-1)Cr
                else
                    dp[i][j]=dp[i - 1][j]; //top level combo bring down
            }
        }
    }
    return dp[n - 1][m - 1];
}

int main()
{
	cout << distinctWays("rabbbit", "rabbit") << endl;
	return 0;
}
