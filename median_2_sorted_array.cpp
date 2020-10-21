#include <iostream>
#include <vector>

using namespace std;

double findMedian(vector<int32_t> const &array1, vector<int32_t> const &array2)
{
	int32_t const size1 = array1.size(), size2 = array2.size(), halfLen = (size1 + size2 + 1) / 2;
	int32_t leftIndex = 0, rightIndex = size1;

	while (leftIndex <= rightIndex)
	{
		int32_t const mid = (leftIndex + rightIndex) / 2;
		int32_t const j = halfLen - mid;

		if (mid < rightIndex && array2[j - 1] > array1[mid])
			leftIndex = mid + 1;
		else if (mid > leftIndex && array1[mid - 1] > array2[j])
			rightIndex = mid - 1; 
		else
		{
			int32_t maxLeft = 0;

			if (mid == 0)
				maxLeft = array2[j - 1];
			else if (j == 0)
				maxLeft = array1[mid - 1];
			else
				maxLeft = max(array1[mid - 1], array2[j - 1]);

			if ((size1 + size2) % 2 == 1)
				return maxLeft;

			int32_t minRight = 0;

			if (mid == size1)
				minRight = array2[j];
			else if (j == size2)
				minRight = array1[mid];
			else 
				minRight = min(array2[j], array1[mid]);

			return (maxLeft + minRight) / 2.0;
		}
	}

	return 0.0;
}

double findMedianSortedArrays(vector<int32_t> array1, vector<int32_t> array2)
{
	return array1.size() < array2.size() ? findMedian(array1, array2) : findMedian(array2, array1);
}

int32_t main()
{
	cout << findMedianSortedArrays({}, {1,2,3}) << endl;
	cout << findMedianSortedArrays({1, 2, 5, 6}, {3, 4, 7, 8}) << endl;
	cout << findMedianSortedArrays({1, 2, 5, 6, 9}, {3, 4, 7, 8}) << endl; 
	return 0;
}
