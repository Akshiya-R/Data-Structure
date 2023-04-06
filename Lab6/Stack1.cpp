#include <iostream>
#include <chrono>
using namespace std;

//initialising array size as 50
int stack_size=5;
int stack_arr[5];

int top_index=-1;

// function to check whether the stack is full or not
bool is_full(){
    if(stack_size-1==top_index){
        return true;
    }
    return false;
}

//function to push elements to the stack
void push(int n){
    top_index++;
    if(is_full()){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        stack_arr[top_index]=n;
    }
}

// function to check whether the stack is empty or not
bool is_Empty(){
    if(top_index>=0){
        return false;
    }
    return true;
}

//function to pop elements from the stack
void pop(){
    if(is_Empty()){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        cout<<"Poped element is: "<<stack_arr[top_index]<<endl;
        top_index--;
    }
}

//function to get the top element
void StackTop(){
    if(is_Empty()){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        cout<<stack_arr[top_index]<<endl;
    }
}

//function to display all the elements in the stack
void display(){
    if(is_Empty()){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        for(int i=0;i<=top_index;i++){
            cout<<stack_arr[i]<<" ";
        }
        cout<<endl;
    }

}
int main(){
        //Calculating the time taken to istack implementation using array
        auto startTimeForIterative = chrono::high_resolution_clock::now();
        push(8);
        push(10);
        push(5);
        push(11);
        push(15);
        push(23);
        push(6);
        push(18);
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
        auto endTimeForIterative = chrono::high_resolution_clock::now();
        auto duration= chrono::duration_cast<chrono::microseconds>(endTimeForIterative - startTimeForIterative).count();
        
        cout << "Time taken for stack implementation using Array: " << duration<< endl;

}