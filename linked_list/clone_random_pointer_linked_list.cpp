#include <iostream>
#include <map>

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
	NodePtr next{nullptr}, random{nullptr};
};

void print(NodePtr head)
{
	for(; head != nullptr; head = head->next)
		cout << head->data << "(" << (head->random != nullptr ? head->random->data : -1) << ")" << " ";
	cout << endl;
}

NodePtr addNodeAtEnd(NodePtr &head, int32_t data)
{
	NodePtr newNode = new Node(data);

	if (head == nullptr)
		head = newNode;
	else
	{
		Node *temp = head;
		for(; temp->next != nullptr; temp = temp->next);
		temp->next = newNode;
	}

	return newNode;
}

NodePtr clone(NodePtr head)
{
	map<int32_t, int32_t> existingNodeMap;
	map<int32_t, NodePtr> newNodeMap;

	NodePtr newList = nullptr;

	//Create new list
	for(; head != nullptr; head = head->next)
	{
		newNodeMap[head->data] = addNodeAtEnd(newList, head->data);
		existingNodeMap[head->data] = (head->random != nullptr ? head->random->data : -1);
	}

	//Setup random pointer
	for(NodePtr temp = newList; temp != nullptr; temp = temp->next)
	{
		int32_t randomData = existingNodeMap[temp->data];
		temp->random = newNodeMap[randomData];
	}

	return newList;
}

int32_t main()
{
	NodePtr head = new Node(10);
	head->next = new Node(20);
	head->next->next = new Node(5);
	head->next->next->next = new Node(19);
	head->next->next->next->next = new Node(16);
	
	head->random = head->next->next;
	head->next->random = head;
	head->next->next->random = head->next->next->next->next;
	head->next->next->next->random = head->next->next->next->next;
	head->next->next->next->next->random = head->next;

	print(head);

	NodePtr newList = clone(head);
	
	print(newList);

	return 0;
}
