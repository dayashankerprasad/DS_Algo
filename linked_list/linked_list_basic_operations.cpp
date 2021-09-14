#include <iostream>
#include <memory>

using namespace std;

struct Node;
using NodePtr = shared_ptr<Node>;

struct Node
{
	Node(int32_t dataArgs, NodePtr nextArgs=nullptr):
		data{dataArgs},
		next{nextArgs}
	{
	}

	int32_t data{0};
	NodePtr next{nullptr};
};

void pushBack(NodePtr &head, int32_t data)
{
	if (head == nullptr)
		head.reset(new Node(data));
	else
	{
		NodePtr temp = head;
		for(; temp->next != nullptr; temp = temp->next);
		temp->next.reset(new Node(data));
	}
}

void pushFront(NodePtr &head, int32_t data)
{
	head.reset(new Node(data, head));
}

NodePtr popFront(NodePtr &head)
{
	NodePtr first = head;
	if (head != nullptr) //if no node
		head = head->next;
	return first;
}

NodePtr popBack(NodePtr &head)
{
	NodePtr last = head, parentOfLast;
	for (; last != nullptr && last->next != nullptr; parentOfLast = last, last = last->next);

	if (last == nullptr); //if no node
	else if (parentOfLast == nullptr) //if only one node
		head.reset();
	else
		parentOfLast->next.reset();

	return last;
}

NodePtr findNode(NodePtr head, int32_t data)
{
	for(; head != nullptr && head->data != data; head = head->next);
	return head;
}

bool removeNode(NodePtr &head, int32_t data)
{
	NodePtr parentOfLast, last;

	for(last = head, parentOfLast = nullptr; last != nullptr && last->data != data; parentOfLast = last, last = last->next);

	if (last == nullptr)
		return false;

	if (last == head)
		head = head->next;
	else
		parentOfLast->next = last->next;

	return true;
}

void reverse(NodePtr &head)
{
	NodePtr prev = nullptr, cur = head, next = nullptr;

	while(cur != nullptr)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	head = prev;
}

void print(NodePtr head)
{
	for(; head != nullptr; head = head->next)
		cout << head->data << " ";
	cout << endl;
}

int32_t main()
{
	NodePtr head;

	for(auto const i: {9,8,7,6,5,4,3,2,1})
		pushBack(head, i);

	print(head);

	return 0;
}


