/**
 * Sort a given array according to given order as another array. 
 * In case given array contains elements other than order array, those elements should be ignored
 * and can be place end in any order.
 * 
 * Example:
 * array: {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
 * order: {2, 1, 8, 3}
 * 
 * After sort 
 * array: {2, 2, 1, 1, 8, 8, 3, 9, 6, 7, 5}
 */

#include <iostream>
#include <vector>

using namespace std;

ostream & operator << (ostream &out, vector<int32_t> const &vec)
{
	for (int32_t v: vec)
		out << v << ", ";
	return out;
}

namespace approach1
{

void sortArray(vector<int32_t> &array, vector<int32_t> const &order)
{
	size_t swapIndex = 0;
	for (size_t i = 0; i < order.size(); ++i)
	{
		for (size_t j = 0; j < array.size(); ++j)
		{
			if (array[j] == order[i])
			{
				swap(array[j], array[swapIndex]);
				++swapIndex;
			}
		}
	}
}

}

int32_t main()
{
	vector<int32_t> array = {1, 0, 0, -1, -1, 0, 1, 1}, order = {0, 1, -1};
	approach1::sortArray(array, order);
	cout << array << endl;

	array = vector<int32_t>{7, 8, 9, 7, 8, 9, 9, 9, 9, 9, 9, 9};
	order = vector<int32_t>{8, 7, 9};
	approach1::sortArray(array, order);
	cout << array << endl;

	array = vector<int32_t>{2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
	order = vector<int32_t>{2, 1, 8, 3};
	approach1::sortArray(array, order);
	cout << array << endl;

	return 0;
}
