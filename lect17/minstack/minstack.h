//minstack.h
#include <list>
#include <set>
using namespace std;
#ifndef MINSTACK_H
#define MINSTACK_H

template <class T>
class minStack{
    public:
        void push(T value){ 
 
        }

        void pop(){ 
            mystack_.pop_front();
        }

        T top(){ 
            return mystack_.front().first;
        }

        bool empty(){ 
            return mystack_.empty();
        }

        T min(){ 
            return 42;
        }

    private:
        list<pair<T, T>> mystack_;
};

template <class T>
class minStack_1{
    public:
        void push(T value){ //O(log n)
            mystack_.push_front(value);
            set_.insert(value);
        }

        void pop(){ //O(log n)
            T val = top();
            mystack_.pop_front();
            set_.erase(val);
        }

        T top(){ //O(1)
            return mystack_.front();
        }

        bool empty(){ //O(1)
            return mystack_.empty();
        }

        T min(){ //O(log n)
            return *(set_.begin());
        }

    private:
        list<T> mystack_;
        set<T>  set_; // balanced BST
};


#endif