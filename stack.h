#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>


class stack{
  public:

  stack();
  void push(int x, int y, char c);
  int pop();
  int peek();
  bool isEmpty();
  int length();
  private:
  struct node{
    int x,y;
    char c;
    node* next;
  };
  node *top;
  int size;
};


stack:: stack(){
  top = nullptr;
  size = 0;
}


void stack:: push(int x, int y, char c){
  top = new node{x,y,c,top};
  size++;
}

int stack :: length(){
  return size;
}


node* stack :: pop(){
      node* ret_val = peek();

  if(top != nullptr){
    node *c = top->next;
    node *t = top;
    top = c;
    delete t;
  }
  size--;
return ret_val;
}


node* stack :: peek(){
  if(!isEmpty()){
  return top;
  }
  else{
    std:: cerr << "TIS EMPTY YO BYEBYE" << std:: endl;
    exit(1);
  }
}


bool stack :: isEmpty(){
  if(top == nullptr){
    return true;
  }
  return false;
}



#endif