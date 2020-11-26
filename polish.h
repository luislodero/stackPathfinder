#ifndef POLISH_H
#define POLISH_H
#include <iostream>
#include <vector>


class stack{
  public:

  stack();
  void push(double x);
  double pop();
  double peek();
  bool isEmpty();
  private:
  struct node{
    double x;
    node* next;
  };
  node *top;
};


stack:: stack(){
  top = nullptr;

}


void stack:: push(double x){
  top = new node{x,top};

}


double stack :: pop(){
   double ret_val = peek();

  if(top != nullptr){
    node *c = top->next;
    node *t = top;
    top = c;
    delete t;
  }
return ret_val;
}


double stack :: peek(){
  if(!isEmpty()){
  return top->x;
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