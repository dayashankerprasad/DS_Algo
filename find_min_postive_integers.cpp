/**
 * Find the minimum positive integer in given array.
 * Given array: {1, 2, 3, 4, 1, 6}
 * Min +ve value: 5
 */

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

int findMinPositive2(vector<uint32_t>& nums)
{
	const auto isHomeUnoccupied = [&](uint32_t n) { return nums[n-1] != n; };
	const auto hasHome = [&](uint32_t n) { return 1 <= n && n <= nums.size(); };

	for (auto n : nums)
	{
		while (hasHome(n) && isHomeUnoccupied(n))
			std::swap(n, nums[n-1]);
    }

	for (uint32_t n = 1; n <= nums.size(); ++n)
	{
		if (isHomeUnoccupied(n))
			return n;
	}

	return nums.size() + 1;
}

uint32_t findMinPositive(vector<uint32_t> &array)
{
	uint32_t n = array.size();
	for (uint32_t i = 0; i < n; ++i)
	{
		if (array[i] > 0 && array[i] <= n)
		{
			uint32_t pos = array[i] - 1;
			if (array[pos] != array[i])
			{
				swap(array[pos], array[i]);
				--i;
			}
		}
	}

	for (uint32_t i = 0; i < n; ++i)
	{
		if (array[i] != i + 1)
			return (i + 1);
	}

	return n + 1;
}

void test(vector<uint32_t> array, uint32_t missingValue, auto function)
{
	uint32_t value = function(array);

	RUNTIME_ASSERTION(value == missingValue);

	cout << "Given array: " << toString(array) << endl;
	cout << "Min Postive val = " << value << endl;
}

int32_t main()
{
	test({1, 3, 6, 4, 1, 2}, 5, findMinPositive);
	return 0;
}


