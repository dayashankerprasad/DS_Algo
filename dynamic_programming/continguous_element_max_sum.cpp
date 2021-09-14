#include <iostream>

using namespace std;

template<typename T, const int size>
constexpr T kadane_algorithm(T (&array)[size])
{
	T local_sum = array[0], global_sum = array[0];

	for(uint32_t i = 1; i < size; ++i)
	{
		local_sum = max(array[i], local_sum + array[i]);
		global_sum = max(local_sum, global_sum);
	}

	return global_sum;
}

int32_t main()
{
	int array_1[] = { 1, 2, 3, -2, 5 };
	cout << "Max sum = " << kadane_algorithm(array_1) << endl;

	int array_2[] = { -1, -2, -3, -4 };
	cout << "Max sum = " << kadane_algorithm(array_2) << endl;

	int array_3[] = { 10, 8, -12, 5, -9, 100 };
	cout << "Max sum = " << kadane_algorithm(array_3) << endl;

	return 0;
}

