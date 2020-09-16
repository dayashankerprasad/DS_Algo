/**
 * Spiral matrix print
 */

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
ostream & operator << (ostream &out, vector<T> const &obj)
{
	for(T const &val: obj)
		out << val << " ";
	return out << "\n";
}

vector<int32_t> spiralTraverse(vector<vector<int32_t>> const &array)
{
	if (array.empty())
		return {};

	vector<int32_t> traverse;

	for(int32_t r1 = 0, r2 = array.size() - 1, c1 = 0, c2 = array[0].size() - 1; r1 <= r2 && c1 <= c2; ++r1, --r2, ++c1, --c2)
	{
		for(int32_t i = c1; i <= c2; ++i)
		{
			traverse.push_back(array[r1][i]);
		}
		for(int32_t i = r1+1; i <= r2; ++i)
		{
			traverse.push_back(array[i][c2]);
		}
		for(int32_t i = c2-1; i >= c1; --i)
		{
			if (r1 == r2)
				break;
			traverse.push_back(array[r2][i]);
		}
		for(int32_t i = r2-1; i >= r1+1; --i)
		{
			if (c1 == c2)
				break;
			traverse.push_back(array[i][c1]);
		}
	}

	return traverse;
}

int main()
{
	vector<vector<int>> matrix = {
		{1, 2, 3, 4},
		{12, 13, 14, 5},
		{11, 16, 15, 6},
		{10, 9, 8, 7}
	};

	cout << "Spiral representation of matrix \n" << matrix << "\nis: " << spiralTraverse(matrix);
	cout << "\nTerminating main()..." << endl;

	return 0;
}

