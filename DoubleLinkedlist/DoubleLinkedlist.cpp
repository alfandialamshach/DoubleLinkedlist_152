#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int noMhs;
	string name;
	Node* next;
	Node* prev;
};

class DoubleLinkedList {
private:
	Node* START;
public:
	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, Node** previous, Node** current);
	bool deleteNode(int rollNo);
	bool listEmpty();
	void traverse();
	void hapus();
	void searchData();

};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node();		//step 1
	newNode->noMhs = nim;			//step 2
	newNode->name = nm;				//step 2

	/*Insert a node in the beginning of a dobly - linked list*/
	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs) {
			cout << "\nDublicate number not allowed" << endl;
			return;
		}
		newNode->next = START;		//step 3
		if (START != NULL)
			START->prev = newNode;	//step 4
		newNode->prev = NULL;		//step 5
		START = newNode;			//Step 6
		return;
	}

	/*Iserting a node on the betwen two node  in the list*/
	Node* current = START;				//Step 1.a
	Node* previous = NULL;				//Step 1.b
	while (current->next != NULL && current->next->noMhs < nim) { //stepp 1.c

		previous = current;	//1.d
		current = current->next;		//1.e
	}

	if (current->next != NULL && nim == current->next->noMhs) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}

	newNode->next = current->next; //Step 4
	newNode->prev = current;	//Step 5
	if (current->next != NULL)
		current->next->prev = newNode;	//Step 6
	current->next = newNode;	//step 7
}

bool DoubleLinkedList::search(int rollNo, Node** previous, Node** current) {
	*previous = START;	//Step 1.a
	*current = START;	//Step 1.b
	while (*current != NULL && rollNo != (*current)->noMhs) {		//step 1.c
		*previous = *current;	//step 1d
		*current = (*current)->next;	//step 1.e
	}
	return; (*current != NULL);
}
bool DoubleLinkedList::deleteNode(int rollNo) {
	Node* previous, * current;
	previous = current = NULL;
}