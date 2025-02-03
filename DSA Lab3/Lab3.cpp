#include<iostream>
using namespace std;
class Node{
    public:
    int roll;
    string name;
    Node* next;
};
class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head = NULL;
    }
    ~LinkedList(){
        Node* temp = head;
        while(temp!=NULL){
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
    void data(Node* node);
    void insertAtStart();
    void insertAtEnd();
    void display();
};
void LinkedList::data(Node* node){
    cout << "Enter rollNo: ";
    cin >> node->roll;
    cout << "Enter Name: ";
    cin >> node->name;
}
void LinkedList::insertAtStart(){
    Node* temp = new Node;
    data(temp);
    temp->next = head;
    head = temp;
}
void LinkedList::insertAtEnd(){
    Node* newNode = new Node;
    data(newNode);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void LinkedList::display(){
    Node* temp = head;
    cout << "RollNo\tName\n";
    while(temp != NULL){
        cout << temp->roll << "\t" << temp->name << "\n";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    LinkedList l;
    l.insertAtStart();
    l.display();
    l.insertAtStart();
    l.display();
    l.insertAtEnd();
    l.display();
}