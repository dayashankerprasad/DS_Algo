/**
 * Given a string, find if its letters can be rearranged in such a way that no two same characters come next to each other.
 * 
 * Input: "aappp" 
 * Output: "papap" 
 * Explanation: In "papap", none of the repeating characters come next to each other.
 * 
 * Input: S = "aaab" 
 * Output: ""
 * Explanation: String cannot be made without repeating characters next to each other.
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

std::pair<char, int32_t> maxFrequency(unordered_map<char, int32_t> const &charFreq)
{
	if (charFreq.size() == 1)
		return {charFreq.begin()->first, charFreq.begin()->second};

	char ch;
	int32_t freq = 0;
	
	for (auto const &val: charFreq)
	{
		if (val.second >= freq)
		{
			freq = val.second;
			ch = val.first;
		}
	}

	return {ch, freq};
}

string rearrage(string const &str)
{
	if (str.empty())
		return "";

	unordered_map<char, int32_t> charFreq;

	for (char ch: str)
		++charFreq[ch];

	string newStr;
	char prevChar = 0;

	while (true)
	{
		auto [ch, freq] = maxFrequency(charFreq);

		if (ch ==  prevChar)
			return "";

		newStr.append(1, ch);
		charFreq[ch]--;

		if (charFreq[ch] == 0)
			charFreq.erase(ch);

		if (charFreq.empty())
			break;

		prevChar = ch;
	} 

	return newStr;
}

int32_t main()
{
	cout << rearrage("aappp") << endl; // papap
	cout << rearrage("aaab") << endl;  // ""
	return 0;
}
