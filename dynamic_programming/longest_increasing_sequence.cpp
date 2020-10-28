#include <iostream>
#include <vector>

using namespace std;

uint32_t longestIncreasingSequenceLength(vector<int32_t> const &array)
{
	vector<int32_t> table(array.size() * array.size(), 1);

	for(uint32_t i = 0; i < array.size(); ++i)
		for(uint32_t j = 0; j < i; ++j)
			if (array[i] > array[j] && table[i] < (table[j] + 1))
				table[i] = table[j] + 1;

	uint32_t maxLength = 0;

	for(uint32_t i = 0; i < array.size(); ++i)
		if (maxLength < table[i])
			maxLength = table[i];

	return maxLength;
}

int32_t main()
{
	cout << longestIncreasingSequenceLength({1, 2, 3, 4, 5, 3, 5, 6}) << endl;
	cout << longestIncreasingSequenceLength({1, 2, 1, 2}) << endl;
	cout << longestIncreasingSequenceLength({10, 9, 2, 3, 4, 5, 6}) << endl;

	return 0;
}
