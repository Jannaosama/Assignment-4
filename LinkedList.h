#include<string>
#include<vector>

class LinkedList
{
private:
	struct node
	{
		int value;
		int count;
		node* next;
		node(int value, int count) : value(value), count(count), next(nullptr) {}
	};
public:

	node* head;
	int size = 0;

	void AddNode(int number);
	void RemoveNode(int number);
	void Print();
	void CreateLinkedList(const std::vector<int>&); //Create a linked list of the elemets of the vector
	int SumNodes();

	LinkedList();

};
