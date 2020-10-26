#include <iostream>

using namespace std;

struct Node;
using NodePtr = Node *;

struct Node
{
	Node(int32_t dataArgs, Node *nextArgs=nullptr):
		data{dataArgs},
		next{nextArgs}
	{
	}

	int32_t data{0};
	NodePtr next{nullptr};
};

void addNodeAtEnd(NodePtr &head, int32_t data)
{
	NodePtr newNode = new Node(data);
	if (head == nullptr)
	{
		head = newNode;
		head->next = head;
	}
	else
	{
		Node *temp = head;
		for(; temp->next != head; temp = temp->next);
		temp->next = newNode;
		newNode->next = head; //make it circular
	}
}

void addNodeAtBeg(NodePtr &head, int32_t data)
{
	NodePtr newNode = new Node(data, head);
	NodePtr temp = head;
	for(; temp->next != head; temp = temp->next);
	head = newNode;
	temp->next = head; //make it circular
}

NodePtr findNode(NodePtr head, int32_t data)
{
	NodePtr temp = head;
	do 
	{
		if (temp->data == data)
			break;
		temp = temp->next;
	}while (temp != head);

	return temp == head ? nullptr : temp;
}

bool removeNode(NodePtr &head, int32_t data)
{
	if (head->data == data)
	{
		NodePtr lastNode = head;
		for(; lastNode->next != head; lastNode = lastNode->next);

		NodePtr firstNode = head;

		head = head->next;
		lastNode->next = head;

		delete firstNode;
		return true;
	}

	NodePtr currentNode = head, parent = nullptr;
	do 
	{
		if (currentNode->data == data)
			break;

		parent = currentNode;
		currentNode = currentNode->next;
	} while (currentNode != head);

	if (currentNode == head)
		return false;

	parent->next = currentNode->next;
	delete currentNode;
	return true;
}

void reverse(NodePtr &head)
{
	NodePtr prev = nullptr, cur = head, next = nullptr;

	do
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	} while(cur != head);

	cur->next = prev; //make it circular
	head = prev;
}

void print(NodePtr head)
{
	NodePtr currentNode = head;
	do
	{
		cout << currentNode->data << " ";
		currentNode = currentNode->next;
	} while (currentNode != head);

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

	cout << removeNode(head, 11) << endl;
	cout << removeNode(head, 10) << endl;
	cout << removeNode(head, 20) << endl;

	print(head);

	reverse(head);

	print(head);

	return 0;
}
