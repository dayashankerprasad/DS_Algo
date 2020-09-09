/**
 * Remove total k no. of digits from a number so that new number should be least value number.
 * Digits can be removed from any where inside given number.
 * Example:
 * 123456789, k=3 ==> 123456
 * 1234219, k=3 ==> 1219
 */

#include <stack>
#include <cmath>
#include <iostream>

using namespace std;

long unsigned int removeDigit(long unsigned int number, uint32_t k)
{
	std::stack<int> containerStk, processingStk;

	while (number > 0)
	{
		containerStk.push(number % 10);
		number /= 10;
	}

	uint32_t const digitCounts = containerStk.size();

	while (! containerStk.empty())
	{
		int val = containerStk.top();
		containerStk.pop();

		if (processingStk.empty())
		{
			processingStk.push(val);
		}
		else
		{
			if (val >= processingStk.top())
			{
				processingStk.push(val);
			}
			else
			{
				while ((! processingStk.empty()) && val < processingStk.top() && k > 0)
				{
					processingStk.pop();
					--k;
				}

				processingStk.push(val);
			}
		}
	}

	for(int i = 1; i <= k; ++i)
		processingStk.pop();

	long unsigned int newVal = 0, pos = 0;

	while (! processingStk.empty())
	{
		int val = processingStk.top();
		processingStk.pop();

		newVal += val * std::pow(10, pos);
		++pos;
	}

	return newVal;
}

int main()
{
	cout << removeDigit(1234219, 3) << endl;
	cout << removeDigit(123456789, 3) << endl;
	cout << removeDigit(567456789, 4) << endl;

	cout << "Terminating main()..." << endl;

	return 0;
}

