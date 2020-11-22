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
  bool path_finder(std:: vector<std:: vector<int>> &V);
  private:
  struct node{
    int x,y;
    node* next;
  };
  node *top;
  void fillVector(std::vector<std:: vector<int>> &V, std:: vector<std:: vector<int>> &A);
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

void stack:: fillVector(std:: vector<std:: vector<int>> &V, std:: vector<std:: vector<int>> &A){
    int ysize = V.size()+2;
    int xsize = V[0].size()+2;
    
    for(int i = 0; i < ysize; i++){
        
        for(int j=0; j < xsize; j++){
            if(i == 0 || i == ysize-1){
                A[i][j] = 0;
            }else if(j == 0 || j == xsize-1){
                A[i][j] = 0;
            }else{
                A[i][j] = V[i-1][j-1];
            }
        }
    }
    
}

bool stack:: path_finder(std:: vector<std:: vector<int>> &V){
  return true;
}


#endif