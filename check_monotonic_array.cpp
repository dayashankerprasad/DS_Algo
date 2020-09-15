/**
 * Check whether a given array is monotonic or not.
 */

#include <iostream>
#include <vector>

using namespace std;

bool isMonotonic_1(vector<int32_t> const &array)
{
	bool increasing = true, decreasing = true;

	for (uint16_t i = 1; i < array.size(); ++i)
	{
		if (array[i] > array[i-1])
			decreasing = false;
		if (array[i] < array[i-1])
			increasing = false;
	}

	return increasing || decreasing;
}

bool isMonotonic_2(vector<int32_t> const &array)
{
	if (array.size() <= 2)
		return true;

	int32_t diffSign = array[1] - array[0]; //This diff sign should be consistent

	for(uint16_t i = 2; i < array.size(); ++i)
	{
		int32_t localDiff = array[i] - array[i-1];
		if (localDiff == 0)
			continue;

		if (diffSign == 0)
			diffSign = localDiff;

		if (diffSign * localDiff < 0)
			return false;
	}
	return true;
}

int main()
{
	cout << isMonotonic_1({-1, -5, -10, -1100, -1100, -1101, -1102, -9001}) << endl;
	cout << isMonotonic_2({-1, -5, -10, -1100, -1100, -1101, -1102, -9001}) << endl;

	cout << "\nTerminating main()..." << endl;

	return 0;
}

