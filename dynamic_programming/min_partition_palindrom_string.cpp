/*
 * Given a string A, partition A such that every substring of the partition is a palindrome.
 * Return the minimum cuts needed for a palindrome partitioning of A.
 * 
 * Input 1:
    A = "aba"
   Output 1:
    0
   Explanation 1:
    "aba" is already a palindrome, so no cuts are needed.

   Input 2:
    A = "aab"
   Output 2:
    1
   Explanation 2:
    Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
 */

#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

bool checkIfPalindrome(string const &str)
{
	for (int start = 0, end = str.size() - 1; start < end; ++start, --end)
	{
		if (str[start] != str[end])
			return false;
	}
	return true;
}

int minimumParition(string const &str)
{
	int const size = str.length();

	vector<int> dp(size, INT_MAX);

	for(int j = 0; j < size; ++j)
	{
		if(checkIfPalindrome(str.substr(0, j + 1)))
			dp[j] = 0;
		else
		{
			for(int i = 0; i < j; ++i)
				if(checkIfPalindrome(str.substr(i + 1, j - i)))
					dp[j] = min(dp[j], 1 + dp[i]);
			}
	}

	    return dp[size - 1];
}

int main()
{
	cout << minimumParition("aab") << endl;
	cout << minimumParition("ababb") << endl;
	cout << minimumParition("abcba") << endl;

	return 0;
}
