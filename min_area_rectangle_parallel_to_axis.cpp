/**
 * Find minimum area of a rectangle, parallel to XY axis, from a given set of points.
 */

#include <vector>
#include <map>
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

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

int32_t main()
{
	vector<pair<int32_t, int32_t>> points = {
		{1, 5}, {5, 1}, {4, 2}, {2, 4}, {2, 2}, {1, 2}, {4, 5}, {2, 5}, {-1, -2}
	};

	cout << minimumAreaRectangle(points) << endl;

	cout << "\nTerminating main()..." << endl;
	return 0;
}
