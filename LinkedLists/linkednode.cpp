#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

int main(){
    node* temp = new node();
    cin>>temp->data;
    cout<<"TEMP: "<<temp->data;
    node* temp1 = new node();
    temp->next=temp1;
    cin>>temp1->data;
    cout<<"TEMP1: "<<temp1->data;
    temp1->next=NULL;

    while(temp->next!=NULL){
        cout<<temp->data;
        temp=temp->next;
        cout<<temp->data;
    }
    return 0;
}