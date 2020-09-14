/**
 * Determine whether a given a array is a subsequence of another given array.
 * Subsequence means all the elements must present without any order disturbance.
 * array: {5, 1, 22, 25, 6, -1, 8, 10}
 * seq: {1, 6, -1, 10}
 * Is seq: true
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
ostream & operator << (ostream &out, vector<T> const &vec)
{
	for(T const &val: vec)
		out << val << " ";
	return out << "\n";
}

bool isValidSubsequence(vector<int32_t> const &array, vector<int32_t> const &sequence)
{
	uint16_t s = 0;

	for(uint16_t a = 0; a < array.size() && s < sequence.size(); ++a)
		if (array[a] == sequence[s])
			++s;

	return s == sequence.size();
}

void test(vector<int32_t> const &array, vector<int32_t> const &sequence)
{
	cout << array << endl << sequence << endl;
	cout << "Is sequence: " << isValidSubsequence(array, sequence) << endl;
}

int main()
{
	test({5, 1, 22, 25, 6, -1, 8, 10}, {1, 6, -1, 10});

	cout << "\nTerminating main()..." << endl;

	return 0;
}

