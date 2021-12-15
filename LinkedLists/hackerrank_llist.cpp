#include<iostream>
#include<conio.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;

        SinglyLinkedList() {
            this->head = nullptr;
        }

};

void print_singly_linked_list(SinglyLinkedListNode* node) {
    while (node!=NULL) {
        cout<< node->data;
        node = node->next;
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode *temp;

SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {

   SinglyLinkedListNode *target = new SinglyLinkedListNode(data);
    SinglyLinkedListNode *temp=head;
    if(head==NULL){
       temp=head=target;
    }
    else{
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=target;
      
    }
    return head;

}

int main(){
    int data,size,i=0;
    SinglyLinkedList* llist = new SinglyLinkedList();
    cin>>size;
    while(i<size){
        cin>>data;
        SinglyLinkedListNode* llist_head = insertNodeAtTail(llist->head, data);
        llist->head = llist_head;
        i++;
    }
    print_singly_linked_list(llist->head);
    free_singly_linked_list(llist->head);
    getch();
    return 0;
}