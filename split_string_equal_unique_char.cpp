/**
 * Given a string S, we can split S into 2 strings: S1 and S2. 
 * Return the number of ways S can be split such that the number of unique characters between S1 and S2 are the same.

 * Input: "aaaa"
 * Output: 3
 * Explanation: we can get a - aaa, aa - aa, aaa- a

 * Input: "ababa"
 * Output: 2
 * Explanation: ab - aba, aba - ba
 */

#include <map>
#include <string>
#include <iostream>

using namespace std;

uint32_t uniqueCount(string data)
{
	std::map<char, uint32_t> count;

	for(uint32_t i = 0; i < data.length(); ++i)
		++count[data[i]];

	return count.size();
}

uint32_t noOfWaysToSplit(string data)
{
	uint32_t result = 0;

	for(uint32_t i = 1; i < data.length(); ++i)
	{
		string const leftPart = data.substr(0, i);
		string const rightPart = data.substr(i);

		if (uniqueCount(leftPart) == uniqueCount(rightPart))
			++result;
	}

	return result;
}

int main()
{
	cout << noOfWaysToSplit("ababa") << endl;
	cout << noOfWaysToSplit("abc") << endl;
	cout << noOfWaysToSplit("aaaa") << endl;

	cout << "Terminating main()..." << endl;

	return 0;
}

