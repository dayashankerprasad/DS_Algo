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

bool isLoopExist(Node *head)
{
	Node *fast = head, *slow = head;
	
	while (true)
	{
		fast = fast->next;
		if (fast != nullptr)
			fast = fast->next;

		slow = slow->next;

		if (slow == fast)
			return true;

		if (slow == nullptr || fast == nullptr)
			return false;
	}
}

Node * findLoop(Node *head)
{
	Node *fast = head, *slow = head;
	bool loop = false;
	while (true)
	{
		fast = fast->next;
		if (fast != nullptr)
			fast = fast->next;

		slow = slow->next;

		if (slow == fast)
		{
			loop = true;
			break;
		}

		if (slow == nullptr || fast == nullptr)
			break;
	}

	if (loop)
	{
		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		
		return slow;
	}
	
	return nullptr;
}

int32_t main()
{
	Node *head = nullptr;

	head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = new Node(6);
	head->next->next->next->next->next->next = new Node(7);
	head->next->next->next->next->next->next->next = new Node(8);
	head->next->next->next->next->next->next->next->next = new Node(9);

	head->next->next->next->next->next->next->next->next->next = head->next->next->next;

	cout << "Loop flag: " << isLoopExist(head) << ", " << findLoop(head)->data << endl;
	
	head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = new Node(6);

	cout << "Loop flag: " << isLoopExist(head) << ", " << findLoop(head) << endl;

	return 0;
}
