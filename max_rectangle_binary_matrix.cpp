/**
 * Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.
 * A : [  1 1 1
          0 1 1
          1 0 0
       ]
 * Output : 4
 */

#include <iostream>
#include <vector>

using namespace std;

void findAreaIfAllAreOne(vector<vector<int>> const &matrix, int r1, int c1, int r2, int c2, int &maxArea)
{
	bool flag = true;
	for (int row = r1; row <= r2; ++row)
	{
		for (int col = c1; col <= c2; ++col)
		{
			if (matrix[row][col] != 1)
			{
				flag = false;
				break;
			}
		}
	}

	int area = 0;

	if (flag)
	{
		area = (r2 - r1 + 1) * (c2 - c1 + 1);
		if (maxArea < area)
			maxArea = area;
	}
}

void areaOfOne(vector<vector<int>> const &matrix, int r1, int c1, int r2, int c2, int &maxArea)
{
	if (r1 >= r2 || c1 >= c2)
		return;

	findAreaIfAllAreOne(matrix, r1, c1, r2, c2, maxArea);

	areaOfOne(matrix, r1+1, c1+1, r2-1, c2-1, maxArea);
	areaOfOne(matrix, r1, c1+1, r2-1, c2, maxArea);
	areaOfOne(matrix, r1+1, c1, r2, c2-1, maxArea);
	areaOfOne(matrix, r1+1, c1+1, r2, c2, maxArea);
	areaOfOne(matrix, r1, c1, r2-1, c2-1, maxArea);
}

int areaOfOne(vector<vector<int>> const &matrix)
{
	int maxArea = 0;
	areaOfOne(matrix, 0, 0, matrix.size()-1, matrix.size()-1, maxArea);
	return maxArea;
}

int main()
{
	vector<vector<int>> matrix1 = {	//Area = 4
		{0, 1, 1},
		{1, 1, 1},
		{1, 1, 1}
	};

	int area = areaOfOne(matrix1);

	cout << "Area: " << area << endl;

	vector<vector<int>> matrix2 = {	//Area = 9
			{1, 1, 1},
			{1, 1, 1},
			{1, 1, 1}
		};

	area = areaOfOne(matrix2);

	cout << "Area: " << area << endl;

	vector<vector<int>> matrix3 = {	//Area = 16
			{1, 1, 1, 0, 1, 1},
			{1, 1, 1, 0, 1, 1},
			{1, 1, 1, 1, 1, 1},
			{0, 1, 1, 1, 1, 1},
			{0, 1, 1, 1, 1, 1},
			{0, 1, 1, 1, 1, 1},
		};

	area = areaOfOne(matrix3);

	cout << "Area: " << area << endl;


	cout << "\nTerminating main()..." << endl;

	return 0;
}

