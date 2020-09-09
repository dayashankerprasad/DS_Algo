/**
 * Largest sub-array of length K
 * X = [1,2,3,4] and Y = [1,2,4,4]. Here Y > X because Y[2] and X[2] are the first element which are different and Y[2] > X[2].
 * Find a larget subarray of length K from a given array.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

template<typename T>
ostream & operator<<(ostream &out, vector<T> const &data)
{
	for(T const &val: data)
		out << val << " ";

	return out;
}

vector<int32_t> extract(vector<int32_t> const &data, uint16_t position, uint16_t kSize)
{
	vector<int32_t> vec(kSize);

	for(uint16_t i = position, k = 0; k < kSize && i < data.size(); ++i, ++k)
		vec[k] = data[i];

	return vec;
}

vector<int32_t> maxSubArray(vector<int32_t> const &data, int k)
{
	vector<vector<int32_t>> extractedData(data.size() - k + 1);

	for(uint16_t i = 0; i < data.size() - k + 1; ++i)
	{
		vector<int32_t> d = extract(data, i, k);
		extractedData[i].swap(d);
	}

	sort(begin(extractedData), end(extractedData),
		[](vector<int32_t> const &v1, vector<int32_t> const &v2)
		{
			assert(v1.size() == v2.size());

			for(uint16_t i = 0; i < v1.size(); ++i)
			{
				if (v1[i] != v2[i])
					return v1[i] > v2[i];
			}
			return false;
		}
	);

	return extractedData[0];
}

int main()
{
	vector<int32_t> arr = {1, 2, 3, 4, 5};

	vector<int32_t> output = maxSubArray(arr, 3);

	cout << "Max subarray: " << output << endl;

	cout << "\nTerminating main()..." << endl;

	return 0;
}

