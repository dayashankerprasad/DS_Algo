/**
 * Given a collection of intervals, merge all overlapping intervals in-place.
 * For example:
 * Given intervals [1,3],[2,6],[8,10],[15,18] should change to [1,6],[8,10],[15,18].
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T, typename U>
ostream & operator << (ostream &out, pair<T, U> const &obj)
{
	return out << "(" << obj.first << ", " << obj.second << ")";
}

template<typename T>
ostream & operator << (ostream &out, vector<T> const &vec)
{
	for(T const &val: vec)
		out << val << " ";
	return out << "\n";
}

void mergeOverlappingIntervals(vector<pair<int32_t, int32_t>> &intervals)
{
	sort(begin(intervals), end(intervals), [](pair<int32_t, int32_t> const &lhs, pair<int32_t, int32_t> const &rhs)
	{
		return lhs.first < rhs.first;
	});

	for (uint16_t i = 1; i < intervals.size(); ++i)
	{
		if (intervals[i-1].second > intervals[i].first)
		{
			intervals[i-1].second = intervals[i].second;
			intervals.erase(intervals.begin() + i);
			--i;
		}
	}
}

void test(vector<pair<int32_t, int32_t>> &intervals)
{
	cout << intervals << endl;
	mergeOverlappingIntervals(intervals);
	cout << intervals << endl;
}

int main()
{
	vector<pair<int32_t, int32_t>> intervals1 = {
		{1, 3},
		{8, 10},
		{2, 6},
		{15, 18}
	};

	test(intervals1);

	vector<pair<int32_t, int32_t>> intervals2 = {
		{1, 3},
		{9, 11},
		{8, 10},
		{2, 6},
		{15, 18},
		{12, 16}
	};

	test(intervals2);

	cout << "\nTerminating main()..." << endl;

	return 0;
}

