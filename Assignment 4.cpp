#include <iostream>
#include <vector>
#include "LinkedList.h"
using namespace std;

void EnterAfter(vector <int>&, int, int);
void printvec(vector <int>);

int main() {

	vector<int> VectorM;
	int n, x;
	cout << "enter the integers number: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "enter the element number " << i + 1 << ": ";
		cin >> x;
		VectorM.push_back(x);
		cout << endl;
	}

	printvec(VectorM);
	EnterAfter(VectorM, 4, 9);
	printvec(VectorM);

	//the linked list part
	LinkedList MainList;

	MainList.AddNode(8);
	MainList.AddNode(9);
	MainList.AddNode(4);
	MainList.AddNode(3);

	cout << "The default list :";
	MainList.Print();

	MainList.RemoveNode(4);

	cout << "After removing 4 : ";
	MainList.Print();

	cout << "the sum of nodes is :";
	cout << MainList.SumNodes();
	cout << endl;

	LinkedList Vectorlist;
	Vectorlist.CreateLinkedList(VectorM);
	cout << " the list that would be inserted in the vector: ";
	Vectorlist.Print();

	return 0;
}

void EnterAfter(vector <int>& VectorM, int first, int second) {

	//linear search 
	for (auto it = VectorM.begin(); it != VectorM.end(); ++it) {
		if (*it == first) {
			it = VectorM.insert(it + 1, second);
		}
	}
}


void printvec(vector <int> v) {
	for (int x : v) {
		std::cout << x << " ";
	}
	cout << endl;
}

