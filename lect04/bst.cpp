//bst.cpp
#include <iostream>
using namespace std;

// bst is an Abstract Data Type
class bst{
 public:
    //initialization routine: constructor
    bst() { root = nullptr;}
    // accessors or getter
    bool search(int value) const;
    int sum() const;
    void printInorder() const;
    int getHeight() const; // returns the height of the tree, maximum number of levels

    // mutators or setter
    void create_small_bst();
    void insert(int value);
    void clear();
    void erase(int value);

 private:
    struct Node{
        int data;
        Node* parent;
        Node* left;
        Node* right;
        Node (int d): data(d){
            parent = left = right = nullptr;
        }
    };
    Node* root;
    void printInorder(Node* r) const;
    int getHeight(Node* r) const;
};
bool bst::search(int value) const{
    return false;
}
int bst::sum() const{
    return 42;
}
void bst::printInorder() const{
    printInorder(root);
    cout << endl;
}

int bst::getHeight() const{
    return getHeight(root);
} // returns the height of the tree, maximum number of levels

void bst::create_small_bst(){
    root = new Node(50);
    root->right = new Node(100);
    root->left = new Node(20);
    root->left->left = new Node(7);
    root->left->left->right = new Node(8);
    return;
}
void bst::insert(int value){
    return;
}
void bst::clear(){
    return;
}
void bst::erase(int value){
    return;
}
void bst::printInorder(Node* r) const{
    if(!r) return;
    printInorder(r->left);
    cout << r->data << " "; //visit the node!
    printInorder(r->right);
}

int bst::getHeight(Node* r) const{
    return 42;
}

int main() {
    bst b;
    b.create_small_bst();
    b.printInorder();
    return 0;
}