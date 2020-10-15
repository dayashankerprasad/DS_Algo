#include <iostream>
#include <vector>

using namespace std;

vector<int32_t> lessThan(vector<int32_t> const &vec)
{
	vector<int32_t> allData;

	for(int32_t i = 1, data = vec[0]; i < vec.size(); ++i)
		if (vec[i] < data)
			allData.push_back(vec[i]);
	
	return allData;
}

vector<int32_t> greaterThan(vector<int32_t> const &vec)
{
	vector<int32_t> allData;

	for(int32_t i = 1, data = vec[0]; i < vec.size(); ++i)
		if (vec[i] >= data)
			allData.push_back(vec[i]);
	
	return allData;
}

bool sameBsts(vector<int32_t> const arrayOne, vector<int32_t> const arrayTwo)
{
	if (arrayOne == arrayTwo)
		return true;

	if ((arrayOne[0] != arrayTwo[0]) || (arrayOne.size() != arrayTwo.size()))
		return false;

	vector<int32_t> lessThanRoot1 = lessThan(arrayOne);
	vector<int32_t> greaterThanRoot1 = greaterThan(arrayOne);

	vector<int32_t> lessThanRoot2 = lessThan(arrayTwo);
	vector<int32_t> greaterThanRoot2 = greaterThan(arrayTwo);
	
	return sameBsts(lessThanRoot1, lessThanRoot2) && sameBsts(greaterThanRoot1, greaterThanRoot2);
}

int32_t main()
{
	cout << "Same: " << sameBsts({10, 15, 8, 12, 94, 81, 5, 2, 11}, {10, 8, 5, 15, 2, 12, 11, 94, 81}) << endl;
	cout << "Same: " << sameBsts({1, 2, 3, 4, 5, 6, 7}, {1, 2, 3, 4, 5, 6, 7}) << endl;
	cout << "Same: " << sameBsts({7, 6, 5, 4, 3, 2, 1}, {7, 6, 5, 4, 3, 2, 1}) << endl;
	cout << "Same: " << sameBsts({10, 15, 8, 12, 94, 81, 5, 2}, {10, 8, 15, 12, 94, 81, 5, 2}) << endl;

	return 0;
}
