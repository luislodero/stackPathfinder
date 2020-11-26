#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <vector>

template <typename T>
class queue{
    
    public:
    queue(int n);
    void enqueue(T x);
    bool isEmpty();
    bool isFull();
    T front();
    T dequeue();
    ~queue();
    queue(const queue&);
    const queue& operator = (const queue&);

    
    private:
    
    int *A;
    int currsize;
    int maxsize;
    int currstart;
    int currlast;
};

template <typename T>
queue<T>:: queue(int n){
    A = new int[n];
    currsize =0;
    maxsize = n;
    currstart = 0;
    currlast = 0;
}

template <typename T>
bool queue<T>:: isEmpty(){
    return (currsize == 0);
}

template<typename T>
bool queue<T>:: isFull(){
    return (maxsize == currsize);
}

template <typename T>
void queue<T>:: enqueue(T x){

    if(isFull()){
        std:: cerr << "Too many items yo";
        exit(1);
    }else{
        currlast = (currsize + currstart) % n;
        A[currlast] = x;
        currsize++;
    }
}



template <typename T>
T queue<T>:: front(){
    if(isEmpty()){
        std:: cerr<< "Tis empty yo";
        exit(1);
    }
    return A[currstart];
}

template <typename T>
T queue<T>:: dequeue(){
    
    T ret_val = front();
    if(currstart == n-1){
        currstart = 0;
    }else{
        currstart ++;
    }
    return ret_val;

}

template <typename T>
queue<T>:: ~queue(){

 delete[] A;

}

template <typename T>
queue<T>:: queue(const queue& q1){
    
    
    for(int i = 0, j = currstart; i < currsize; i++, j++){
        if(j == maxsize){
            j=0;
        }
        this->enqueue(q1.A[j]);
    }
    
    std:: cout << "-----------------COPY---------------------" << std:: endl;
}





#endif
