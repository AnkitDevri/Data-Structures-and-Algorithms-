using namespace std;
#include<iostream>
#include<conio.h>

class stackNode{
 public:
 int data;
 stackNode *next;
  
 stackNode(int stackdata){
     this->data=stackdata;
     this->next=nullptr;
   }
   
};

class stack{
     stackNode* top;
  public:
     stack(){
       this->top=nullptr;
     }

     void push(int data){
       stackNode* node = new stackNode(data);
        if(this->top==NULL)
         this->top=node;

         else{
            node->next=top;
            this->top=node;
         }
     }

     void pop(){
         stackNode* temp=this->top;
         this->top=this->top->next;
         delete temp;
     }

     void display(){
         stackNode* temp=this->top;
         if(temp==NULL)
         cout<<"Stack Empty";
         
         while(temp!=NULL){
             cout<<temp->data<<" ";
             temp=temp->next;
         }
         cout<<endl;
     }
};

int main(){
    stack AD;
    int size,element;
    cin>>size;
    for(int i=0;i<size;i++){
    cin>>element;
    AD.push(element);
    }
    AD.display();
    AD.pop();
    AD.display();
    
    getch();
    return 0;
}