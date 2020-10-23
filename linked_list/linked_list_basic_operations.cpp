#include <iostream>

using namespace std;

struct Node
{
	Node(int32_t dataArgs, Node *nextArgs=nullptr):
		data{dataArgs},
		next{nextArgs}
	{
	}

	int32_t data{0};
	Node *next{nullptr};
};

using NodePtr = Node *;

void addNodeAtEnd(NodePtr &head, int32_t data)
{
	if (head == nullptr)
		head = new Node(data);
	else
	{
		Node *temp = head;
		for(; temp->next != nullptr; temp = temp->next);
		temp->next = new Node(data);
	}
}

void addNodeAtBeg(NodePtr &head, int32_t data)
{
	NodePtr newNode = new Node(data, head);
	head = newNode;
}

NodePtr findNode(NodePtr head, int32_t data)
{
	for(; head != nullptr && head->data != data; head = head->next);
	return head;
}

bool removeNode(NodePtr &head, int32_t data)
{
	NodePtr parent, current;

	for(current = head; current != nullptr && current->data != data; parent = current, current = current->next);

	if (current == nullptr)
		return false;

	if (current == head)
		head = head->next;
	else
		parent->next = current->next;

	delete current;
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
	NodePtr head = nullptr;

	for(int i = 1; i <= 10; ++i)
		addNodeAtEnd(head, i);

	print(head);

	for(int i = 11; i <= 20; ++i)
		addNodeAtBeg(head, i);

	print(head);

	cout << findNode(head, 10) << endl;
	cout << findNode(head, 30) << endl;

	removeNode(head, 11);
	removeNode(head, 10);
	removeNode(head, 20);

	print(head);

	reverse(head);

	print(head);

	return 0;
}
