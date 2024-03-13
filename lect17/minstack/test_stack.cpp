//test_stack.cpp
#include <iostream>
#include <vector>
#include <stack>
#include "minstack.h"
using namespace std;
int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, -3, 4, 5};
    minStack<int> s;
    cout << "Pushing elements to the min-stack" << endl;
    for(auto elem : nums){
        s.push(elem);
        cout << "Top: " << s.top() << " Min: " << s.min() << endl;
    }
    //cout << "Top: " << s.top() << endl;
    cout << "Popping elements from the min-stack" << endl;
    while(!s.empty()){
        cout << "Top: " << s.top() << " Min: " << s.min() << endl;
        s.pop();
    }

}
