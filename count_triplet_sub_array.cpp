#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

template<typename T>
using Triplet = tuple<T, T, T>;

template<class Tuple, std::size_t N>
struct TuplePrinter
{
	static void print(Tuple const &t) 
	{
		TuplePrinter<Tuple, N-1>::print(t);
		std::cout << ", " << std::get<N-1>(t);
    }
};

template<class Tuple>
struct TuplePrinter<Tuple, 1>
{
	static void print(Tuple const &t) 
	{
		std::cout << std::get<0>(t);
	}
};
 
template<class... Args>
ostream & operator<<(ostream &out, std::tuple<Args...> const &t)
{
	out << "(";
	TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
	out << ")";
	return out;
}

template<typename T>
ostream & operator<<(ostream &out, vector<T> const &vec)
{
	for(auto const &obj: vec)
	{
		out << obj;
	}
	return out;
}

template<typename T, int32_t N>
vector<Triplet<T>> const find_triplet(T (&array)[N])
{
	vector<Triplet<T>> vec;

	sort(begin(array), end(array));

	for(int32_t i = N - 1; i >= 0; --i)
	{
		for(int32_t start_index = 0, end_index = i - 1; start_index < end_index; )
		{
			T const sum = array[start_index] + array[end_index];

			if (sum == array[i])
			{
				vec.emplace_back(array[start_index], array[end_index], array[i]);
				++start_index;
				++end_index;
			}
			else if(sum < array[i])
				++start_index;
			else
				--end_index;
		}
	}

	return vec;
}

int main()
{
	int32_t array_1[] = { 10, 8, 9, 7, 5, 6, 4, 1, 3, 2 };
	cout << "Triplet count = " << find_triplet(array_1) << endl;

	int32_t array_2[] = { 5, 6, 4, 1, 3, 2 };
	cout << "Triplet count = " << find_triplet(array_2) << endl;

	int32_t array_3[] = { 1, 3, 2 };
	cout << "Triplet count = " << find_triplet(array_3) << endl;

	int32_t array_4[] = { 1, 1, 1 };
	cout << "Triplet count = " << find_triplet(array_4) << endl;

	int32_t array_5[] = { 2, -1, 4, 3, 7, 1 };
	cout << "Triplet count = " << find_triplet(array_5) << endl;

	return 0;
}

