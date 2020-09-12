/**
 * find out the zero border from all sides from a square matrix filled with 0 or 1 only.
 * matrix = [
	  	1, 1, 1, 0, 1, 0, 
	 >	0, 0, 0, 0, 0, 1, <
	 	0, 1, 1, 1, 0, 1,
	   	0, 0, 0, 1, 0, 1, 
	   	0, 1, 1, 1, 0, 1, 
	 >	0, 0, 0, 0, 0, 1, <
    	^           ^
 * ]
 */

#include <iostream>
#include <vector>

using namespace std;

bool isZeroSquare(vector<vector<int>> const &matrix, int r1, int c1, int r2, int c2)
{
	for (int row = r1; row <= r2; ++row)
		if (matrix[row][c1] != 0 || matrix[row][c2] != 0)
			return false;

	for (int col = c1; col <= c2; ++col)
		if (matrix[r1][col] != 0 || matrix[r2][col] != 0)
			return false;

	return true;
}

bool squareOfZeroes(vector<vector<int>> const &matrix, int r1, int c1, int r2, int c2)
{
	if (r1 >= r2 || c1 >= c2)
		return false;

	return isZeroSquare(matrix, r1, c1, r2, c2)
		|| squareOfZeroes(matrix, r1+1, c1+1, r2-1, c2-1)
		|| squareOfZeroes(matrix, r1, c1+1, r2-1, c2)
		|| squareOfZeroes(matrix, r1+1, c1, r2, c2-1)
		|| squareOfZeroes(matrix, r1+1, c1+1, r2, c2)
		|| squareOfZeroes(matrix, r1, c1, r2-1, c2-1);
}

bool squareOfZeroes(vector<vector<int>> const &matrix)
{
	return squareOfZeroes(matrix, 0, 0, matrix.size()-1, matrix.size()-1);
}

int main()
{
	vector<vector<int>> matrix = {
		{1, 1, 1, 0, 1, 0},
		{0, 0, 0, 0, 0, 1},
		{0, 1, 1, 1, 0, 1},
		{0, 0, 0, 1, 0, 1},
		{0, 1, 1, 1, 0, 1},
		{0, 0, 0, 0, 0, 1},
	};

	bool const val = squareOfZeroes(matrix);

	cout << "Final result: " << val << endl;

	cout << "\nTerminating main()..." << endl;

	return 0;
}

