/*
 * Find longest palindrom substring from a given string. If there is no palindrom substring,
 * first character of given string should return.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string longestPalindrome(string const &s)
{
	if (s.length() <= 1)
		return s;

	string str;

	for (int right = s.length() - 1; right >=0; --right)
	{
		for(int left = 0; left < right; ++left)
		{
			int l = left, r = right;

			for(;l < r && s[l] != s[r]; --r);

			if (left == right)
				continue;

			if (l < r)
			{
				int tempLeft = l, tempRight = r;

				for(; s[tempLeft] == s[tempRight] && tempLeft < tempRight; ++tempLeft, --tempRight);

				if (tempLeft >= tempRight)
				{
					string const tempstr = s.substr(l, r - l + 1);
					if (tempstr.length() > str.length())
							str = tempstr;
				}
			}
		}
	}

	if (str.empty())
		return s.substr(0, 1);

	return str;
}

int32_t main()
{
	cout << longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << endl;
	cout << longestPalindrome("abcdbbfcba") << endl;
	cout << longestPalindrome("aaabaaaa") << endl;
	cout << longestPalindrome("babadada") << endl;
	cout << longestPalindrome("abcda") << endl;
	cout << longestPalindrome("aa") << endl;
	return 0;
}


