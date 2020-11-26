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
  
//   ~ordered_set();

// ordered_set(const ordered_set&);

// const ordered_set& operator = (const ordered_set&);
  
  private:
  struct node{
    int x,y;
    node* next;
  };
  node *top;
  int size;
};

// void ordered_set:: delAll(){
//   node *t = head;
//   node *c;
//     while(t){
//       c = t->next;
//       delete t;
//       t = c;
//     }
  
// }

// void ordered_set:: copyList(node *p){
//   if(p!=nullptr){
    
//     head = new node{p->data, nullptr};
// node* curr = p->next;
//     node* temp = head;

//     while (curr) {
//         temp->next = new node{curr->data, nullptr};
//         temp = temp->next;
//         curr = curr->next;
        
//     }
    
//   }

// }

// ordered_set:: ~ordered_set(){
  
//   delAll();
 
//   head = nullptr;
//   curr = nullptr;
//   std:: cout << "-----------------DELETE-------------------" << std:: endl;

// }


// ordered_set:: ordered_set(const ordered_set& os5){
    
   
//     if(os5.head != nullptr){
//     copyList(os5.head);
      
//     }
    
//     std:: cout << "-----------------COPY---------------------" << std:: endl;
// }


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