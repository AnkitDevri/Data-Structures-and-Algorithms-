using namespace std;
#include<iostream>
#include<conio.h>
class queueNode{
public:
 int data;
 queueNode* next;
  
 queueNode(int queueData){
     this->data=queueData;
     this->next=nullptr;
 }
};
class queue{
public:
 queueNode *front;
 queueNode *rear;
 
 queue(){
     this->front=this->rear=nullptr;
 }

 void insertNode(int data){
    queueNode *node=new queueNode(data);
  if(this->front==NULL)
    this->front=this->rear=node;

  else{
     this->rear->next=node;
     this->rear=node;
  }
  
 }

 void deleteNode(){
   if(this->front==NULL){
       cout<<"Underflow......"<<endl;
   }
   else{
       queueNode *temp=this->front;
       this->front=this->front->next;
       delete temp;
   }
 }
  
 void display(){
      queueNode *temp=this->front;
      if(temp==NULL)
      cout<<"Queue Empty"<<endl;
      while(temp!=NULL){
          cout<<temp->data<<" ";
          temp=temp->next;
      }
     cout<<endl;
 }

};

int main(){
    queue temp;
    int size,element;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>element;
        temp.insertNode(element);
    }
    temp.display();
    temp.deleteNode();
    temp.display();
    getch();
    return 0;
}