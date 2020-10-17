/**
 * Find total n largest number from a given array whose size is > n.
 * example:
 * array = {141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7}
 * n = 4
 * largest number = {17 18 141 541}
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

ostream & operator<< (ostream &out, vector<int> const &vec)
{
	for(int const v: vec)
		out << v << " ";
	return out;
}

void pushLargest(vector<int32_t> &result, int32_t n, int32_t index)
{
	for(int32_t i = 0; i <= index; ++i)
		result[i] = result[i+1];
	
	result[index] = n;
}

void findLargest(vector<int32_t> &result, int32_t n, int32_t count)
{
	for(int32_t i = count - 1; i >= 0; --i)
	{
		if (n > result[i])
		{
			pushLargest(result, n, i);
			break;
		}
	}
}

vector<int32_t> findNLargestNumbers(vector<int32_t> array, uint32_t count)
{
	vector<int32_t> result(count, INT_MIN);

	for(int32_t n: array)
		findLargest(result, n, count);

	return result;
}

int32_t main()
{
	cout << findNLargestNumbers({141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7}, 4) << endl;
	cout << findNLargestNumbers({55, 7, 8}, 2) << endl;
	cout << findNLargestNumbers({55, 43, 11, 3, -3, 10}, 3) << endl;

	return 0;
}
