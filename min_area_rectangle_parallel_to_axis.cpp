/**
 * Find minimum area of a rectangle, parallel to XY axis, from a given set of points.
 */

#include <vector>
#include <map>
#include <iostream>
#include <limits>
#include <algorithm>
#include <set>

using namespace std;

namespace solution1
{

int minimumAreaRectangle(vector<pair<int32_t, int32_t>> const &points)
{
	map<int32_t, vector<int32_t>> columns;

	for(auto i: points)
		columns[i.first].push_back(i.second);

	map<pair<int32_t, int32_t>, int32_t> lastx;

	int32_t ans = numeric_limits<int32_t>::max();

	for (auto &x:columns) 
	{ 
		vector<int32_t> column = x.second;

		sort(column.begin(), column.end());

		for (int32_t j = 0; j < column.size(); j++)
		{
			for (int32_t i = 0; i < j; i++)
			{
				int32_t y1 = column[i];
  
				if (lastx.find({y1, column[j]}) != lastx.end())
				{
					ans = min(ans, (x.first - lastx[{y1, column[j]}]) * (column[j] - column[i]));
				}
		
				lastx[{y1, column[j]}] = x.first;
			}
		}
	}

	if (ans < numeric_limits<int32_t>::max())
		return ans;
	else
		return 0;
}

}

namespace solution2
{

string pointToStr(pair<int32_t, int32_t> const &point)
{
	return to_string(point.first) + ":" + to_string(point.second);
}

string pointToStr(int32_t const x, int32_t const y)
{
	return to_string(x) + ":" + to_string(y);
}

int32_t minimumAreaRectangle(vector<pair<int32_t, int32_t>> points)
{
	set<string> pointSet;

	for (auto const &p: points)
		pointSet.insert(pointToStr(p));

	int32_t minArea = numeric_limits<int32_t>::max();
	
	for (int32_t i = 0; i < points.size(); ++i)
	{
		pair<int32_t, int32_t> const &p1 = points[i];
		
		for (int32_t j = 0; j < i; ++j)
		{
			pair<int32_t, int32_t> const &p2 = points[j];

			if (p1.first == p2.first || p1.second == p2.second)
				continue;

			if (pointSet.find(pointToStr(p1.first, p2.second)) != pointSet.end() 
					&& pointSet.find(pointToStr(p2.first, p1.second)) != pointSet.end())
			{
				int32_t area = abs(p1.first - p2.first) * abs(p1.second - p2.second);
				minArea = min(minArea, area);
			}
		}
	}
	
	return minArea != numeric_limits<int32_t>::max() ? minArea : 0;
}

}

int32_t main()
{
	vector<pair<int32_t, int32_t>> points = {
		{1, 5}, {5, 1}, {4, 2}, {2, 4}, {2, 2}, {1, 2}, {4, 5}, {2, 5}, {-1, -2}
	};

	cout << solution1::minimumAreaRectangle(points) << endl;
	cout << solution2::minimumAreaRectangle(points) << endl;

	cout << "\nTerminating main()..." << endl;
	return 0;
}
