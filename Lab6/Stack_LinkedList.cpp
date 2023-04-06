#include <iostream>
using namespace std;

//initialising array size as 50
int stack_size;
struct Node {
    int value;
    Node *next;
};
struct Node* head=NULL;
int count=0;

// function to check whether the stack is empty or not
bool Is_Empty(){
    if (head==NULL){
        return true;
    }
    return false;
}

// function to check whether the stack is full or not
bool Is_full(){
    if(count == stack_size){
        return true;
    }
    return false;
}

//function to push elements to the stack
void push(int n) {
   if (Is_full()){
        cout<<"Stack Overflow"<<endl;
   }
   else{
        struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
        newnode->value = n;
        newnode->next = head;
        head = newnode;
        count++;
   }
   
}

//function to pop elements from the stack
void pop() {
  if(Is_Empty())
       cout<<"Stack Underflow"<<endl;
  else {
     cout<<"Popped element is: "<< head->value <<endl;
     head = head->next;
  }
  count--;
}


//function to display all the elements in the stack
void display() {
   struct Node* ptr;
   if(head==NULL){
      cout<<"Stack is empty";
   }
   else {
      ptr = head;
      cout<<"Stack elements are: ";
      int i=1;
      while (i<=count) {
        cout<< ptr->value <<" ";
        ptr = ptr->next;
        i++;
    }
   }
   cout<<endl;
}
//function to get the top element
void StackTop(){
    if(Is_Empty()){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        cout<<head->value<<endl;
    }
}
int main(){
    cout<<"Enter the stack size: ";
    cin>>stack_size;
    cout<<endl;
    push(8);
    push(10);
    push(5);
    pop();
    pop();
    pop();
    pop();
    pop();
    display();
    push(11);
    push(15);
    push(23);
    push(6);
    push(18);
    push(101);
    push(55);
    push(93);
    push(20);
    push(17);
    display();
    pop();
    pop();
    pop();
    pop();
    pop();
    display();
    push(4);
    push(30);
    push(3);
    push(1);
    display();

}