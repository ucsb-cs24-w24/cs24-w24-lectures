//linkedlist.cpp
// Non-OOP style implementation to contrast against the OOP style
// implementation in intlist.cpp 
#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

Node* push_front(Node* h, int value){
    return new Node{value, h};
}

Node* reverseList(Node* head) {
    if(!head) return nullptr;
    if(!head->next) return head;
    Node* new_head = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head; 
}

void printList(Node* head){
    Node* p = head;
    while(p){
        cout << "["<< p->data << "]";
        p = p->next;
        if(p) cout << "->";
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    head = push_front(head, 10);
    head = push_front(head, 20);
    head = push_front(head, 30);
    head = push_front(head, 40);
    printList(head);
    head = reverseList(head);
    printList(head);
    return 0;
}

