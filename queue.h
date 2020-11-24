#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <vector>

template <typename T>
class queue{
    
    public:
    queue();
    void enqueue(T x);
    bool isEmpty();
    T front();
    T dequeue();
    
    private:
    
    struct node{
        T data;
        
        node *next;
    };
    node *head;
    node *tail;
};

template <typename T>
queue<T>:: queue(){
    head = nullptr;
    tail = nullptr;
}

template <typename T>
void queue<T>:: enqueue(T x){
    
    if(!head){
        tail = new node{x, nullptr};
        head = tail;
    }else{
        tail->next = new node{x, nullptr};
        tail = tail->next;
    }
}

template <typename T>
bool queue<T>:: isEmpty(){
    return !head;
}

template <typename T>
T queue<T>:: front(){
    if(isEmpty()){
        std:: cerr<< "Tis empty yo";
        exit(1);
    }
    return head->data;
}

template <typename T>
T queue<T>:: dequeue(){
    T ret_val = front();
    node *tmp = head->next;
    delete head;
    head = tmp;
    if(!head){
        tail = head;
    }
    return ret_val;
}

#endif
