#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//O(n^2)
uint32_t longestIncreasingSequenceLength(vector<int32_t> const &array)
{
	/**
	+---------------------------------+
	| a[0] | a[1] | a[2] | ... | a[n] |
	+---------------------------------+

	+---------------------------------+
	|   1  | max1 | max2 | ... | maxn |
	+---------------------------------+
	 */
	vector<int32_t> table(array.size(), 1); //Stores max length till individual index

	for(uint32_t i = 0; i < array.size(); ++i)
		for(uint32_t j = 0; j < i; ++j)
			if (array[i] > array[j])
				table[i] = max(table[i], table[j] + 1);

	uint32_t maxLength = 0;

	for(uint32_t i = 0; i < array.size(); ++i)
		if (maxLength < table[i])
			maxLength = table[i];

	return maxLength;
}

//O(nlogn)
uint32_t longestIncreasingSequenceLength_2(vector<int32_t> const &array)
{
	vector<int32_t> seq;
	seq.push_back(array[0]);

	for (uint32_t i = 1; i < array.size(); ++i)
	{
		if (array[i] > seq.back())
			seq.push_back(array[i]);
		else
		{
			auto index = lower_bound(begin(seq), end(seq), array[i]) - begin(seq);
			seq[index] = array[i];
		}
	}

	return seq.size();
}

int32_t main()
{
	cout << longestIncreasingSequenceLength({1, 2, 3, 4, 5, 3, 5, 6}) << endl;
	cout << longestIncreasingSequenceLength({1, 2, 1, 2}) << endl;
	cout << longestIncreasingSequenceLength({10, 9, 2, 3, 4, 5, 6}) << endl;

	cout << longestIncreasingSequenceLength_2({1, 2, 3, 4, 5, 3, 5, 6}) << endl;
	cout << longestIncreasingSequenceLength_2({1, 2, 1, 2}) << endl;
	cout << longestIncreasingSequenceLength_2({10, 9, 2, 3, 4, 5, 6}) << endl;

	return 0;
}
