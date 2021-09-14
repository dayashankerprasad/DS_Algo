/**
 * Multiply 2 arrays as if they are representing numbers.
 * array1 = {1, 2, 3, 4}
 * array2 = {1, 1}
 * array1 * array2 = {1, 3, 5, 7, 4}
 * because 1234*11 = 13574
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ostream & operator <<(ostream &out, vector<int32_t> const &vec)
{
	out << "{";
	for (auto v: vec)
		out << v << ", ";
	return out << "}";
}

namespace solution2
{
/**
 * This algorithm first prepares numbers from arrays, multiply both the numbers
 * and then split this result number into array.
 */

int32_t formNumber(vector<int32_t> array)
{
	int32_t sum = 0, sign = array.front() < 0 ? -1 : 1;

	array.front() = abs(array.front());

	for (auto v: array)
		sum  = sum * 10 + v;

	return sum * sign;
}

vector<int32_t> splitNumber(int32_t number)
{
	int sign = number < 0 ? -1 : 1;

	number = abs(number);

	vector<int32_t> result;

	while (number > 0)
	{
		result.push_back(number % 10);
		number /= 10;
	}
	
	reverse(begin(result), end(result));
	result.front() *= sign;

	return result;
}

vector<int32_t> multiply(vector<int32_t> array1, vector<int32_t> array2)
{
	cout << "\nMultiplying \n" << array1 << "\n" << array2 << endl;

	int32_t num1 = formNumber(array1), num2 = formNumber(array2);

	return splitNumber(num1 * num2);
}

}

namespace solution1
{
/**
 * this algorithm traverses both the arrays and multiplies individual element.
 */

vector<int32_t> multiply(vector<int32_t> array1, vector<int32_t> array2)
{
	cout << "\nMultiplying \n" << array1 << "\n" << array2 << endl;

	int32_t sign = array1.front() < 0 ^ array2.front() < 0 ? -1 : 1;

	array1.front() = abs(array1.front());
	array2.front() = abs(array2.front());

	vector<int32_t> result(array1.size() + array2.size(), 0);

	for (int32_t i = array1.size()-1; i >= 0; --i)
	{
		for (int32_t j = array2.size()-1; j >= 0; --j)
		{
			result[i + j + 1] += array1[i] * array2[j];
			result[i + j] += result[i + j + 1] / 10;
			result[i + j + 1] %= 10;
		}
	}

	result = vector<int32_t> {
		find_if(
			begin(result), 
			end(result), 
			[](int32_t a) 
			{
				return a != 0; 
			}
		),
		end(result)
	};

	if (result.empty())
		return {0};

	result.front() *= sign;

	return result;
}

}

int32_t main()
{
	cout << solution1::multiply({4, 3}, {-1, 6, 5, 4});
	cout << solution2::multiply({4, 3}, {-1, 6, 5, 4});
	cout << "\nTerminating main()..." << endl;
	return 0;
}
