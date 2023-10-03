#include<iostream>
#include<stack>
using namespace std;

class Stack {
    public:
        int *arr;
        int top; 
        int size;
    Stack(int s){
        this->size = s;
        arr = new int[s];
        top = -1; 
    }
    void push(int element){
        if(size-top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack is overflow"<<endl;
        }

    }
    void pop(){
        if(top>=0){
            top--;
        }else{
            cout<<"stack is Underflow"<<endl;
        }

    }
    void peek(){
        if(top>=0){
            cout<<arr[top]<<endl;
        }else{
            cout<<"Stack is Empty"<<endl;
        }

    }
    bool isEmpty(){
        if(top>=0){
            return false;
        }else{
           return true;
        }

    }


};
int main()
{
    Stack st(5);
    st.push(5);
    st.push(10);
    st.push(15);
    st.push(20);
    st.peek();


    st.pop();
    st.peek();

    st.pop();
    st.peek();

    st.pop();
    st.peek();

    // st.pop();
    // st.peek();   //stack is empty
    cout<<st.isEmpty()<<endl;
    
    return 0;
}