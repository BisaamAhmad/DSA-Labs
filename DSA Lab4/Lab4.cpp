#include<iostream>
using namespace std;
class Node;
Node* head = NULL;
class Node{
    int data;
    Node* next;
    public:
    void Data(Node* node){
        cout << "Enter data: ";
        cin >> node->data;
    }
    void insertAtStart(){
        Node* temp = new Node;
        Data(temp);
        temp->next = head;
        head = temp;
    }
    void insertAtPosition(){
        int position;
        cout << "Enter Position: ";
        cin >> position;
        if(position < 1){
            cout << "Invalid Position!";
            return; 
        }
        if(position == 1){
            insertAtStart();
            return;
        }
        Node* temp = head;
        for(int i = 1; i < position - 1; i++){
            temp = temp->next;
            if(temp == NULL){
                cout << "Invalid Position!";
                return;
            }
        }
        Node* newNode = new Node;
        Data(newNode);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void display(){
        Node* temp = head;
        while(temp!= NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    Node n;
    n.insertAtPosition();
    n.display();
    n.insertAtPosition();
    n.display();
}