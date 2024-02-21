#include<iostream>
#include <set>
#include <map>

// set: Balanced BST - unique keys, order
using namespace std;

void printKeys(set<int>& s){
    auto it = s.begin();
    while(it != s.end()){
        cout << *it << " ";
        it++;
    }
}

int main(int argc, char const *argv[])
{   
    set<int> s {30, 20, 25, 40, 35, 60}; //Empty set
    s.insert(30); // insert 30
    for (auto elem : s){
        cout << elem << " ";
    }
    cout << endl;
    auto it = s.find(30);
    cout << *it << endl; // 30 
    it = s.find(32);
    if( it != s.end()){
       cout << *it << endl;
    }
    it = s.find(25);
    s.erase(it);
    it = s.find(25);
    cout << *it << endl;
    it = s.end();
    it--;
    cout << *it << endl; 
    printKeys(s);
    cout << endl;
   // set<pair<string, int>, Comparator> grocery_list;
    map<string, int> groceries;
    // balanced bst - key: value pairs
    groceries["banana"] = 2; // insert
    groceries["apple"] = 1;
    groceries["milk"] = 3;
    groceries["bread"] = 5;

    for (auto elem: groceries){
        cout << elem.first  << " " << elem.second << " ";
    }
    cout << endl;







    return 0;
}
