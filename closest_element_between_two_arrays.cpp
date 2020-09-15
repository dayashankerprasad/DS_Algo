/**
 * find closest element between 2 arrays.
 * arrayOne = {-1, 5, 10, 20, 28, 3}, arrayTwo = {26, 134, 135, 15, 17}
 * closet element = 28, 26
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

template<typename T>
ostream & operator << (ostream &out, vector<T> const &obj)
{
	for(T const &val: obj)
		out << val << " ";
	return out;
}

vector<int32_t> smallestDifference(vector<int32_t> arrayOne, vector<int32_t> arrayTwo)
{
	sort(begin(arrayOne), end(arrayOne));
	sort(begin(arrayTwo), end(arrayTwo));

	int32_t smallestDiff = INT_MAX;
	vector<int32_t> smallestDiffElement;

	for(uint16_t indexOne = 0, indexTwo = 0; indexOne < arrayOne.size() && indexTwo < arrayTwo.size(); )
	{
		int32_t currentDiff = 0, firstEle = arrayOne[indexOne], secondEle = arrayTwo[indexTwo];
		if (firstEle < secondEle)
		{
			currentDiff = secondEle - firstEle;
			++indexOne;
		}
		else if (firstEle > secondEle)
		{
			currentDiff = firstEle - secondEle;
			++indexTwo;
		}
		else
			return {firstEle, secondEle};

		if (smallestDiff > currentDiff)
		{
			smallestDiff = currentDiff;
			smallestDiffElement.clear();
			smallestDiffElement.push_back(firstEle);
			smallestDiffElement.push_back(secondEle);
		}
	}

	return smallestDiffElement;
}

int main()
{
	vector<int32_t> arrayOne = {-1, 5, 10, 20, 28, 3}, arrayTwo = {26, 134, 135, 15, 17};
	vector<int32_t> closeElement = smallestDifference(arrayOne, arrayTwo);
	cout << "Close element = " << closeElement;
	cout << "\nTerminating main()..." << endl;

	return 0;
}

