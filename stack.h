#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>
#include <string>

/**
 * Student: Luis Hector Lopez de la Rosa
 * Student #: 100319615
 * Date: November 26, 2020
 * Description: This class creates a stack of coordinates from a 2d vector.
 **/

class stack{
 
  
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
  const stack& operator = (const stack&);

  
};

//Input: none
//Output: none
//This function deletes the linked list and its contents.
void stack:: delAll(){
  node *t = top;
  node *c;
    while(t){
      c = t->next;
      delete t;
      t = c;
    }
  
}

//Input: node pointer p.
//Output: none
//This function copies a linked list based on the node given in the parameter.
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

// Destructor
// Deletes the current linked list and its contents.
stack:: ~stack(){
  
  delAll();
 
  top = nullptr;

}


// Copy constructor
// Copies the contents of the linked list given in the parameters.
stack:: stack(const stack& os5){
    
   
  if(os5.top != nullptr){
  copyList(os5.top);
  }
    
}

//Assignment operator overload
//This will delete the contents of the current linked list and copy the contents of the given ordered set onto the current ordered set.
const stack& stack:: operator = (const stack & os5){
  

  if(this->top != os5.top){
   
    delAll();
    top = nullptr; 
    node *c = os5.top;
    
    if(c){
      copyList(c);
    }
  }
  
  return *this;
    
}

//Class constructor: top pointer will be set to nullptr and size to 0.
stack:: stack(){
  top = nullptr;
  size = 0;
}

//Input: int y int x representing coordinates of a 2d vector
//Output: none
//Push function inserts a new set of coordinates to the beginning of the linked list.
void stack:: push(int y, int x){
  top = new node{y,x,top};
  size++;
}

//Input: none
//Output: int representing size of linked list.
int stack :: length(){
  return size;
}

//Input: none
//Output: string containing coordinates of a 2d vector
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


//Input: none
//Output: string containing first element's coordinates
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

// Input: none
//Output: boolean representing if linked list is empty.
bool stack :: isEmpty(){
  if(top == nullptr){
    return true;
  }
  return false;
}





#endif