/*
 * Split array into 2 subarrays such that diff bwteen sum of elements in both subarrays should be least.
 * [1,2,3,4,5] => 
 * 	[3,4] = 7, 
 * 	[1,2,5] = 8 
 * 	diff = 8 - 7 = 1
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>

using namespace std;

ostream & operator << (ostream &out, vector<int> const &vec)
{
	for(int val: vec)
		out << val << " ";
	return out;
}

tuple<vector<int>, vector<int>> split(vector<int> &vec)
{
	vector<int> subarray1, subarray2;

	sort(begin(vec), end(vec));

	int targetSum = std::accumulate(begin(vec), end(vec), 0) / 2, sum = 0;

	for(uint16_t start = 0, i = 0; i < vec.size(); ++i)
	{
		sum += vec[i];
		subarray1.push_back(vec[i]);

		if (sum == targetSum)
			break;
		else if (sum > targetSum)
		{
			++start;
			i = start;
			sum = 0;

			subarray1.clear();
		}
	}

	std::set_difference(begin(vec), end(vec), begin(subarray1), end(subarray2), back_inserter(subarray2));

	return std::make_tuple(subarray1, subarray2);
}

void test(vector<int> &vec)
{
	auto [subarray1, subarray2] = split(vec);

	cout << "Array: " << vec << endl;
	cout << "Subarray1: " << subarray1 << endl;
	cout << "Subarray2: " << subarray2 << endl;
}

int main()
{
	vector<int> vec1 = {1,2,3,4,5};
	vector<int> vec2 = {100, 100, 90, 90, 80, 20, 20, 20};

	test(vec1);
	test(vec2);

	cout << "\nTerminating main()..." << endl;

	return 0;
}

