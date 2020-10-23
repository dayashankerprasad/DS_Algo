#include <iostream>
#include <vector>

using namespace std;

// O(n^2)
int maxArea1(vector<int> height)
{
	int max = 0;

	for (uint32_t i = 1; i < height.size(); ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			int val = min(height[j], height[i]);
			int area = val * (i - j);
			if (max < area)
				max = area;
		}
	}

	return max;
}

//O(n)
int maxArea(vector<int> const height)
{
	int area = 0, left = 0, right = height.size() - 1;

	while (left < right)
	{
		if (height[left] < height[right])
		{
			area = max(area, height[left] * (right - left));
			++left;
		}
		else
		{
			area = max(area, height[right] * (right - left));
			--right;
		}
	}
	return area;
}

int32_t main()
{
	cout << maxArea({1,2,3,4,5}) << endl;
	cout << maxArea1({1,2,3,4,5}) << endl;

	cout << maxArea({1,8,6,2,5,4,8,3,7}) << endl;
	cout << maxArea1({1,8,6,2,5,4,8,3,7}) << endl;

	return 0;
}

