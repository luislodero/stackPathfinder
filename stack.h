#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>
#include <string>

class stack{
 
  //const stack& operator = (const stack&);
  
  private:
  struct node{
    int x,y;
    node* next;
  };
  
  node *top;
  int size;
  
  
   public:

  stack();
  void push(int y, int x);
  std:: string pop();
  std:: string peek();
  bool isEmpty();
  int length();
  void delAll();
  void copyList(node *p);
  ~stack();
  stack(const stack&);
  
};

void stack:: delAll(){
  node *t = top;
  node *c;
    while(t){
      c = t->next;
      delete t;
      t = c;
    }
  
}

void stack:: copyList(node *p){
  if(p!=nullptr){
    
    top = new node{p->y, p->x, nullptr};
    node* curr = p->next;
    node* temp = top;

    while (curr) {
        temp->next = new node{curr->y, curr->x, nullptr};
        temp = temp->next;
        curr = curr->next;
        
    }
    
  }

}

stack:: ~stack(){
  
  delAll();
 
  top = nullptr;
  std:: cout << "-----------------DELETE-------------------" << std:: endl;

}


stack:: stack(const stack& os5){
    
   
  if(os5.top != nullptr){
  copyList(os5.top);
  }
    
  std:: cout << "-----------------COPY---------------------" << std:: endl;
}


// const ordered_set& ordered_set:: operator = (const ordered_set & os5){
  
//   std:: cout << "-----------------ASSIGNMENT---------------" << std:: endl;

//   if(this->head != os5.head){
   
//     delAll();
//     head = nullptr; 
//     node *c = os5.head;
    
//     if(c){
//       copyList(c);
//     }
//   }
  
//   return *this;
    
// }


stack:: stack(){
  top = nullptr;
  size = 0;
}


void stack:: push(int y, int x){
  top = new node{y,x,top};
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
    s += std:: to_string(top->x);
    s += std:: to_string(top->y);
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