#include<iostream>
#include<conio.h>

using namespace std;

struct node{
int data;
node* next;
};
node* start=NULL;
node* current=NULL;

void deleteNode(int data)
{
  node* temp =start;
  node* prev =temp;
  while(temp!=NULL){
  if(temp->data!=data)
  {
   prev=temp;
   temp=temp->next;
   } 
  else{
       prev->next=temp->next;
       delete temp;
       break;
       }
   } 
}
void insertNode(int data){
    node* temp=new node();
     temp->data=data;

    if(start==NULL)
    start=current=temp;

    else{
      current->next=temp;
      current=temp;
    }
}

void displayList(){
    node* temp=start;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main(){
  int size,element;
  cin>>size;
  for(int i=0; i< size;i++){
   cin>>element;
   insertNode(element);
  }
  displayList();
 /* cout<<endl<<"Element to delete from the list : ";
  cin>>element;
  deleteNode(element);
  displayList();
  
 getch();*/
 return 0;
}