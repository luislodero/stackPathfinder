#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>


class stack{
  public:

  stack();
  void push(int x, int y);
  int pop();
  int peek();
  bool isEmpty();
  bool path_finder(std:: vector<std:: vector<int>> &V, int n);
  private:
  struct node{
    int x,y;
    node* next;
  };
  node *top;
};


stack:: stack(){
  top = nullptr;
  
}


void stack:: push(int x, int y){
  top = new node{x,y,top};

}


int stack :: pop(){
      int ret_val = peek();

  if(top != nullptr){
    node *c = top->next;
    node *t = top;
    top = c;
    delete t;
  }
return ret_val;
}


int stack :: peek(){
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

bool stack:: path_finder(std:: vector<std:: vector<int>> &V, int n){
    // int ysize = V.size()+2;
    // int xsize = V[0].size()+2;
    // std::vector<std:: vector<int>> A(ysize, std::vector<int> (xsize, 0));
    //fillVector(V,A);
    
    // checkPos(A,s);
  
  int startx = 1;
  int starty = 1;
  // int endx = V[0].size()-1;
  // int endy = V.size()-1;
  
  if(V[startx][starty] == 1){
    std:: cout << n << std:: endl;
    std:: cout << "true" << std:: endl;
    return true;
  }
  std:: cout << "false" << std:: endl;
  return false;
}


#endif