#include <iostream>

class node{
    public:
    node* prev;
    node* next;
        int data;
        node(int val) : prev(nullptr), data(val), next(nullptr){}
};

class DLL{
    public:
    node* head;
    node* tail;
    int size;
        DLL() : head(nullptr), tail(nullptr), size(0){}
        bool empty(){
            return (head == nullptr && tail == nullptr);
        }
        void insertAtBeginning(int data){
            node* newNode = new node(data);
            if (empty())
            {
                head = newNode;
                tail = newNode;
            }
            else{
                newNode->next = head;
                head = newNode;
                head->prev = newNode;
            }
            
            
            size++;
        }
        void insertAtEnd(int data){
            node* newNode = new node(data);
            if (empty())
            {
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            size++;
        }
        void insertAtPos(int data, int pos){
            node* newNode = new node(data);
            int i;
            if (pos > size)
            {
                std::cout<<"mynf3sh"<<std::endl;
                
            }
            else{

                node* temp = head;
                while (i <pos)
                {
                    temp = temp->next;
                    i++;
                }
                newNode->prev = temp->prev;
                temp->prev = newNode;
                newNode->next = temp;
                newNode->prev->next = newNode;
                
                size++;
            }
            
            
        }
        int count(){
            return size;
        }

        int sum(){
            int sum = 0;
            node* temp = head;
            while (temp != nullptr)
            {
                sum+= temp->data;
                temp = temp->next;
            }
            return sum;
            
        }
        void display(){
            
            node* temp = head;
            while (temp != nullptr)
            {
                std::cout<<temp->data<<" "<<std::endl;
                temp = temp->next;
            }
            
        }
};

