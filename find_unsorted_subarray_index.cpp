/**
 * Find which part of array is not sorted and returns corresponding start and end index.
 * If array is completely sorted returns {-1, -1}
 */

#include <limits.h>
#include <iostream>
#include <sstream>
#include <vector>


using namespace std;

#define	LOG(msg) \
do { \
	cout << msg << " [" << __PRETTY_FUNCTION__ << " (" << __FILE__ << ": " << __LINE__ << ")]" << endl; \
} while(false) \

#define	RUNTIME_ASSERTION(condition) \
do { \
	if (!(condition)) \
	{ \
		LOG("Runtime asserting '" << #condition << "' failed"); \
		exit(1); \
	} \
} while(false) \


template<typename ContainerType>
string toString(ContainerType const &obj)
{
	if (obj.empty())
		return "";

	ostringstream oss;

	typename ContainerType::const_iterator curPos = begin(obj);

	oss << *curPos;

	for(++curPos; curPos != end(obj); ++ curPos)
		oss << ", " << *curPos;

	return oss.str();
}

bool areNeighboursInSequence(vector<int32_t> const &array, uint32_t index)
{
	if (index == 0)
	{
		if (array[index] > array[index + 1])
			return false;
		else
			return true;
	}

	if (index == array.size() - 1)
	{
		if (array[index] < array[index - 1])
			return false;
		else
			return true;
	}

	return array[index - 1] <= array[index] && array[index] <= array[index + 1];
}

vector<int32_t> subarraySort(vector<int32_t> const &array)
{
	int32_t minNotInSeq = INT_MAX, maxNotInSeq = INT_MIN;

	for(uint32_t i = 0; i < array.size(); ++i)
	{
		if (! areNeighboursInSequence(array, i))
		{
			minNotInSeq = min(minNotInSeq, array[i]);
			maxNotInSeq = max(maxNotInSeq, array[i]);
		}
	}

	if (minNotInSeq == INT_MAX)
		return {-1, -1};

	int32_t startIndex = 0, endIndex = array.size() - 1;

	for(; minNotInSeq >= array[startIndex]; ++startIndex);
	for(; maxNotInSeq <= array[endIndex]; --endIndex);

	return {startIndex, endIndex};
}

void test(vector<int32_t> const &array, vector<int32_t> const &result)
{
	vector<int32_t> index = subarraySort(array);

	RUNTIME_ASSERTION(index == result);

	cout << toString(index) << endl;
}

int32_t main()
{
	test({1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19}, {3, 9});
	test({0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89}, {-1, -1});
	return 0;
}


