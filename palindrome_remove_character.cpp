/**
 * Return true/false depending upon if removing a character from a given string makes it palindrome
 */

#include <string>
#include <iostream>

using namespace std;

bool isPalindrom(string const &str, int32_t left,  int32_t right)
{
	for(; left < right; ++left,  --right)
	{
		if (str[left] != str[right])
			return false;
	}
	return true;
}
bool isPalindromeIfACharacterRemoved(string const &str)
{
	int32_t left = 0, right = str.length() - 1;

	while (left < right)
	{
		if (str[left] ==  str[right])
		{
			++left;
			--right;
		}
		else
		{
			if (isPalindrom(str, left + 1,  right))
				return true;
			else if (isPalindrom(str, left, right - 1))
				return true;
			return false;
		}
	}
	return true;
}

int32_t main()
{
	cout <<  isPalindromeIfACharacterRemoved("abca") <<  endl; // removing 'c' will make string palindrome => true
	cout <<  isPalindromeIfACharacterRemoved("aabb") <<  endl; // removing any one char will not make string palindrome => false

	return 0;
}
