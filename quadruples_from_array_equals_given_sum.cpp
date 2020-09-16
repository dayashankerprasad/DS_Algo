/**
 * Find all the quadruples from a given array whose sum is equal to a given target sum
 * array: [1, 2, 3, 4, 5, -5, 6, -6]
 * targetSum = 5
 * quadruples: [2, 3, 5, -5], [1, 4, 5, -5], [2, 4, 5, -6], [1, 3, -5, 6], [2, 3, 6, -6], [1, 4, 6, -6]
 *
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

template<typename T>
ostream & operator << (ostream &out, vector<T> const &obj)
{
	for(T const &val: obj)
		out << val << " ";
	return out << "\n";
}

vector<vector<int32_t>> fourNumberSum(vector<int32_t> const &array, int32_t targetSum)
{
	vector<vector<int32_t>> quadruples;
	map<int32_t, vector<vector<int32_t>>> hashMap;

	for(uint32_t i = 0; i < array.size()-1; ++i)
	{
		for(uint32_t j = i + 1; j < array.size(); ++j)
		{
			int32_t currentSum = array[i] + array[j];
			int32_t remainSum = targetSum - currentSum;

			auto curPos = hashMap.find(remainSum);
			if (curPos != hashMap.end()) //hashmap has remaining 2 elements
			{
				for(vector<int32_t> remainElements: curPos->second)
				{
					remainElements.push_back(array[i]);
					remainElements.push_back(array[j]);

					quadruples.push_back(remainElements);
				}
			}
		}

		for(uint32_t k = 0; k < i; ++k)
		{
			int32_t currentSum = array[i] + array[k];
			if (hashMap.find(currentSum) == hashMap.end())
				hashMap[currentSum] = {{array[k], array[i]}};
			else
				hashMap[currentSum].push_back({array[k], array[i]});
		}
	}

	return quadruples;
}


int main()
{
	vector<vector<int>> quadruples = fourNumberSum({1, 2, 3, 4, 5, -5, 6, -6}, 5);

	cout << "All quadruples: \n " << quadruples;

	cout << "\nTerminating main()..." << endl;

	return 0;
}

