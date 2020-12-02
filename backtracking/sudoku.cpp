#include <iostream>
#include <vector>

using namespace std;

constexpr uint32_t NEED_TO_FILL{0};

bool findVacant(std::vector<std::vector<uint32_t>> const &grid, uint32_t &row, uint32_t &col)
{
	for (row = 0; row < grid.size(); ++row)
		for (col = 0; col < grid.size(); ++col)
			if (grid[row][col] == NEED_TO_FILL)
				return true;

	return false;
}

bool usedInRow(std::vector<std::vector<uint32_t>> const &grid, uint32_t row, uint32_t num)
{
	for (uint32_t col = 0; col < grid.size(); ++col)
		if (grid[row][col] == num)
			return true;

	return false;
}

bool usedInCol(std::vector<std::vector<uint32_t>> const &grid, uint32_t col, uint32_t num)
{
	for (uint32_t row = 0; row < grid.size(); ++row)
		if (grid[row][col] == num)
			return true;

		return false;
}

bool usedInBox(std::vector<std::vector<uint32_t>> const &grid, uint32_t boxStartRow, uint32_t boxStartCol, uint32_t num)
{
	for (uint32_t row = 0; row < grid.size() / 3; ++row)
		for (uint32_t col = 0; col < grid.size() / 3; ++col)
			if (grid[row + boxStartRow][col + boxStartCol] == num)
				return true;

	return false;
}

bool isSafe(std::vector<std::vector<uint32_t>> const &grid, uint32_t row, uint32_t col, uint32_t num)
{
	return !usedInRow(grid, row, num) 
		&& !usedInCol(grid, col, num) 
		&& !usedInBox(grid, row - row % 3 , col - col % 3, num);
}

void printGrid(std::vector<std::vector<uint32_t>> const &grid)
{
	for (auto const &row : grid)
	{
		for (auto const val: row)
			cout << val << "  ";

		cout << endl;
	}
}

bool solveSudoku(std::vector<std::vector<uint32_t>> &grid)
{
	uint32_t row, col;

	if (!findVacant(grid, row, col))
		return true;

	for (uint32_t num = 1; num <= grid.size(); ++num)
	{
		if (isSafe(grid, row, col, num))
		{
			grid[row][col] = num;

			if (solveSudoku(grid))
				return true;
			else
				grid[row][col] = NEED_TO_FILL;
		}
	}
	return false;
}

int32_t main()
{
	std::vector<std::vector<uint32_t>> grid = {
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 3, 1},
		{0, 0, 3, 0, 1, 0, 0, 8, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0},
		{0, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0}
		
	};

	constexpr uint32_t SIZE{9};

	if (! (grid.size() == SIZE && grid.size() == grid[0].size()))
	{
		cout << "Incorrect size" << endl;
		return 1;
	}

	if (solveSudoku(grid))
		printGrid(grid);
	else
		cout << "No solution exists" << endl;

	return 0;
}
