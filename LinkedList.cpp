#include<string>
#include<iostream>
#include"LinkedList.h"
using namespace std;

//by creating the list we define a new head to be a null pointer

LinkedList::LinkedList()
{
	node* head = nullptr;
}
void LinkedList::AddNode(int x) {
	node* present = head; //this pointer is used to cross over the list
	node* temp = nullptr; //this pointer is for trcaking other nodes


	//In this case the linked list is empty and we have to assign the head pointer to a node to intialize it as the first node in the linked list
	if (head == nullptr) {
		head = new node(x, 1);
		size++;
		return;
	}

	while (present != nullptr && present->value != x) {
		temp = present;
		present = present->next;
	}

	//if we found an existing node with the same value , we incremnet the count without adding a new node
	if (present != nullptr) {
		present->count++;
	}
	else {
		node* addnode = new node(x, 1);
		size++;
		//case of inserting in a node at the top of the list
		if (temp == nullptr) {
			head = addnode;
		}
		else {
			//update the the pointer of the previous node to the new node instead of nullptr
			temp->next = addnode;
		}
		//update the pointer of the new node
		addnode->next = present;
	}
}

void LinkedList::RemoveNode(int value) {

	// Check wether the list exists or not
	if (head == nullptr) {
		std::cout << "your list is empty";
		return;
	}


	if (head->value == value) {
		node* temp = head;
		head = head->next;
		delete temp;
		size--;
		return;
	}

	node* temp = head;
	node* present = head->next;
	//Checking if there is a similar value in the list
	while (present != nullptr) {
		if (present->value == value) {
			//move the pointer to the next pint after deleting
			temp->next = present->next;
			delete present;
			size--;
			return;
		}
		//shifting the pointers to the next node 
		temp = present;
		present = present->next;
	}

}

void LinkedList::Print() {

	node* present = head;
	//loop checking if that node is the last node in the linked list
	while (present != nullptr) {
		std::cout << present->value << " ";
		present = present->next;
	}
	std::cout << std::endl;

}


void LinkedList::CreateLinkedList(const std::vector<int>& vec) {
	for (int element : vec) {
		AddNode(element);
	}
}

int LinkedList::SumNodes() {
	int add = 0;
	node* present = head;
	// go over the list to check if it is the last node
	while (present != nullptr) {
		add += present->value;
		present = present->next;
	}

	return add;
}
