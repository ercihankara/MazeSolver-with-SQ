#include <iostream>
#include <cstdlib>
#pragma once

using namespace std;

template <class T>
class StackQueue{
    private:
        T* custom_queue;
        int front, rear;
        int length;
        // considering an array lying, left is the rear while right is the front!
        // as if index 0 at right side (front)
    public:
        // constructor
        StackQueue(int num_of_els = 1024);
        // store new element at front
        void push_front(T new_el_front);
        // store new element at rear
        void push_rear(T new_el_rear);
        // remove and return from front
        T pop_front();
        // remove and return from rear
        T pop_rear();
        // return from front
        T peek_front();
        // return from rear
        T peek_rear();
        // return front-1'th element
        T peek_front_min_one();

        // check whether queue is full or empty
        bool is_full();
        bool is_empty();

        int get_rear();
        int get_front();

        // print all stored elements from rear to front
        void print_elements();

        // destructor
        ~StackQueue();
};

// constructor
template <class T>
StackQueue<T>::StackQueue(int num_of_els){
    custom_queue = new T[num_of_els];
    rear = 0;
    front = 0;
    length = num_of_els;
}

// store new element at front, no circular motion I guess
template <class T>
void StackQueue<T>::push_front(T new_el_front){ // stack
    if(front == length){
        cout << "OVERFLOW" << endl;
        exit(1);
    }

    if(rear == 0){
        for(int i=front; i>=0; i--){
            custom_queue[i+1] = custom_queue[i];
        }
        custom_queue[rear] = new_el_front;
        front ++;
    }
    else{
        custom_queue[rear-1] = new_el_front;
        rear --;
    }
}

// store new element at rear, no circular motion I guess
template <class T>
void StackQueue<T>::push_rear(T new_el_rear){ // queue
    if(front == length){
        cout << "OVERFLOW" << endl;
        exit(1);
    }
    custom_queue[front] = new_el_rear;
    front ++;
}

// remove and return from front, no circular motion I guess
template <class T>
T StackQueue<T>::pop_front(){ // queue
    T temp;
    if(front == 0 || rear == front){
        cout << "EMPTY" << endl;
        exit(1);
    }
    temp = custom_queue[rear];
    rear ++;
    return temp;

}

// remove and return from rear
template <class T>
T StackQueue<T>::pop_rear(){ // stack?
    T temp;
    if(front == 0 || rear == front){
        cout << "EMPTY" << endl;
        exit(1);
    }
    temp = custom_queue[front-1];
    front --;
    return temp;

}

// return from front w/o removing -> no exit is used
template <class T>
T StackQueue<T>::peek_front(){
    T temp;
    temp = custom_queue[rear];
    return temp;
}

// return from rear w/o removing -> no exit is used
template <class T>
T StackQueue<T>::peek_rear(){
    T temp;
    temp = custom_queue[front-1];
    return temp;
}

// return front-1 w/o removing
template <class T>
T peek_front_min_one();

// check whether queue is full or empty
template <class T>
bool StackQueue<T>::is_full(){
    return front == length;
}

template <class T>
bool StackQueue<T>::is_empty(){
    return front == 0;
}

template <class T>
int StackQueue<T>::get_rear(){
    return front;
}

template <class T>
int StackQueue<T>::get_front(){
    return rear;
}

// print all stored elements from rear to front
template <class T>
void StackQueue<T>::print_elements(){
    cout << "SQ: ";
    for(int i=rear; i<=front-1; i++)
        cout << custom_queue[i];
    cout << endl;
}

// destructor
template <class T>
StackQueue<T>::~StackQueue(){
    delete[] custom_queue;
}
