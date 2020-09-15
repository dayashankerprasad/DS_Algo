/**
 * Move a given element at the end of a given array. Order of remaining elements may be changed.
 * array = {2, 1, 2, 2, 2, 3, 4, 2}
 * toBeMoved = 2
 * After moving 2, array: {1, 3, 4, 2, 2, 2, 2, 2}
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

void moveElementToEnd(vector<int> &array, int toMove)
{
	int endIndex = array.size() - 1;

	for(uint16_t i = 0; i < endIndex;)
	{
		if (array[endIndex] == toMove)
		{
			if (endIndex > i)
				--endIndex;
			continue;
		}

		if (array[i] == toMove)
			swap(array[i], array[endIndex]);

		++i;
	}
}

int main()
{
	vector<int32_t> array = {2, 1, 2, 2, 2, 3, 4, 2};
	moveElementToEnd(array, 2);
	cout << "After element movement = " << array;
	cout << "\nTerminating main()..." << endl;

	return 0;
}

