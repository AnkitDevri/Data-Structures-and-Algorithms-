using namespace std;
#include <bits/stdc++.h>
 struct Node {
     int val;
     Node *next;
     Node *random;
     Node() : val(0), next(nullptr), random(nullptr) {}
     Node(int x) : val(x), next(nullptr), random(nullptr) {}
     Node(int x, Node *next) : val(x), next(next), random(nullptr) {}
     Node(int x, Node *next, Node *random) : val(x), next(next), random(random) {}
  };

  class linkedList {
        Node* head;
        int length;
        public:
        linkedList( int val){
            this-> head = new Node(val);
            this-> length = 1;
        } 
        void insertAtEnd( int val ){
            Node *temp = this-> head;
            while ( temp->next ){
                temp = temp->next;
            }
            Node *tmp = new Node(val);
            temp-> next = tmp;

            this->length++;
        }

        void insertAtPostion( int pos, int val){
            Node *temp = this-> head;
            int i = 1;
            while(i < pos - 1) {
                temp = temp -> next;
                i++;
            }
            Node *tmp = new Node(val);
            tmp->next = temp->next;
            temp->next = tmp;

            this->length++;
        }
        void primitiveRemoveFromEnd ( int pos ){
            Node *temp = this->head;   
            int i = 1;
            Node *tmp = head;
            int Size = 0;
            while (tmp){
                tmp = tmp ->next;
                Size++;
            }
            
            if ( pos == Size){
                Node *toDelete = temp;
                this->head = temp->next;
                delete toDelete;
            }
            else{
                while ( i < Size - pos ){
                    temp = temp -> next;
                    i++;
                }
                Node *toDelete = temp->next;
                temp -> next = toDelete->next;

                delete toDelete;
                }
             

        }
        
        void removeFromEnd ( int pos ){
            Node *temp = this->head;
            int i = 1;
            if ( pos == this->length){
                Node *toDelete = temp;
                this->head = temp->next;
                delete toDelete;
            }
            else{
                while ( i < this->length - pos ){
                    temp = temp -> next;
                    i++;
                }
                Node *toDelete = temp->next;
                temp -> next = toDelete->next;

                delete toDelete;
                }
             this->length--;
        }
        void displayList (){
            Node *temp = this->head;
            while (temp){
                cout<< temp->val<<" ";
                temp = temp->next;
            }
        }

        int size () {
            return this->length;
        }

        Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        
        unordered_map <Node*,int> originalMap;
        unordered_map <int,Node*> clonedMap;
        // mapping original List
        Node* temp = head;
        int count = 1;
        while (temp)
        {
            originalMap.insert({temp,count});
            temp = temp->next;
            count++;
        }
        // creating and mapping new list for next 
        count = 1;
        temp = head;
        Node* newHead = new Node(head->val);
        Node* prev = newHead;
        temp = temp->next;
        clonedMap.insert({count,prev});

        while(temp){
            prev->next = new Node(temp->val);
            prev = prev->next;
            count++;
            clonedMap.insert({count,prev});
            temp = temp->next;
        }

        //mapping for randoms in new list
        temp = head;
        Node* newTemp = newHead;
        prev = temp->random;
        while(temp){
           int pos = originalMap[prev];
           Node *linker = clonedMap[pos];
           newTemp->random = linker;
           newTemp = newTemp->next;
           temp = temp->next;
           if(temp)prev = temp->random;
        }
        
       return newHead;
    }
  };
  
int main () {
    linkedList l1(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    l1.insertAtEnd(4);
    l1.removeFromEnd(3);
    l1.displayList();
    return 0;
}