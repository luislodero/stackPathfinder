#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>
#include <string>

class stack{
  public:

  stack();
  void push(int x, int y);
  std:: string pop();
  std:: string peek();
  bool isEmpty();
  int length();
  private:
  struct node{
    int x,y;
    node* next;
  };
  node *top;
  int size;
};


stack:: stack(){
  top = nullptr;
  size = 0;
}


void stack:: push(int x, int y){
  top = new node{x,y,top};
  size++;
}

int stack :: length(){
  return size;
}


std:: string stack :: pop(){
      std:: string ret_val = peek();

  if(top != nullptr){
    node *c = top->next;
    node *t = top;
    top = c;
    delete t;
  }
  size--;
return ret_val;
}


std:: string stack :: peek(){
  if(!isEmpty()){
    std:: string s;
    s += std:: to_string(top->y);
    s += std:: to_string(top->x);
  return s;
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