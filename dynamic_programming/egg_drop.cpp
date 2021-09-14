#include <iostream>
#include <vector>

using namespace std;

namespace solution1
{

int32_t eggDrop(int32_t eggCount, int32_t floorCount)
{
	vector<int32_t> table(eggCount + 1, 0);
	int32_t attempt = 0;

	for (attempt = 0; table[eggCount] < floorCount; ++attempt)
	{
		for (int i = eggCount; i > 0; --i)
			table[i] += (table[i-1] + 1);
	}

	return attempt;
}

}

namespace solution2
{

int32_t eggDrop(int32_t eggCount, int32_t floorCount)
{
	vector<vector<int32_t>> table(eggCount + 1, vector<int32_t>(floorCount + 1, 0));

	for(int32_t i = 0; i <= floorCount; ++i)
		table[1][i] = i;

	for(int32_t k = 2; k <= eggCount; ++k)
	{
		for(int32_t n = 1; n <= floorCount; ++n)
		{
			int32_t low = 1; int high = n, x = 1;

			while(low <= high)
			{
				x = low + (high - low)/2;

				int32_t const t1 = table[k - 1][x - 1];
				int32_t const t2 = table[k][n - x];

				if(t1 < t2)
					low = x + 1;
				else if(t1 > t2)
					high = x - 1;
				else
				{
					low = x;
					high = x;
					break;
				}
			}

			table[k][n] = 1 + max(table[k][n - x], table[k - 1][x - 1]);
		}
	}

	return table[eggCount][floorCount];
}

}

int32_t main()
{
	cout << solution1::eggDrop(1, 2) << endl;
	cout << solution1::eggDrop(2, 6) << endl;
	cout << solution1::eggDrop(3, 14) << endl;

	cout << solution2::eggDrop(1, 2) << endl;
	cout << solution2::eggDrop(2, 6) << endl;
	cout << solution2::eggDrop(3, 14) << endl;

	cout << "\nTerminating main()..." << endl;
	return 0;
}
