#include <iostream>
#include <array>
#include <functional>

using namespace std;

int32_t leftChildIndex(int32_t const index)
{
	return (index << 1) + 1;
}

int32_t rightChildIndex(int32_t const index)
{
	return (index << 1) + 2;
}

int32_t parentIndex(int32_t const index)
{
	return (index - 1) >> 1;
}

template<typename Type, typename Comparator>
int32_t heapifyTree(Type *buffer, int32_t const parentIndex, int32_t const maxIndex, Comparator const cmp)
{
	int32_t const leftIndex = leftChildIndex(parentIndex), rightIndex = rightChildIndex(parentIndex);
	int32_t workingIndex = -1;

	if (leftIndex <= maxIndex && rightIndex <= maxIndex)
	{
		if (cmp(buffer[leftIndex], buffer[rightIndex]))
			workingIndex = leftIndex;
		else
			workingIndex = rightIndex;
	}
	else if (leftIndex <= maxIndex && rightIndex > maxIndex)
		workingIndex = leftIndex;
	else if (leftIndex > maxIndex && rightIndex <= maxIndex)
		workingIndex = rightIndex;

	if (workingIndex == -1)
		return -1;

	if (cmp(buffer[workingIndex], buffer[parentIndex]))
	{
		swap(buffer[workingIndex], buffer[parentIndex]);
		return workingIndex;
	}

	return -1;
}

template<typename Type, int32_t SIZE, typename Comp>
class Heap
{
public:
	bool insert(Type const data);
	void remove();
	Type const & top() const
	{
		return buffer[0];
	}
	bool empty() const
	{
		return curIndex == -1;
	}
	int32_t size() const 
	{
		return this->curIndex + 1;
	}

	void print()const //for debug purpose only
	{
		for (int32_t i = 0; i <= curIndex; ++i)
			cout << buffer[i] << " ";
		cout << endl;
	}

private:
	array<Type, SIZE> buffer{-1};
	int32_t curIndex{-1};
	Comp cmp;
};

template<typename Type, int32_t SIZE, typename Comp>
bool Heap<Type, SIZE, Comp>::insert(Type data)
{
	if (curIndex >= SIZE - 1)
		return false;

	buffer[++curIndex] = data;

	if (curIndex == 0)
		return true;

	int32_t tempIndex = curIndex;

	while(true)
	{
		int32_t const pIndex = parentIndex(tempIndex);
		
		if (cmp(buffer[tempIndex], buffer[pIndex]))
			swap(buffer[tempIndex], buffer[pIndex]);

		if (pIndex == 0)
			break;

		tempIndex = pIndex;
	}

	return true;
}

template<typename Type, int32_t SIZE, typename Comp>
void Heap<Type, SIZE, Comp>::remove()
{
	buffer[0] = buffer[curIndex--];

	int startIndex = 0;

	while (true)
	{
		int32_t const ret = heapifyTree(buffer.data(), startIndex, curIndex, Comp());

		if (ret == -1)
			break;

		startIndex = ret;
	}
}

template<typename T, int32_t SIZE>
using MaxHeap = Heap<T, SIZE, std::greater<T>>;

template<typename T, int32_t SIZE>
using MinHeap = Heap<T, SIZE, std::less<T>>;

template<typename Type, typename Comp=std::greater<Type>>
void heapify(Type *buffer, int32_t const start, int32_t const end, Comp cmp=Comp())
{
	for (int32_t i = end; i >= start; --i)
		heapifyTree(buffer, i, end, cmp);

	for (int32_t i = start + 1; i <= end; ++i)
		heapifyTree(buffer, i, end, cmp);
}

int main()
{
	MaxHeap<int, 10> obj;

	obj.insert(50);
	obj.insert(30);
	obj.insert(20);
	obj.insert(15);
	obj.insert(10);
	obj.insert(8);
	obj.insert(16);

	obj.print();

	obj.remove();
	obj.print();

	obj.remove();
	obj.print();

	obj.remove();
	obj.print();

	int32_t array[] = {10, 20, 15, 12, 40, 25, 18};
	heapify(array, 0, sizeof(array)/sizeof(array[0]) - 1);

	for (int32_t i: array)
		cout << i << " ";
	cout << endl;
	return 0;
}
