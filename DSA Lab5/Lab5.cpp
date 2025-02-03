#include<iostream>
using namespace std;
class Node {
public:
	int roll;
	string name;
	Node* next;
};
class LinkedList {
	Node* head;
public:
	LinkedList() {
		this->head = NULL;
	}
	~LinkedList() {
		Node* temp = head;
		while (temp != NULL) {
			Node* nextNode = temp->next;
			delete temp;
			temp = nextNode;
		}
	}
	void data(Node* head);
	void insertAtHead();
	void insertAtLast();
	void insertAtPosition();
	void display();
	void displayCenterNode();

};
void LinkedList::data(Node* node) {
	cout << "Enter RollNo: ";
	cin >> node->roll;
	cout << "Enter Name: ";
	cin >> node->name;
}
void LinkedList::insertAtHead() {
	Node* temp = new Node;
	data(temp);
	temp->next = head;
	head = temp;
}
void LinkedList::insertAtLast() {
	Node* newNode = new Node;
	data(newNode);
	if (head == NULL) {
		head = newNode;
		return;
	}
	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	temp = newNode;
}
void LinkedList::insertAtPosition() {
	int position;
	cout << "Enter Position to insert: ";
	cin >> position;
	if (position < 1) {
		cout << "Invalid Position!" << endl;
		return;
	}
	if (position == 1) {
		insertAtHead();
		return;
	}
	Node* temp = head;
	for (int i = 1; i < position - 1; i++) {
		temp = temp->next;
		if (temp == NULL) {
			cout << "Invalid Position!" << endl;
			exit(0);
		}
	}
	Node* newNode = new Node;
	data(newNode);
	newNode->next = temp->next;
	temp->next = newNode;
}
void LinkedList::display() {
	Node* temp = head;
	cout << "RollNo\tName\n";
	while (temp != NULL) {
		cout << temp->roll << "\t" << temp->name << "\n";
		temp = temp->next;
	}
	cout << endl;
}
void LinkedList::displayCenterNode() {
	Node* temp = head;
	int count = 1;
	while (temp != NULL) {
		temp = temp->next;
		count++;
	}
	int size = count;
	int middle = size / 2;
	Node* middleNode = head;
	for (int i = 1; i <= middle; i++) {
		if ( i == middle) {
			cout << "Middle Node = " << middleNode->roll << "\t" << middleNode->name << "\n";
			break;
		}
		middleNode = middleNode->next;
	}
}
int main() {
	LinkedList l;
	l.insertAtHead();
	l.display();
	l.insertAtLast();
	l.display();
	l.insertAtPosition();
	l.insertAtPosition();
	l.insertAtPosition();
	l.display();
	l.displayCenterNode();
	
}