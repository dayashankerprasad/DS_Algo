/**
 * Given an index k, return the kth row of the Pascal’s triangle.
 * Input : k = 3, Return : [1,3,3,1]
 */

#include <iostream>
#include <vector>

using namespace std;

ostream & operator << (ostream &out, vector<int32_t> const &vec)
{
	for(int32_t val: vec)
		out << val << " ";
	return out;
}

vector<int32_t> getPascalRow(int32_t rowIndex)
{
	vector <int> ans;

	for(int32_t c = 1, j = 1; j <= rowIndex + 1; ++j)
	{
	    ans.push_back(c);
	    c = c * (rowIndex + 1 - j) / j;
	}

	return ans;
}

int main()
{
	int32_t const rowIndex = 5;

	vector<int32_t> const pascalRow = getPascalRow(rowIndex);
	cout << pascalRow << endl;

	cout << "\nTerminating main()..." << endl;

	return 0;
}


