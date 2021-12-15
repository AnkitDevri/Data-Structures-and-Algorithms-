using namespace std;
#include<iostream>
#include<conio.h>

class llistnode{
public:
int data;
llistnode* prev;
llistnode* next;

llistnode(int nodeData){
  this->data=nodeData;
  this->next=nullptr;
  this->prev=nullptr;
}
};

class llist{
    public:
    llistnode* head;
    llistnode* tail;
   llist(){
   this->head=nullptr;
   this->tail=nullptr;
 }
   void insert(int nodeData){
    llistnode* temp= new llistnode(nodeData);
    if(this->head==nullptr){
      head=tail=temp;
    }
    else{
      this->tail->next=temp;
      temp->prev=this->tail;
      this->tail=temp;
    }
   }
   void erase(int position){
    llistnode* temp=this->head;
    int i=0;
    while(i!=position-2){
      temp=temp->next;
      i++;
    }
    llistnode *temp2=temp->next;
    temp->next->next->prev=temp;
    temp->next=temp->next->next;
    delete temp2;
   }

   void display(){
     llistnode* temp=this->head;
     while(temp){
       cout<<temp->data<<" ";
       temp=temp->next;
     }
     cout<<endl;
   }

   void revdisplay(){
     llistnode *temp=this->tail;
     while(temp){
       cout<<temp->data<<" ";
       temp=temp->prev;
     }
     cout<<endl;
   }
};

int main(){
  llist yo;
  int size,element;
  cin>>size;
  for(int i=0;i<size;i++){
  cin>>element;
  yo.insert(element);
  }
  yo.display();
  yo.revdisplay();
  cout<<"Element no. to erase : ";
  cin>>element;
  yo.erase(element);
  yo.display();
  yo.revdisplay();
  getch();
  return 0;
}