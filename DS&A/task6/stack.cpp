#include <iostream>


class node{
    public:
    int data;
    node* prev;



    node(int value){
        
        data = value;
        prev = nullptr;

    }
};

class stack{
    public:
    node* top;
    stack(){
        
        top = nullptr;
    }


    bool empty(){
        return top == nullptr;
    }
    void push(int data){
        node* newNode = new node(data);
        newNode->prev = top;
        top = newNode;
    }

    int pop(){
        if (empty())
        {
            return -1;
        }
        
        int temp = top->data;
        node* popped = top;
        top = top->prev;
        delete popped;
        return temp;

    }

    int display(){
        if (empty())
        {
            return -1;
        }
        node* traverse = top;
        
        do
        {
            printf("%d ", traverse->data);
            traverse = traverse->prev;
        } while (!(traverse == nullptr));
        std::cout<<std::endl;
        return 1;
        
    }

    int peek(){
        return top->data;
    }
    ~stack(){
        while (!(top == nullptr))
        {
            node* temp = top;
            top = top->prev;
            delete temp;
        }
        
    }

};

int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();
    s.pop();
    s.pop();
    s.display();

}


















// typedef struct Node {
//     int data;
//     struct Node* next;
// } Node;

// typedef struct {
//     Node* top;    
// } Stack;


// void initStack(Stack* s) {
//     s->top = NULL;
// }
