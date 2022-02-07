#include <iostream>
#include <memory>

using namespace std;

template<typename Type>
class DLinkedList
{
	struct Node
	{
		Node(Type &data, uint32_t &len): data_{move(data)}, len_{len}
		{
			++len_;
		}

		~Node() noexcept
		{
			std::cout << "Deleting node for data: " << data_ << std::endl;
			--len_;
		}

		Type data_;
		uint32_t &len_;
		weak_ptr<Node> prev_;
		shared_ptr<Node> next_;
	};

public:
	void pushBack(Type data);
	void pushFront(Type data);

	void popBack();
	void popFront();

	bool erase(Type const &data);
	bool find(Type const &data);

	Type const & front() const noexcept { return head_->data_; }
	Type const & back() const noexcept { return tail_->data_; }
	uint32_t size() const noexcept { return length_; }
	bool empty() const noexcept { return head_ == nullptr && tail_ == nullptr; }
	void clear() noexcept { head_ = tail_ = nullptr; }

private:
	shared_ptr<Node> createNode(Type &data)
	{
		return make_shared<Node>(data, length_);
	}

	shared_ptr<Node> __find(Type const &data) const
	{
		shared_ptr<Node> foundNode{nullptr};

		for (shared_ptr<Node> headTemp = head_, tailTemp = tail_; headTemp != tailTemp; headTemp = headTemp->next_, tailTemp = tailTemp->prev_.lock())
		{
			if (headTemp->data_ == data)
			{
				foundNode = headTemp;
				break;
			}
			else if (tailTemp->data_ == data)
			{
				foundNode = tailTemp;
				break;
			}

			if (headTemp->next_ == tailTemp)
				break;
		}

		return foundNode;
	}

	shared_ptr<Node> head_{nullptr}, tail_{nullptr};
	uint32_t length_{0};
};

template<typename Type>
void DLinkedList<Type>::pushBack(Type data)
{
	shared_ptr<Node> newNode = createNode(data);
	if (empty())
		head_ = tail_ = newNode;
	else
	{
		newNode->prev_ = tail_;
		tail_->next_ = newNode;
		tail_ = newNode;
	}
}

template<typename Type>
void DLinkedList<Type>::pushFront(Type data)
{
	shared_ptr<Node> newNode = createNode(data);
	if (empty())
		head_ = tail_ = newNode;
	else
	{
		newNode->next_ = head_;
		head_->prev_ = newNode;
		head_ = newNode;
	}
}

template<typename Type>
void DLinkedList<Type>::popBack()
{
	if (head_ == tail_)
		head_ = tail_ = nullptr;
	else
	{
		tail_->prev_.lock()->next_ = nullptr;
		tail_ = tail_->prev_.lock();
	}
}

template<typename Type>
void DLinkedList<Type>::popFront()
{
	if (head_ == tail_)
		head_ = tail_ = nullptr;
	else
	{
		head_->next_->prev_.reset();
		head_ = head_->next_;
	}
}

template<typename Type>
bool DLinkedList<Type>::erase(Type const &data)
{
	shared_ptr<Node> foundNode = __find(data);

	if (foundNode == nullptr)
		return false;

	foundNode->prev_.lock()->next_ = foundNode->next_;
	foundNode->next_->prev_ = foundNode->prev_;

	return true;
}

template<typename Type>
bool DLinkedList<Type>::find(Type const &data)
{
	shared_ptr<Node> foundNode = __find(data);
	return (foundNode != nullptr);
}

int32_t main()
{
	DLinkedList<int32_t> list;

	for (int32_t i = 1; i <= 10; ++i)
		list.pushBack(i);

	//list => 1 2 3 4 5 6 7 8 9 10

	for (int32_t i = 11; i <= 20; ++i)
		list.pushFront(i);

	//list => 20 19 18 17 16 15 14 13 12 11 1 2 3 4 5 6 7 8 9 10

	cout << "\nSize: " << list.size(); //20
	cout << "\nEmpty: " << boolalpha << list.empty() << endl; //false

	for (int32_t i = 1; i <= 5; ++i)
	{
		cout << list.back() << " ";
		list.popBack();
	}

	//list => 20 19 18 17 16 15 14 13 12 11 1 2 3 4 5

	for (int32_t i = 1; i <= 5; ++i)
	{
		cout << list.front() << " ";
		list.popFront();
	}

	//list => 15 14 13 12 11 1 2 3 4 5

	cout << "\nSize: " << list.size(); //10
	cout << "\nEmpty: " << boolalpha << list.empty() << endl; //false

	bool status = list.erase(11); //15 14 13 12 1 2 3 4 5
	cout << "\nErase status: " << boolalpha << status << endl; //true

	status = list.erase(51); //15 14 13 12 1 2 3 4 5
	cout << "\nErase status: " << boolalpha << status << endl; //false

	list.clear(); //list =>

	cout << "\nSize: " << list.size(); //0
	cout << "\nEmpty: " << boolalpha << list.empty() << endl; //true

	cout << "\nTerminating main()..." << endl;
	return 0;
}

