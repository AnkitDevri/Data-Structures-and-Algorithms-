#include <bits/stdc++.h>

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
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

void reversePrint(SinglyLinkedListNode* head) {
    
SinglyLinkedList* l1=new SinglyLinkedList();
l1->head=l1->tail=head;
vector<int> sample;

while(l1->tail!=NULL){
    sample.push_back(l1->tail->data);
    l1->tail=(l1->tail)->next;
}

free_singly_linked_list(l1->head);

SinglyLinkedList *l2=new SinglyLinkedList();
int i=sample.size()-1;

while(i>=0){
SinglyLinkedListNode *temp=new SinglyLinkedListNode(sample[i]);
if(l2->head==NULL)
 l2->head=l2->tail=temp;
 
 else{
     (l2->tail)->next=temp;
     l2->tail=temp; 
 }
 i--; 
}

l2->tail=l2->head;

while(l2->tail!=NULL){
    cout<<(l2->tail)->data<<endl;
    l2->tail=(l2->tail)->next;
}

free_singly_linked_list(l2->head);
}
//reverse the list
SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
int i=0;
SinglyLinkedListNode *left,*mid,*right;
left=llist;
mid=llist->next;
while(mid){
if(i==0)
left->next=nullptr;
right=mid->next;
mid->next=left;
left=mid;
mid=right;
i++;  
}
return left;
}

int main()
{
    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist = new SinglyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        reversePrint(llist->head);
    }

    return 0;
}
