using namespace std;
#include<iostream>

struct node{
    int data;
    node* next;
};
node* start=NULL;
node* current=NULL;

void insert(int data){
node* temp=new node();
temp->data=data;

if(start==NULL){
    start=current=temp;
} 
else{
 current->next=temp;
 current=temp;
 } 
}

void display(){
 node* ptr=start;
 while(ptr!=NULL){
     cout<<ptr->data<<" ";
     ptr=ptr->next;
 }
}
int main(){
    int element,size;
    cout<<"Enter the no. of elements you want to enter : ";
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>element;
        insert(element);
    }
    display();
    
    return 0;
}