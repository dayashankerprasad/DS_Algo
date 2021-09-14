/**
 * Remove continuous duplicate elements from a given array in-place and return new length of array.
 * input: array = {2, 3, 5, 5, 5, 7, 11, 11, 11, 13, 13}
 * output: 
 * 5
 * modified array = {2, 3, 5, 7, 11, 13, ...remaining elements...}
 */

#include <iostream>
#include <vector>

using namespace std;

ostream & operator<< (ostream &out, vector<int32_t> const &vec)
{
	out << "{";
	for (auto const v: vec)
		out << v << ", ";
	return out << "}";
}

namespace solution1
{

int32_t removeContinuousDuplicate(vector<int32_t>& array)
{
	int32_t size = array.size();
	if (size <= 1)
		return size;
        
	for (auto it = array.begin() + 1; it != array.end(); )
	{
		if (*(it - 1) == *it)
			it = array.erase(it);
		else
			++it;
	}

	return array.size();
}

}

namespace solution2
{

int32_t removeContinuousDuplicate(vector<int32_t> &array)
{
	int32_t size = array.size();

	if (size <= 1)
		return size;

	int i, j;
	for (i = 0, j = 1; j < size; ++j)
	{
		if (array[i] != array[j])
		{
			++i;
			array[i] = array[j];
		}
	}

	return i+1;
}

}

namespace solution3
{

int32_t removeContinuousDuplicate(vector<int32_t> &array)
{
	int32_t size = array.size();

    if (size <= 1)
	   	return size;

    int i, j;
    for (i = 0, j = 1; j < size; ++j)
	{
		if (array[i] == array[j])
			continue;

		if (array[i+1] != array[j])
			swap(array[i+1], array[j]);
		++i;
	}

	return i+1;
}

}

int32_t main()
{
	vector<int32_t> vec1 = {2, 3, 5, 5, 5, 7, 11, 11, 11, 13, 13};
	cout << solution1::removeContinuousDuplicate(vec1) << " => " << vec1 << endl;
	vec1 = {2, 3, 5, 5, 5, 7, 11, 11, 11, 13, 13};
	cout << solution2::removeContinuousDuplicate(vec1) << " => " << vec1 << endl;
	vec1 = {2, 3, 5, 5, 5, 7, 11, 11, 11, 13, 13};
	cout << solution3::removeContinuousDuplicate(vec1) << " => " << vec1 << endl;
	
	vec1 = vector<int32_t> {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	cout << solution1::removeContinuousDuplicate(vec1) << " => " << vec1 << endl;
	vec1 = vector<int32_t> {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	cout << solution2::removeContinuousDuplicate(vec1) << " => " << vec1 << endl;
	vec1 = vector<int32_t> {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	cout << solution3::removeContinuousDuplicate(vec1) << " => " << vec1 << endl;

	cout << "\nTerminating main()..." << endl;
	return 0;
}
