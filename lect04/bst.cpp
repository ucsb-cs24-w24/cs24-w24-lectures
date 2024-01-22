//bst.cpp
#include <iostream>
using namespace std;

// IntList is an Abstract Data Type
class IntList{
 public:
    //initialization routine: constructor
    IntList() { head = nullptr;}
    // accessors or getter
    int sum() const;
    int front() const;
    int back() const;
    void print() const;

    // mutators or setter
    void reverse();
    void push_front(int value);
    void clear();
    void pop_front();
    void erase(int value);

 private:
    struct Node{
        int data;
        Node* next;
    };
    Node* head;
};


int main() {
    return 0;
}