/**
 * Rotate the matrix by 90 degrees (clockwise) in-place.

 * Input = [
       [1, 2],
       [3, 4]
   ]

   Output = [
       [3, 1],
       [4, 2]
   ]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
ostream & operator << (ostream &out, vector<T> const &vec)
{
	for(T const &val: vec)
		out << val << " ";
	return out << "\n";
}

namespace solution1
{

template<typename T>
void rotate_90_Cockwise(vector<vector<T>> &matrix)
{
	uint32_t const size = matrix.size();

	//Transpose
	for(uint16_t row = 0; row < size; ++row)
		for(uint16_t col = row + 1; col < size; ++col)
			swap(matrix[row][col], matrix[col][row]);

	//Swap both end col data until comes to mid
	for(uint16_t startCol = 0, endCol = size - 1; startCol < endCol; ++startCol, --endCol)
		for(uint16_t row = 0; row < size; ++row)
			swap(matrix[row][startCol], matrix[row][endCol]);
}

}

namespace solution2
{

template<typename T>
void rotate_90_Cockwise(vector<vector<T>> &matrix)
{
	const uint16_t matrixSize = matrix.size() - 1;

	for (uint16_t i = 0; i < (matrixSize + 1) / 2; ++i)
	{
		for (uint16_t j = i; j < matrix.size() - i; ++j)
		{
			T temp1 = matrix[matrixSize - j][i];
			T temp2 = matrix[matrixSize - i][matrixSize - j];
			T temp3 = matrix[j][matrixSize - i];
			T temp4 = matrix[i][j];

			matrix[i][j] = temp1;
			matrix[matrixSize - j][i] = temp2;
			matrix[matrixSize - i][matrixSize - j] = temp3;
			matrix[j][matrixSize - i] = temp4;
		}
	}
}

}
int main()
{
	vector<vector<char>> matrix = {
		{'a', 'f', 'k', 'p', 'u'},
		{'b', 'g', 'l', 'q', 'v'},
		{'c', 'h', 'm', 'r', 'w'},
		{'d', 'i', 'n', 's', 'x'},
		{'e', 'j', 'o', 't', 'y'}
	};

	cout << "Original matrix:\n" << matrix << endl;

	solution1::rotate_90_Cockwise(matrix);

	cout << "Rotated matrix:\n" << matrix << endl;

	matrix = vector<vector<char>>{
		{'a', 'f', 'k', 'p', 'u'},
		{'b', 'g', 'l', 'q', 'v'},
		{'c', 'h', 'm', 'r', 'w'},
		{'d', 'i', 'n', 's', 'x'},
		{'e', 'j', 'o', 't', 'y'}
	};

	cout << "\nOriginal matrix:\n" << matrix << endl;

	solution2::rotate_90_Cockwise(matrix);

	cout << "Rotated matrix:\n" << matrix << endl;

	cout << "\nTerminating main()..." << endl;

	return 0;
}

