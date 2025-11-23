// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    int priority;
    Node* next;
    
    Node(int data,int p){
        val = data;
        priority = p;
        next = NULL;
    }
};
class priorityQueue{
    public:
    Node* head;
    Node* tail;
    
    priorityQueue(){
        head = tail = NULL;
    }
    
    void insert(int val,int pri){
        Node* newnode = new Node(val,pri);
        if(head == NULL || pri > head->priority){
            newnode->next = head;
            head = newnode;
        }
        Node* temp = head;
        while(temp->next && temp->next->priority >= pri){
            temp = temp->next;
        }
        temp->next= newnode;
        newnode->next = temp->next;
    }
    
    void remove(){
        if(head == NULL){
            cout<<"queue is empty"<<endl;
            return;
        }
        Node* temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    
    int peek(){
        if(head == NULL){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return head->val;
        
    }
    
    void print(){
        if(head == NULL){
            cout<<"queue is empty"<<endl;
            return;
        }
        Node* temp = head;
        
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    
};

int main() {
    priorityQueue q;
    q.insert(8,4);
    q.insert(7,2);
    q.insert(9,3);
    q.insert(10,1);
    q.print();
    q.remove();
    q.print();
    
}
