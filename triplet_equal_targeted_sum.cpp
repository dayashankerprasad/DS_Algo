/**
 * find all triplets from array such that their sum can be equal to a targeted value.
 * All the triplets must be sorted and triple data should be sorted as well.
 *
 * array = {12, 3, 1, 2, -6, 5, -8, 6}
 * targetSum = 0
 * Triplets: [-8 2 6], [-8 3 5], [-6 1 5]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
ostream & operator << (ostream &out, vector<T> const &obj)
{
	for(T const &val: obj)
		out << val << " ";
	return out;
}

vector<vector<int>> threeNumberSum(vector<int> &&array, int targetSum)
{
	vector<vector<int>> result;

	sort(begin(array), end(array));

	for(uint16_t i = 0; i < array.size(); ++i)
	{
		int diff = targetSum - array[i];

		for(uint16_t start = i + 1, end = array.size()-1; start < end;)
		{
			int sum = array[start] + array[end];
			if (sum == diff)
			{
				result.push_back({array[i], array[start], array[end]});
				++start;
			}
			else if (sum > diff)
				--end;
			else
				++start;
		}
	}
	return result;
}

int main()
{
	vector<vector<int>> result = threeNumberSum({12, 3, 1, 2, -6, 5, -8, 6}, 0);
	cout << result;
	cout << "\nTerminating main()..." << endl;

	return 0;
}

