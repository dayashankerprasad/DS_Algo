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

//O(n^2)
uint32_t longestIncreasingSequenceLength_3(vector<int32_t> const &array)
{
	vector<int32_t> table(array.size(), 1); //Stores max length till individual index
	vector<int32_t> seq(array.size(), -1); // Chain of indices causing subseq to be max length
	int maxIndex = 0;
	for(uint32_t i = 1; i < array.size(); ++i)
	{
		for(uint32_t j = 0; j < i; ++j)
		{
			if (array[i] > array[j] && (table[j] + 1) > table[i])
			{
				table[i] = table[j] + 1;
				seq[i] = j;
			}
		}
		
		if (table[i] > table[maxIndex])
			maxIndex = i;
	}

	vector<int> seqIndex; //Actual indices creating largest length subsequence
	seqIndex.push_back(maxIndex);

	for(int i = maxIndex; i >= 0; i = seq[i])
	{
		if (seq[i] >= 0)
			seqIndex.push_back(seq[i]);
	}

	vector<int> subSeq; //Finally all the elements creating largest length sub sequence
	for (std::vector<int>::reverse_iterator rit = seqIndex.rbegin(); rit!= seqIndex.rend(); ++rit)
		subSeq.push_back(array[*rit]);

	for(auto const i: subSeq)
		cout << i << " ";
	cout << endl;

	return table[maxIndex];
}

int32_t main()
{
	cout << longestIncreasingSequenceLength({1, 2, 3, 4, 5, 3, 5, 6}) << endl;
	cout << longestIncreasingSequenceLength({1, 2, 1, 2}) << endl;
	cout << longestIncreasingSequenceLength({10, 9, 2, 3, 4, 5, 6}) << endl;

	cout << longestIncreasingSequenceLength_2({1, 2, 3, 4, 5, 3, 5, 6}) << endl;
	cout << longestIncreasingSequenceLength_2({1, 2, 1, 2}) << endl;
	cout << longestIncreasingSequenceLength_2({10, 9, 2, 3, 4, 5, 6}) << endl;

	cout << longestIncreasingSequenceLength_3({1, 2, 3, 4, 5, 3, 5, 6}) << endl;
	cout << longestIncreasingSequenceLength_3({1, 2, 1, 2}) << endl;
	cout << longestIncreasingSequenceLength_3({10, 9, 2, 3, 4, 5, 6}) << endl;

	return 0;
}
