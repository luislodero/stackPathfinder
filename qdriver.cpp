#include <iostream>
#include "queue.h"


int main(){
    
    queue<int> q;
    std:: cout << q.isEmpty() << std:: endl;
    q.enqueue(9);
    std:: cout << q.front() << std:: endl;
    std:: cout << q.isEmpty() << std:: endl;
    q.dequeue();
    std:: cout << q.isEmpty() << std:: endl;
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(3);
    std:: cout << q.front() << std:: endl;
    q.dequeue();
    std:: cout << q.front() << std:: endl;
    q.dequeue();
    std:: cout << q.front() << std:: endl;
    q.dequeue();
    q.dequeue();
    std:: cout << q.front() << std:: endl;
    return 0;
    
}